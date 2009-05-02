--- server/gam_kqueue.c.orig	2007-07-04 09:50:41.000000000 -0400
+++ server/gam_kqueue.c	2009-05-01 20:52:14.000000000 -0400
@@ -10,9 +10,10 @@
  *       FAM should do: we do not call g_dir_open() if the file is a
  *       symbolic link).
  *
- *     * kqueue cannot monitor files residing on anything but a UFS
- *       file system. If kqueue cannot monitor a file, this backend
- *       will poll it periodically.
+ *     * While kqueue is no longer tied to the UFS file system, it is
+ *       better to not use it for remote file systems (because for
+ *       such file systems, only local changes are detected by
+ *       the kernel).
  *
  *     * Monitoring a file with kqueue prevents the file system it
  *       resides on from being unmounted, because kqueue can only
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
 
@@ -326,7 +330,7 @@ gam_kqueue_isdir (const char *pathname, 
 static gboolean
 gam_kqueue_get_uint_sysctl (const char *name, unsigned int *value)
 {
-  unsigned int value_len = sizeof(*value);
+  size_t value_len = sizeof(*value);
 
   if (sysctlbyname(name, value, &value_len, (void *)NULL, 0) < 0)
     {
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
+
+  if (gam_exclude_check(mon->pathname))
+    {
+      GAM_DEBUG(DEBUG_INFO, "not using kqueue for %s since it is excluded, falling back to poll\n", mon->pathname);
+      return FALSE;
+    }
   
-  mon->fd = open(mon->pathname, O_RDONLY | O_NOFOLLOW);
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
@@ -840,6 +863,8 @@ gam_kqueue_sub_monitor_emit_event (SubMo
     case GAMIN_EVENT_MOVED:
       gam_kqueue_sub_monitor_set_missing(smon);
       break;
+    default:
+      break;
     }
 
   gam_server_emit_event(mon->pathname, isdir, event, smon->subs, 1);
@@ -981,6 +1006,8 @@ gam_kqueue_file_monitor_emit_event (File
 	
       gam_kqueue_hash_table_remove(fmon->smon->fmons, fmon);
       break;
+    default:
+      break;
     }
 }
 
@@ -1167,6 +1194,9 @@ gam_kqueue_init (void)
   channel = g_io_channel_unix_new(kq);
   g_io_add_watch(channel, G_IO_IN, gam_kqueue_kevent_cb, NULL);
 
+#ifdef USE_GAMIN_POLLER
+  gam_poll_basic_init ();
+#endif
   
   gam_server_install_kernel_hooks(GAMIN_K_KQUEUE,
   				  gam_kqueue_add_subscription,
