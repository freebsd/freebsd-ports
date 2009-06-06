--- server/gam_kqueue.c.orig	2007-07-04 09:50:41.000000000 -0400
+++ server/gam_kqueue.c	2009-06-03 13:43:38.000000000 -0400
@@ -5,7 +5,8 @@
  *
  *     * http://techpubs.sgi.com/library/tpl/cgi-bin/getdoc.cgi?coll=0650&db=bks&fname=/SGI_Developer/books/IIDsktp_IG/sgi_html/ch08.html
  *       states that FAM does not follow monitored symbolic links: we
- *       do the same (note that regarding
+ *       do NOT do the same to preserve compatibility with SGI FAM (note
+ *       that regarding
  *       http://oss.sgi.com/bugzilla/show_bug.cgi?id=405, we do what
  *       FAM should do: we do not call g_dir_open() if the file is a
  *       symbolic link).
@@ -28,10 +29,9 @@
  *           - kqueue needs to be augmented with a filename-based
  *             monitoring facility;
  *
- *           - kqueue needs to be moved out the UFS code.
- *
  * Copyright (C) 2005 Joe Marcus Clarke <marcus@FreeBSD.org>
- * Copyright (C) 2005 Jean-Yves Lefort <jylefort@FreeBSD.org>
+ * Copyright (C) 2005, 2006 Jean-Yves Lefort <jylefort@FreeBSD.org>
+ * Copyright (C) 2006 Alex Dupre <ale@FreeBSD.org>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of the GNU Lesser General Public
@@ -53,6 +53,9 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <sys/param.h>
+#ifndef USE_GAMIN_POLLER
+#include <sys/mount.h>
+#endif
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #include <sys/stat.h>
@@ -62,6 +65,7 @@
 #include "gam_error.h"
 #include "gam_kqueue.h"
 #include "gam_event.h"
+#include "gam_excludes.h"
 #include "gam_server.h"
 #include "gam_poll_basic.h"
 
@@ -130,7 +134,7 @@ typedef struct
   HashTableRemoveFunc		remove;
   HashTablePostRemoveFunc	post_remove;
 } HashTableMethods;
-  
+
 /*
  * A hash table which can be modified while iterating over it.
  */
@@ -281,8 +285,8 @@ static void
 gam_kqueue_mini_lstat (const char *pathname, MiniStat *mini_sb)
 {
   struct stat sb;
-  
-  if (lstat(pathname, &sb) < 0)
+
+  if (stat(pathname, &sb) < 0)
     memset(mini_sb, 0, sizeof(*mini_sb));
   else
     {
@@ -319,14 +323,14 @@ gam_kqueue_isdir (const char *pathname, 
   else
     {
       struct stat sb;
-      return lstat(pathname, &sb) >= 0 && (sb.st_mode & S_IFDIR) != 0;
+      return stat(pathname, &sb) >= 0 && (sb.st_mode & S_IFDIR) != 0;
     }
 }
 
 static gboolean
 gam_kqueue_get_uint_sysctl (const char *name, unsigned int *value)
 {
-  unsigned int value_len = sizeof(*value);
+  size_t value_len = sizeof(*value);
 
   if (sysctlbyname(name, value, &value_len, (void *)NULL, 0) < 0)
     {
@@ -406,7 +410,7 @@ gam_kqueue_hash_table_foreach (HashTable
   table->iterating = TRUE;
   g_hash_table_foreach(table->main, func, user_data);
   table->iterating = FALSE;
-  
+
   if (table->pending_additions)
     {
       GSList *l;
@@ -509,33 +513,52 @@ static gboolean
 gam_kqueue_monitor_enable_kqueue (Monitor *mon)
 {
   struct kevent ev[1];
+#ifndef USE_GAMIN_POLLER
+  struct statfs sb;
+#endif
 
   if (open_files == max_open_files)
     {
       GAM_DEBUG(DEBUG_INFO, "cannot open %s (max_open_files limit reached), falling back to poll\n", mon->pathname);
       return FALSE;
     }
-  
-  mon->fd = open(mon->pathname, O_RDONLY | O_NOFOLLOW);
+
+  if (gam_exclude_check(mon->pathname))
+    {
+      GAM_DEBUG(DEBUG_INFO, "not using kqueue for %s since it is excluded, falling back to poll\n", mon->pathname);
+      return FALSE;
+    }
+
+  mon->fd = open(mon->pathname, O_RDONLY | O_NONBLOCK | O_NOFOLLOW);
   if (mon->fd < 0)
     {
       GAM_DEBUG(DEBUG_INFO, "cannot open %s (%s), falling back to poll\n", mon->pathname, g_strerror(errno));
       return FALSE;
     }
 
+#ifndef USE_GAMIN_POLLER
+  if (fstatfs(mon->fd, &sb) == 0 && (sb.f_flags & MNT_LOCAL) == 0)
+    {
+      GAM_DEBUG(DEBUG_INFO, "%s resides on a remote file system, falling back to poll\n", mon->pathname);
+      goto poll;
+    }
+#endif
+
   EV_SET(ev, mon->fd, EVFILT_VNODE, EV_ADD | EV_ENABLE | EV_CLEAR, VN_NOTE_ALL, 0, mon);
   if (kevent(kq, ev, G_N_ELEMENTS(ev), NULL, 0, NULL) < 0)
     {
       GAM_DEBUG(DEBUG_INFO, "cannot enable kqueue notification for %s (%s), falling back to poll\n", mon->pathname, g_strerror(errno));
-
-      close(mon->fd);
-      mon->fd = -1;
-
-      return FALSE;
+      goto poll;
     }
 
   open_files++;
   return TRUE;
+
+ poll:
+  close(mon->fd);
+  mon->fd = -1;
+
+  return FALSE;
 }
 
 static void
@@ -612,7 +635,7 @@ gam_kqueue_sub_monitor_free (SubMonitor 
   gam_kqueue_poller_remove_sub_monitor(&missing_smon_poller, smon);
   gam_kqueue_poller_remove_sub_monitor(&unsupported_smon_poller, smon);
   /* unsupported_dirs_poller is handled by _clear_fmons() below */
-  
+
   gam_kqueue_sub_monitor_clear_fmons(smon);
   gam_kqueue_monitor_free(MONITOR(smon));
 }
@@ -700,7 +723,7 @@ gam_kqueue_sub_monitor_enable_notificati
     {
       struct stat sb;
 
-      exists = lstat(mon->pathname, &sb) >= 0;
+      exists = stat(mon->pathname, &sb) >= 0;
       flags |= (exists && (sb.st_mode & S_IFDIR) != 0) ? MONITOR_ISDIR : MONITOR_ISNOTDIR;
     }
 
@@ -715,21 +738,21 @@ gam_kqueue_sub_monitor_enable_notificati
 	{
 	  GDir *dir;
 	  GError *err = NULL;
-	  
+
 	  dir = g_dir_open(mon->pathname, 0, &err);
 	  if (dir)
 	    {
 	      const char *filename;
-	      
+
 	      while ((filename = g_dir_read_name(dir)))
 		{
 		  FileMonitor *fmon;
 		  FileMonitorFlags fmon_flags;
-		  
+
 		  fmon = gam_kqueue_file_monitor_new(smon, filename, &fmon_flags);
 		  gam_kqueue_file_monitor_emit_event(fmon, gevent, fmon_flags);
 		}
-	      
+
 	      g_dir_close(dir);
 	    }
 	  else
@@ -749,7 +772,7 @@ gam_kqueue_sub_monitor_enable_notificati
 
       return;
     }
-    
+
   /* then we enable kqueue notification, falling back to poll if necessary */
 
   if (! gam_kqueue_monitor_enable_kqueue(mon))
@@ -774,7 +797,7 @@ gam_kqueue_sub_monitor_handle_directory_
 
   filenames = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, NULL);
 
-  if (isdir)			/* do not follow symbolic links */
+  if (isdir)
     {
       GDir *dir;
       GError *err = NULL;
@@ -783,7 +806,7 @@ gam_kqueue_sub_monitor_handle_directory_
       if (dir)
 	{
 	  const char *filename;
-	  
+
 	  while ((filename = g_dir_read_name(dir)))
 	    {
 	      g_hash_table_insert(filenames, g_strdup(filename), GINT_TO_POINTER(TRUE));
@@ -793,12 +816,12 @@ gam_kqueue_sub_monitor_handle_directory_
 		{
 		  FileMonitor *fmon;
 		  FileMonitorFlags fmon_flags;
-		  
+
 		  fmon = gam_kqueue_file_monitor_new(smon, filename, &fmon_flags);
 		  gam_kqueue_file_monitor_emit_event(fmon, GAMIN_EVENT_CREATED, fmon_flags);
 		}
 	    }
-	  
+
 	  g_dir_close(dir);
 	}
       else
@@ -840,6 +863,8 @@ gam_kqueue_sub_monitor_emit_event (SubMo
     case GAMIN_EVENT_MOVED:
       gam_kqueue_sub_monitor_set_missing(smon);
       break;
+    default:
+      break;
     }
 
   gam_server_emit_event(mon->pathname, isdir, event, smon->subs, 1);
@@ -931,11 +956,11 @@ gam_kqueue_file_monitor_emit_event (File
   gboolean isdir;
   gboolean stat_done;
   gboolean stat_succeeded;
-  
+
   if ((flags & MONITOR_ISDIR) == 0 && (flags & MONITOR_ISNOTDIR) == 0)
     {
       stat_done = TRUE;
-      stat_succeeded = lstat(mon->pathname, &sb) >= 0;
+      stat_succeeded = stat(mon->pathname, &sb) >= 0;
       isdir = stat_succeeded && (sb.st_mode & S_IFDIR) != 0;
     }
   else
@@ -943,7 +968,7 @@ gam_kqueue_file_monitor_emit_event (File
       stat_done = FALSE;
       isdir = (flags & MONITOR_ISDIR) != 0;
     }
-  
+
   gam_server_emit_event(mon->pathname, isdir, event, fmon->smon->subs, 1);
 
   switch (event)
@@ -962,7 +987,7 @@ gam_kqueue_file_monitor_emit_event (File
 	    {
 	      FileMonitor *new_fmon;
 	      FileMonitorFlags new_fmon_flags;
-	      
+
 	      /*
 	       * The file exists again. It means that kqueue has
 	       * aggregated a removal+creation into a single event. We
@@ -978,9 +1003,11 @@ gam_kqueue_file_monitor_emit_event (File
 	      break;		/* do not remove the fmon we've just created */
 	    }
 	}
-	
+
       gam_kqueue_hash_table_remove(fmon->smon->fmons, fmon);
       break;
+    default:
+      break;
     }
 }
 
@@ -1033,7 +1060,7 @@ gam_kqueue_kevent_cb (GIOChannel *source
 
   for (i = 0; i < nevents; i++)
     MONITOR(ev[i].udata)->handle_kevent(MONITOR(ev[i].udata), &ev[i]);
-  
+
   return TRUE;			/* keep source */
 }
 
@@ -1042,7 +1069,7 @@ gam_kqueue_missing_smon_poll (SubMonitor
 {
   struct stat sb;
 
-  if (lstat(MONITOR(smon)->pathname, &sb) >= 0)
+  if (stat(MONITOR(smon)->pathname, &sb) >= 0)
     {
       gam_kqueue_poller_remove_sub_monitor(&missing_smon_poller, smon);
       gam_kqueue_sub_monitor_enable_notification(smon, SUB_MONITOR_WAS_MISSING | ((sb.st_mode & S_IFDIR) != 0 ? MONITOR_ISDIR : MONITOR_ISNOTDIR));
@@ -1062,16 +1089,16 @@ gam_kqueue_unsupported_smon_poll (SubMon
       if (gam_kqueue_monitor_enable_kqueue(mon))
 	gam_kqueue_poller_remove_sub_monitor(&missing_smon_poller, smon);
     }
-  
+
   gam_kqueue_mini_lstat(mon->pathname, &sb);
-  
+
   if (! sb.exists && mon->sb.exists)
     event = GAMIN_EVENT_DELETED;
   else if (gam_kqueue_differs(&sb, &mon->sb))
     event = GAMIN_EVENT_CHANGED;
   else
     return;
-	
+
   memcpy(&mon->sb, &sb, sizeof(sb));
   gam_kqueue_sub_monitor_emit_event(smon, event, (sb.mode & S_IFDIR) != 0 ? MONITOR_ISDIR : MONITOR_ISNOTDIR);
 }
@@ -1167,7 +1194,10 @@ gam_kqueue_init (void)
   channel = g_io_channel_unix_new(kq);
   g_io_add_watch(channel, G_IO_IN, gam_kqueue_kevent_cb, NULL);
 
-  
+#ifdef USE_GAMIN_POLLER
+  gam_poll_basic_init ();
+#endif
+
   gam_server_install_kernel_hooks(GAMIN_K_KQUEUE,
   				  gam_kqueue_add_subscription,
 				  gam_kqueue_remove_subscription,
@@ -1200,7 +1230,7 @@ gam_kqueue_add_subscription (GamSubscrip
       smon->subs = g_list_append(smon->subs, sub);
       return TRUE;
     }
-  
+
   smon = gam_kqueue_sub_monitor_new(sub);
   smon->subs = g_list_append(smon->subs, sub);
 
@@ -1260,6 +1290,6 @@ gam_kqueue_remove_all_for (GamListener *
       success = FALSE;
 
   g_list_free(subs);
-  
+
   return success;
 }
