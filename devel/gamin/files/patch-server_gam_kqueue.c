--- server/gam_kqueue.c.orig	Sat Apr 30 12:26:31 2005
+++ server/gam_kqueue.c	Sun May  1 08:18:47 2005
@@ -0,0 +1,1262 @@
+/*
+ * gam_kqueue.c - a kqueue(2) Gamin backend
+ *
+ * Notes:
+ *
+ *     * http://techpubs.sgi.com/library/tpl/cgi-bin/getdoc.cgi?coll=0650&db=bks&fname=/SGI_Developer/books/IIDsktp_IG/sgi_html/ch08.html
+ *       states that FAM does not follow monitored symbolic links: we
+ *       do the same (note that regarding
+ *       http://oss.sgi.com/bugzilla/show_bug.cgi?id=405, we do what
+ *       FAM should do: we do not call g_dir_open() if the file is a
+ *       symbolic link).
+ *
+ *     * kqueue cannot monitor files residing on anything but a UFS
+ *       file system. If kqueue cannot monitor a file, this backend
+ *       will poll it periodically.
+ *
+ *     * Monitoring a file with kqueue prevents the file system it
+ *       resides on from being unmounted, because kqueue can only
+ *       monitor open files.
+ *
+ *     * The creation of missing monitored files is detected by
+ *       performing a lstat() every second. Although using kqueue to
+ *       monitor the parent directory is technically feasible, it
+ *       would introduce a lot of complexity in the code.
+ *
+ *     * In light of the previous points, it appears that:
+ *
+ *           - kqueue needs to be augmented with a filename-based
+ *             monitoring facility;
+ *
+ *           - kqueue needs to be moved out the UFS code.
+ *
+ * Copyright (C) 2005 Joe Marcus Clarke <marcus@FreeBSD.org>
+ * Copyright (C) 2005 Jean-Yves Lefort <jylefort@FreeBSD.org>
+ *
+ * This library is free software; you can redistribute it and/or
+ * modify it under the terms of the GNU Lesser General Public
+ * License as published by the Free Software Foundation; either
+ * version 2 of the License, or (at your option) any later version.
+ *
+ * This library is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+ * Lesser General Public License for more details.
+ *
+ * You should have received a copy of the GNU Lesser General Public
+ * License along with this library; if not, write to the Free
+ * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
+ */
+
+#include "config.h"
+#include <string.h>
+#include <fcntl.h>
+#include <unistd.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <sys/stat.h>
+#include <sys/event.h>
+#include <sys/time.h>
+#include <errno.h>
+#include "gam_error.h"
+#include "gam_kqueue.h"
+#include "gam_event.h"
+#include "gam_server.h"
+
+/*** tunable constants, modify to tweak the backend aggressivity *************/
+
+/*
+ * The backend will use at most n file descriptors, where n is the
+ * minimum value between (kern.maxfiles * CFG_GLOBAL_FILE_RESERVE_RATIO)
+ * and (kern.maxfilesperproc - CFG_SELF_FILE_RESERVE).
+ */
+#define CFG_GLOBAL_FILE_RESERVE_RATIO			0.7
+#define CFG_SELF_FILE_RESERVE				200
+
+/*
+ * If a SubMonitor or FileMonitor is not supported by kqueue and has
+ * to be polled, the backend will re-attempt to enable kqueue
+ * notification every n polls.
+ */
+#define CFG_UNSUPPORTED_SMON_KQUEUE_RETRY_FREQUENCY	10
+#define CFG_UNSUPPORTED_FMON_KQUEUE_RETRY_FREQUENCY	10
+
+/*
+ * The various poll intervals, in milliseconds. The default interval
+ * for each poller is based on the poller's expected usage.
+ */
+#define CFG_MISSING_SMON_POLL_INTERVAL			1000
+#define CFG_UNSUPPORTED_SMON_POLL_INTERVAL		3000
+#define CFG_UNSUPPORTED_FMON_POLL_INTERVAL		3000
+
+/*** end of tunable constants ************************************************/
+
+#define VN_NOTE_CHANGED	(NOTE_WRITE | NOTE_EXTEND | NOTE_ATTRIB | NOTE_LINK)
+#define VN_NOTE_DELETED (NOTE_DELETE | NOTE_REVOKE)
+#define VN_NOTE_ALL	(VN_NOTE_CHANGED | VN_NOTE_DELETED | NOTE_RENAME)
+
+/*
+ * A barebone stat structure, only containing the fields we need.
+ */
+typedef struct
+{
+  gboolean	exists;
+  ino_t		ino;
+  mode_t	mode;
+  uid_t		uid;
+  gid_t		gid;
+  time_t	mtime;
+  time_t	ctime;
+  off_t		size;
+} MiniStat;
+
+typedef void (*HashTableAddFunc) (GHashTable *table,
+				  gpointer item,
+				  gpointer user_data);
+typedef void (*HashTablePostAddFunc) (GHashTable *table,
+				      gpointer user_data);
+typedef void (*HashTableRemoveFunc) (GHashTable *table,
+				     gpointer item,
+				     gpointer user_data);
+typedef void (*HashTablePostRemoveFunc) (GHashTable *table,
+					 gpointer user_data);
+
+typedef struct
+{
+  HashTableAddFunc		add;
+  HashTablePostAddFunc		post_add;
+  HashTableRemoveFunc		remove;
+  HashTablePostRemoveFunc	post_remove;
+} HashTableMethods;
+  
+/*
+ * A hash table which can be modified while iterating over it.
+ */
+typedef struct
+{
+  GHashTable		*main;
+  gboolean		iterating;
+  GSList		*pending_additions;
+  GSList		*pending_removals;
+  HashTableMethods	*methods;
+  gpointer		user_data;
+} HashTable;
+
+/* the base monitor class */
+typedef struct _Monitor Monitor;
+struct _Monitor
+{
+  void (*handle_kevent) (Monitor *monitor, struct kevent *event);
+  char		*pathname;
+  int		fd;		/* for kqueue */
+  MiniStat	sb;		/* for poll */
+  unsigned int	poll_count;
+};
+#define MONITOR(ptr)		((Monitor *) ptr)
+
+typedef enum
+{
+  MONITOR_ISDIR		= 1 << 0,
+  MONITOR_ISNOTDIR	= 1 << 1
+} MonitorFlags;
+#define MONITOR_FLAGS_SHIFT	2
+
+/* monitor for Gamin subscriptions */
+typedef struct
+{
+  Monitor	base;
+  GList		*subs;
+  HashTable	*fmons;			/* FileMonitor objects */
+  HashTable	*unsupported_fmons;	/* subset of fmons to poll */
+  gboolean	isdir;			/* is a directory subscription? */
+} SubMonitor;
+#define SUB_MONITOR(ptr)	((SubMonitor *) ptr)
+
+typedef enum
+{
+  SUB_MONITOR_WAS_MISSING		= 1 << MONITOR_FLAGS_SHIFT
+} SubMonitorFlags;
+
+/* monitor for files within directory subscriptions */
+typedef struct
+{
+  Monitor	base;
+  SubMonitor	*smon;		/* the SubMonitor this fmon belongs to */
+  char		*filename;	/* pointer into base.pathname */
+} FileMonitor;
+#define FILE_MONITOR(ptr)	((FileMonitor *) ptr)
+
+typedef enum
+{
+  FILE_MONITOR_POSSIBLY_RECREATED	= 1 << MONITOR_FLAGS_SHIFT
+} FileMonitorFlags;
+
+typedef void (*PollerFunc) (SubMonitor *smon);
+typedef struct
+{
+  PollerFunc	func;
+  unsigned int	interval;
+  unsigned int	timeout_id;
+  HashTable	*smons;		/* SubMonitor objects */
+} Poller;
+
+static int kq = -1;
+
+static unsigned int open_files = 0;
+static unsigned int max_open_files = 0;
+
+static GHashTable *dir_hash = NULL;
+static GHashTable *file_hash = NULL;
+
+static Poller missing_smon_poller;
+static Poller unsupported_smon_poller;
+static Poller unsupported_fmon_poller;
+
+static void gam_kqueue_hash_table_default_add_cb (GHashTable *table,
+						  gpointer item,
+						  gpointer user_data);
+static void gam_kqueue_hash_table_default_remove_cb (GHashTable *table,
+						     gpointer item,
+						     gpointer user_data);
+
+static void gam_kqueue_poller_post_add_cb (GHashTable *table, Poller *poller);
+static void gam_kqueue_poller_post_remove_cb (GHashTable *table, Poller *poller);
+
+static HashTableMethods poller_hash_table_methods =
+  {
+    gam_kqueue_hash_table_default_add_cb,
+    (HashTablePostAddFunc) gam_kqueue_poller_post_add_cb,
+    gam_kqueue_hash_table_default_remove_cb,
+    (HashTablePostRemoveFunc) gam_kqueue_poller_post_remove_cb
+  };
+
+static void gam_kqueue_sub_monitor_add_fmon_cb (GHashTable *table,
+						FileMonitor *fmon,
+						SubMonitor *smon);
+static void gam_kqueue_sub_monitor_remove_fmon_cb (GHashTable *table,
+						   FileMonitor *fmon,
+						   SubMonitor *smon);
+
+static HashTableMethods sub_monitor_fmons_hash_table_methods =
+  {
+    (HashTableAddFunc) gam_kqueue_sub_monitor_add_fmon_cb,
+    (HashTablePostAddFunc) NULL,
+    (HashTableRemoveFunc) gam_kqueue_sub_monitor_remove_fmon_cb,
+    (HashTablePostRemoveFunc) NULL
+  };
+
+static void gam_kqueue_sub_monitor_post_add_unsupported_fmon_cb (GHashTable *table,
+								 SubMonitor *smon);
+static void gam_kqueue_sub_monitor_post_remove_unsupported_fmon_cb (GHashTable *table,
+								    SubMonitor *smon);
+
+static HashTableMethods sub_monitor_unsupported_fmons_hash_table_methods =
+  {
+    gam_kqueue_hash_table_default_add_cb,
+    (HashTablePostAddFunc) gam_kqueue_sub_monitor_post_add_unsupported_fmon_cb,
+    gam_kqueue_hash_table_default_remove_cb,
+    (HashTablePostRemoveFunc) gam_kqueue_sub_monitor_post_remove_unsupported_fmon_cb
+  };
+
+static void gam_kqueue_sub_monitor_emit_event (SubMonitor *smon,
+					       GaminEventType event,
+					       SubMonitorFlags flags);
+static void gam_kqueue_sub_monitor_handle_kevent (Monitor *mon,
+						  struct kevent *event);
+
+static FileMonitor *gam_kqueue_file_monitor_new (SubMonitor *smon,
+						 const char *filename,
+						 FileMonitorFlags *flags);
+static void gam_kqueue_file_monitor_free (FileMonitor *fmon);
+static void gam_kqueue_file_monitor_emit_event (FileMonitor *fmon,
+						GaminEventType event,
+						FileMonitorFlags flags);
+static void gam_kqueue_file_monitor_handle_kevent (Monitor *mon, struct kevent *event);
+
+/*** helpers *****************************************************************/
+
+static void
+gam_kqueue_mini_lstat (const char *pathname, MiniStat *mini_sb)
+{
+  struct stat sb;
+  
+  if (lstat(pathname, &sb) < 0)
+    memset(mini_sb, 0, sizeof(*mini_sb));
+  else
+    {
+      mini_sb->exists = TRUE;
+      mini_sb->ino = sb.st_ino;
+      mini_sb->mode = sb.st_mode;
+      mini_sb->uid = sb.st_uid;
+      mini_sb->gid = sb.st_gid;
+      mini_sb->mtime = sb.st_mtime;
+      mini_sb->ctime = sb.st_ctime;
+      mini_sb->size = sb.st_size;
+    }
+}
+
+static gboolean
+gam_kqueue_differs (const MiniStat *sb1, const MiniStat *sb2)
+{
+  return sb1->mtime != sb2->mtime
+    || sb1->ctime != sb2->ctime
+    || sb1->size != sb2->size
+    || sb1->mode != sb2->mode
+    || sb1->uid != sb2->uid
+    || sb1->gid != sb2->gid
+    || sb1->ino != sb2->ino;
+}
+
+static gboolean
+gam_kqueue_isdir (const char *pathname, MonitorFlags flags)
+{
+  if ((flags & MONITOR_ISDIR) != 0)
+    return TRUE;
+  else if ((flags & MONITOR_ISNOTDIR) != 0)
+    return FALSE;
+  else
+    {
+      struct stat sb;
+      return lstat(pathname, &sb) >= 0 && (sb.st_mode & S_IFDIR) != 0;
+    }
+}
+
+static gboolean
+gam_kqueue_get_uint_sysctl (const char *name, unsigned int *value)
+{
+  unsigned int value_len = sizeof(*value);
+
+  if (sysctlbyname(name, value, &value_len, NULL, 0) < 0)
+    {
+      gam_error(DEBUG_INFO, "unable to retrieve %s: %s\n", name, g_strerror(errno));
+      return FALSE;
+    }
+  else
+    return TRUE;
+}
+
+/*** HashTable ***************************************************************/
+
+static HashTable *
+gam_kqueue_hash_table_new (GHashTable *main,
+			   HashTableMethods *methods,
+			   gpointer user_data)
+{
+  HashTable *table;
+
+  table = g_new0(HashTable, 1);
+  table->main = main;
+  table->methods = methods;
+  table->user_data = user_data;
+
+  return table;
+}
+
+static void
+gam_kqueue_hash_table_default_add_cb (GHashTable *table,
+				      gpointer item,
+				      gpointer user_data)
+{
+  g_hash_table_insert(table, item, GINT_TO_POINTER(TRUE));
+}
+
+static void
+gam_kqueue_hash_table_default_remove_cb (GHashTable *table,
+					 gpointer item,
+					 gpointer user_data)
+{
+  g_hash_table_remove(table, item);
+}
+
+static void
+gam_kqueue_hash_table_add (HashTable *table, gpointer item)
+{
+  if (table->iterating)
+    table->pending_additions = g_slist_prepend(table->pending_additions, item);
+  else
+    {
+      table->methods->add(table->main, item, table->user_data);
+      if (table->methods->post_add)
+	table->methods->post_add(table->main, table->user_data);
+    }
+}
+
+static void
+gam_kqueue_hash_table_remove (HashTable *table, gpointer item)
+{
+  if (table->iterating)
+    table->pending_removals = g_slist_prepend(table->pending_removals, item);
+  else
+    {
+      table->methods->remove(table->main, item, table->user_data);
+      if (table->methods->post_remove)
+	table->methods->post_remove(table->main, table->user_data);
+    }
+}
+
+static void
+gam_kqueue_hash_table_foreach (HashTable *table,
+			       GHFunc func,
+			       gpointer user_data)
+{
+  g_assert(table->iterating == FALSE);
+
+  table->iterating = TRUE;
+  g_hash_table_foreach(table->main, func, user_data);
+  table->iterating = FALSE;
+  
+  if (table->pending_additions)
+    {
+      GSList *l;
+
+      for (l = table->pending_additions; l != NULL; l = l->next)
+	table->methods->add(table->main, l->data, table->user_data);
+
+      g_slist_free(table->pending_additions);
+      table->pending_additions = NULL;
+
+      if (table->methods->post_add)
+	table->methods->post_add(table->main, table->user_data);
+    }
+
+  if (table->pending_removals)
+    {
+      GSList *l;
+
+      for (l = table->pending_removals; l != NULL; l = l->next)
+	table->methods->remove(table->main, l->data, table->user_data);
+
+      g_slist_free(table->pending_removals);
+      table->pending_removals = NULL;
+
+      if (table->methods->post_remove)
+	table->methods->post_remove(table->main, table->user_data);
+    }
+}
+
+static void
+gam_kqueue_hash_table_destroy (HashTable *table)
+{
+  g_assert(table->iterating == FALSE);
+
+  g_hash_table_destroy(table->main);
+  g_free(table);
+}
+
+/*** Poller ******************************************************************/
+
+static void
+gam_kqueue_poller_init (Poller *poller, PollerFunc func, unsigned int interval)
+{
+  poller->func = func;
+  poller->interval = interval;
+  poller->timeout_id = 0;
+  poller->smons = gam_kqueue_hash_table_new(g_hash_table_new(g_direct_hash, g_direct_equal),
+					    &poller_hash_table_methods,
+					    poller);
+}
+
+static void
+gam_kqueue_poller_foreach_cb (SubMonitor *smon,
+			      gpointer unused,
+			      Poller *poller)
+{
+  poller->func(smon);
+}
+
+static gboolean
+gam_kqueue_poller_timeout_cb (Poller *poller)
+{
+  gam_kqueue_hash_table_foreach(poller->smons, (GHFunc) gam_kqueue_poller_foreach_cb, poller);
+
+  return TRUE;			/* keep source */
+}
+
+static void
+gam_kqueue_poller_post_add_cb (GHashTable *table, Poller *poller)
+{
+  if (! poller->timeout_id)
+    poller->timeout_id = g_timeout_add(poller->interval, (GSourceFunc) gam_kqueue_poller_timeout_cb, poller);
+}
+
+static void
+gam_kqueue_poller_post_remove_cb (GHashTable *table, Poller *poller)
+{
+  if (g_hash_table_size(table) == 0 && poller->timeout_id)
+    {
+      g_source_remove(poller->timeout_id);
+      poller->timeout_id = 0;
+    }
+}
+
+static void
+gam_kqueue_poller_add_sub_monitor (Poller *poller, SubMonitor *smon)
+{
+  gam_kqueue_hash_table_add(poller->smons, smon);
+}
+
+static void
+gam_kqueue_poller_remove_sub_monitor (Poller *poller, SubMonitor *smon)
+{
+  gam_kqueue_hash_table_remove(poller->smons, smon);
+}
+
+/*** Monitor *****************************************************************/
+
+static gboolean
+gam_kqueue_monitor_enable_kqueue (Monitor *mon)
+{
+  struct kevent ev[1];
+
+  if (open_files == max_open_files)
+    {
+      GAM_DEBUG(DEBUG_INFO, "cannot open %s (max_open_files limit reached), falling back to poll\n", mon->pathname);
+      return FALSE;
+    }
+  
+  mon->fd = open(mon->pathname, O_RDONLY | O_NOFOLLOW);
+  if (mon->fd < 0)
+    {
+      GAM_DEBUG(DEBUG_INFO, "cannot open %s (%s), falling back to poll\n", mon->pathname, g_strerror(errno));
+      return FALSE;
+    }
+
+  EV_SET(ev, mon->fd, EVFILT_VNODE, EV_ADD | EV_ENABLE | EV_CLEAR, VN_NOTE_ALL, 0, mon);
+  if (kevent(kq, ev, G_N_ELEMENTS(ev), NULL, 0, NULL) < 0)
+    {
+      GAM_DEBUG(DEBUG_INFO, "cannot enable kqueue notification for %s (%s), falling back to poll\n", mon->pathname, g_strerror(errno));
+
+      close(mon->fd);
+      mon->fd = -1;
+
+      return FALSE;
+    }
+
+  open_files++;
+  return TRUE;
+}
+
+static void
+gam_kqueue_monitor_set_unsupported (Monitor *mon)
+{
+  if (mon->fd >= 0)
+    {
+      close(mon->fd);
+      mon->fd = -1;
+
+      open_files--;
+    }
+
+  gam_kqueue_mini_lstat(mon->pathname, &mon->sb);
+}
+
+static void
+gam_kqueue_monitor_free (Monitor *mon)
+{
+  g_free(mon->pathname);
+  if (mon->fd >= 0)
+    {
+      close(mon->fd);
+      open_files--;
+    }
+  g_free(mon);
+}
+
+/*** SubMonitor **************************************************************/
+
+static void
+gam_kqueue_sub_monitor_init_fmons (SubMonitor *smon)
+{
+  smon->fmons = gam_kqueue_hash_table_new(g_hash_table_new_full(g_str_hash, g_str_equal, NULL, (GDestroyNotify) gam_kqueue_file_monitor_free),
+					  &sub_monitor_fmons_hash_table_methods,
+					  smon);
+  smon->unsupported_fmons = gam_kqueue_hash_table_new(g_hash_table_new(g_direct_hash, g_direct_equal),
+						      &sub_monitor_unsupported_fmons_hash_table_methods,
+						      smon);
+}
+
+static SubMonitor *
+gam_kqueue_sub_monitor_new (GamSubscription *sub)
+{
+  SubMonitor *smon;
+  Monitor *mon;
+
+  smon = g_new0(SubMonitor, 1);
+
+  mon = MONITOR(smon);
+  mon->handle_kevent = gam_kqueue_sub_monitor_handle_kevent;
+  mon->pathname = g_strdup(gam_subscription_get_path(sub));
+  mon->fd = -1;
+
+  smon->isdir = gam_subscription_is_dir(sub);
+  gam_kqueue_sub_monitor_init_fmons(smon);
+
+  return smon;
+}
+
+static void
+gam_kqueue_sub_monitor_clear_fmons (SubMonitor *smon)
+{
+  if (g_hash_table_size(smon->unsupported_fmons->main) > 0)
+    gam_kqueue_poller_remove_sub_monitor(&unsupported_fmon_poller, smon);
+
+  gam_kqueue_hash_table_destroy(smon->unsupported_fmons);
+  gam_kqueue_hash_table_destroy(smon->fmons);
+}
+
+static void
+gam_kqueue_sub_monitor_free (SubMonitor *smon)
+{
+  gam_kqueue_poller_remove_sub_monitor(&missing_smon_poller, smon);
+  gam_kqueue_poller_remove_sub_monitor(&unsupported_smon_poller, smon);
+  /* unsupported_dirs_poller is handled by _clear_fmons() below */
+  
+  gam_kqueue_sub_monitor_clear_fmons(smon);
+  gam_kqueue_monitor_free(MONITOR(smon));
+}
+
+static void
+gam_kqueue_sub_monitor_add_fmon_cb (GHashTable *table,
+				    FileMonitor *fmon,
+				    SubMonitor *smon)
+{
+  g_hash_table_replace(table, fmon->filename, fmon);
+}
+
+static void
+gam_kqueue_sub_monitor_remove_fmon_cb (GHashTable *table,
+				       FileMonitor *fmon,
+				       SubMonitor *smon)
+{
+  g_hash_table_remove(table, fmon->filename);
+}
+
+static void
+gam_kqueue_sub_monitor_post_add_unsupported_fmon_cb (GHashTable *table,
+						     SubMonitor *smon)
+{
+  gam_kqueue_poller_add_sub_monitor(&unsupported_fmon_poller, smon);
+}
+
+static void
+gam_kqueue_sub_monitor_post_remove_unsupported_fmon_cb (GHashTable *table,
+							SubMonitor *smon)
+{
+  if (g_hash_table_size(table) == 0)
+    gam_kqueue_poller_remove_sub_monitor(&unsupported_fmon_poller, smon);
+}
+
+static void
+gam_kqueue_sub_monitor_set_missing (SubMonitor *smon)
+{
+  Monitor *mon = MONITOR(smon);
+
+  if (mon->fd >= 0)
+    {
+      close(mon->fd);
+      mon->fd = -1;
+
+      open_files--;
+    }
+
+  /*
+   * A removed directory will normally not contain files, but we must
+   * not assume it (we might receive events out of order, etc). We
+   * therefore check if files are remaining, and if yes, clear them.
+   */
+  if (g_hash_table_size(smon->fmons->main) > 0)
+    {
+      gam_kqueue_sub_monitor_clear_fmons(smon);
+      gam_kqueue_sub_monitor_init_fmons(smon);
+    }
+
+  gam_kqueue_poller_remove_sub_monitor(&unsupported_smon_poller, smon);
+  gam_kqueue_poller_add_sub_monitor(&missing_smon_poller, smon);
+}
+
+static void
+gam_kqueue_sub_monitor_set_unsupported (SubMonitor *smon)
+{
+  Monitor *mon = MONITOR(smon);
+
+  gam_kqueue_monitor_set_unsupported(mon);
+  gam_kqueue_poller_add_sub_monitor(&unsupported_smon_poller, smon);
+}
+
+static void
+gam_kqueue_sub_monitor_enable_notification (SubMonitor *smon,
+					    SubMonitorFlags flags)
+{
+  Monitor *mon = MONITOR(smon);
+  gboolean exists;
+
+  /* we first send CREATED or EXISTS/DELETED+ENDEXISTS events */
+
+  if ((flags & SUB_MONITOR_WAS_MISSING) != 0)
+    exists = TRUE;
+  else
+    {
+      struct stat sb;
+
+      exists = lstat(mon->pathname, &sb) >= 0;
+      flags |= (exists && (sb.st_mode & S_IFDIR) != 0) ? MONITOR_ISDIR : MONITOR_ISNOTDIR;
+    }
+
+  if (exists)
+    {
+      GaminEventType gevent;
+
+      gevent = (flags & SUB_MONITOR_WAS_MISSING) != 0 ? GAMIN_EVENT_CREATED : GAMIN_EVENT_EXISTS;
+      gam_kqueue_sub_monitor_emit_event(smon, gevent, flags);
+
+      if (smon->isdir && (flags & MONITOR_ISDIR) != 0)
+	{
+	  GDir *dir;
+	  GError *err = NULL;
+	  
+	  dir = g_dir_open(mon->pathname, 0, &err);
+	  if (dir)
+	    {
+	      const char *filename;
+	      
+	      while ((filename = g_dir_read_name(dir)))
+		{
+		  FileMonitor *fmon;
+		  FileMonitorFlags fmon_flags;
+		  
+		  fmon = gam_kqueue_file_monitor_new(smon, filename, &fmon_flags);
+		  gam_kqueue_file_monitor_emit_event(fmon, gevent, fmon_flags);
+		}
+	      
+	      g_dir_close(dir);
+	    }
+	  else
+	    {
+	      GAM_DEBUG(DEBUG_INFO, "unable to open directory %s: %s\n", mon->pathname, err->message);
+	      g_error_free(err);
+	    }
+	}
+
+      if ((flags & SUB_MONITOR_WAS_MISSING) == 0)
+	gam_kqueue_sub_monitor_emit_event(smon, GAMIN_EVENT_ENDEXISTS, flags);
+    }
+  else
+    {
+      gam_kqueue_sub_monitor_emit_event(smon, GAMIN_EVENT_DELETED, flags);
+      gam_kqueue_sub_monitor_emit_event(smon, GAMIN_EVENT_ENDEXISTS, flags);
+
+      return;
+    }
+    
+  /* then we enable kqueue notification, falling back to poll if necessary */
+
+  if (! gam_kqueue_monitor_enable_kqueue(mon))
+    gam_kqueue_sub_monitor_set_unsupported(smon);
+}
+
+static void
+gam_kqueue_sub_monitor_handle_directory_change_removal_cb (const char *filename,
+							   FileMonitor *fmon,
+							   GHashTable *filenames)
+{
+  if (! g_hash_table_lookup(filenames, filename))
+    gam_kqueue_file_monitor_emit_event(fmon, GAMIN_EVENT_DELETED, MONITOR_ISNOTDIR);
+}
+
+static void
+gam_kqueue_sub_monitor_handle_directory_change (SubMonitor *smon,
+						gboolean isdir)
+{
+  Monitor *mon = MONITOR(smon);
+  GHashTable *filenames;
+
+  filenames = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, NULL);
+
+  if (isdir)			/* do not follow symbolic links */
+    {
+      GDir *dir;
+      GError *err = NULL;
+
+      dir = g_dir_open(mon->pathname, 0, &err);
+      if (dir)
+	{
+	  const char *filename;
+	  
+	  while ((filename = g_dir_read_name(dir)))
+	    {
+	      g_hash_table_insert(filenames, g_strdup(filename), GINT_TO_POINTER(TRUE));
+
+	      /* handle file creation */
+	      if (! g_hash_table_lookup(smon->fmons->main, filename))
+		{
+		  FileMonitor *fmon;
+		  FileMonitorFlags fmon_flags;
+		  
+		  fmon = gam_kqueue_file_monitor_new(smon, filename, &fmon_flags);
+		  gam_kqueue_file_monitor_emit_event(fmon, GAMIN_EVENT_CREATED, fmon_flags);
+		}
+	    }
+	  
+	  g_dir_close(dir);
+	}
+      else
+	{
+	  GAM_DEBUG(DEBUG_INFO, "unable to open directory %s: %s\n", mon->pathname, err->message);
+	  g_error_free(err);
+	}
+    }
+
+  /*
+   * Handle deleted files (they are also handled at the FileMonitor
+   * level, but we must use whichever event comes first).
+   */
+  gam_kqueue_hash_table_foreach(smon->fmons, (GHFunc) gam_kqueue_sub_monitor_handle_directory_change_removal_cb, filenames);
+  g_hash_table_destroy(filenames);
+}
+
+static void
+gam_kqueue_sub_monitor_emit_event (SubMonitor *smon,
+				   GaminEventType event,
+				   SubMonitorFlags flags)
+{
+  Monitor *mon = MONITOR(smon);
+  gboolean isdir;
+
+  isdir = gam_kqueue_isdir(mon->pathname, flags);
+
+  switch (event)
+    {
+    case GAMIN_EVENT_CHANGED:
+      if (smon->isdir)
+	{
+	  gam_kqueue_sub_monitor_handle_directory_change(smon, isdir);
+	  return;
+	}
+      break;
+
+    case GAMIN_EVENT_DELETED:
+    case GAMIN_EVENT_MOVED:
+      gam_kqueue_sub_monitor_set_missing(smon);
+      break;
+    }
+
+  gam_server_emit_event(mon->pathname, isdir, event, smon->subs, 1);
+}
+
+static void
+gam_kqueue_sub_monitor_handle_kevent (Monitor *mon, struct kevent *event)
+{
+  SubMonitor *smon = SUB_MONITOR(mon);
+
+  if ((event->flags & EV_ERROR) != 0)
+    {
+      /* kqueue failed, fallback to poll */
+      GAM_DEBUG(DEBUG_INFO, "kqueue failed for %s, falling back to poll\n", mon->pathname);
+      gam_kqueue_sub_monitor_set_unsupported(smon);
+      return;
+    }
+
+  /*
+   * kevent aggregates events, so we must handle a fflags with
+   * multiple event bits set.
+   */
+  if ((event->fflags & VN_NOTE_CHANGED) != 0)
+    gam_kqueue_sub_monitor_emit_event(smon, GAMIN_EVENT_CHANGED, 0);
+
+  /* emitting the following events will add the smon to the missing poller */
+  if ((event->fflags & VN_NOTE_DELETED) != 0)
+    gam_kqueue_sub_monitor_emit_event(smon, GAMIN_EVENT_DELETED, MONITOR_ISNOTDIR);
+  else if ((event->fflags & NOTE_RENAME) != 0)
+    gam_kqueue_sub_monitor_emit_event(smon, GAMIN_EVENT_MOVED, MONITOR_ISNOTDIR);
+}
+
+/*** FileMonitor *************************************************************/
+
+static void
+gam_kqueue_file_monitor_set_unsupported (FileMonitor *fmon)
+{
+  Monitor *mon = MONITOR(fmon);
+
+  gam_kqueue_monitor_set_unsupported(mon);
+  gam_kqueue_hash_table_add(fmon->smon->unsupported_fmons, fmon);
+}
+
+static FileMonitor *
+gam_kqueue_file_monitor_new (SubMonitor *smon,
+			     const char *filename,
+			     FileMonitorFlags *flags)
+{
+  FileMonitor *fmon;
+  Monitor *mon;
+
+  fmon = g_new0(FileMonitor, 1);
+
+  mon = MONITOR(fmon);
+  mon->handle_kevent = gam_kqueue_file_monitor_handle_kevent;
+  mon->pathname = g_build_filename(MONITOR(smon)->pathname, filename, NULL);
+  mon->fd = -1;
+
+  fmon->smon = smon;
+  fmon->filename = strrchr(mon->pathname, G_DIR_SEPARATOR);
+  fmon->filename = fmon->filename ? fmon->filename + 1 : mon->pathname;
+
+  gam_kqueue_hash_table_add(fmon->smon->fmons, fmon);
+
+  if (gam_kqueue_monitor_enable_kqueue(mon))
+    *flags = 0;
+  else
+    {
+      gam_kqueue_file_monitor_set_unsupported(fmon);
+      *flags = (mon->sb.mode & S_IFDIR) != 0 ? MONITOR_ISDIR : MONITOR_ISNOTDIR;
+    }
+
+  return fmon;
+}
+
+static void
+gam_kqueue_file_monitor_free (FileMonitor *fmon)
+{
+  gam_kqueue_monitor_free(MONITOR(fmon));
+}
+
+static void
+gam_kqueue_file_monitor_emit_event (FileMonitor *fmon,
+				    GaminEventType event,
+				    FileMonitorFlags flags)
+{
+  Monitor *mon = MONITOR(fmon);
+  struct stat sb;
+  gboolean isdir;
+  gboolean stat_done;
+  gboolean stat_succeeded;
+  
+  if ((flags & MONITOR_ISDIR) == 0 && (flags & MONITOR_ISNOTDIR) == 0)
+    {
+      stat_done = TRUE;
+      stat_succeeded = lstat(mon->pathname, &sb) >= 0;
+      isdir = stat_succeeded && (sb.st_mode & S_IFDIR) != 0;
+    }
+  else
+    {
+      stat_done = FALSE;
+      isdir = (flags & MONITOR_ISDIR) != 0;
+    }
+  
+  gam_server_emit_event(mon->pathname, isdir, event, fmon->smon->subs, 1);
+
+  switch (event)
+    {
+    case GAMIN_EVENT_DELETED:
+    case GAMIN_EVENT_MOVED:
+      if (mon->fd < 0)
+	gam_kqueue_hash_table_remove(fmon->smon->unsupported_fmons, fmon);
+
+      if ((flags & FILE_MONITOR_POSSIBLY_RECREATED) != 0)
+	{
+	  if (! stat_done)
+	    stat_succeeded = lstat(mon->pathname, &sb) >= 0;
+
+	  if (stat_succeeded)
+	    {
+	      FileMonitor *new_fmon;
+	      FileMonitorFlags new_fmon_flags;
+	      
+	      /*
+	       * The file exists again. It means that kqueue has
+	       * aggregated a removal+creation into a single event. We
+	       * must therefore create a new fmon and emit a
+	       * GAMIN_EVENT_CREATED event, because
+	       * gam_kqueue_sub_monitor_handle_directory_change() did
+	       * not detect the removal+creation.
+	       */
+
+	      new_fmon = gam_kqueue_file_monitor_new(fmon->smon, fmon->filename, &new_fmon_flags);
+	      gam_kqueue_file_monitor_emit_event(new_fmon, GAMIN_EVENT_CREATED, new_fmon_flags);
+
+	      break;		/* do not remove the fmon we've just created */
+	    }
+	}
+	
+      gam_kqueue_hash_table_remove(fmon->smon->fmons, fmon);
+      break;
+    }
+}
+
+static void
+gam_kqueue_file_monitor_handle_kevent (Monitor *mon, struct kevent *event)
+{
+  FileMonitor *fmon = FILE_MONITOR(mon);
+
+  if ((event->flags & EV_ERROR) != 0)
+    {
+      /* kqueue failed, fallback to poll */
+      GAM_DEBUG(DEBUG_INFO, "kqueue failed for %s, falling back to poll\n", mon->pathname);
+      gam_kqueue_file_monitor_set_unsupported(fmon);
+      return;
+    }
+
+  /*
+   * kevent aggregates events, so we must handle a fflags with
+   * multiple event bits set.
+   */
+
+  if ((event->fflags & VN_NOTE_CHANGED) != 0)
+    gam_kqueue_file_monitor_emit_event(fmon, GAMIN_EVENT_CHANGED, 0);
+
+  /* emitting the following events will free the fmon */
+  if ((event->fflags & VN_NOTE_DELETED) != 0)
+    gam_kqueue_file_monitor_emit_event(fmon, GAMIN_EVENT_DELETED, MONITOR_ISNOTDIR | FILE_MONITOR_POSSIBLY_RECREATED);
+  else if ((event->fflags & NOTE_RENAME) != 0)
+    gam_kqueue_file_monitor_emit_event(fmon, GAMIN_EVENT_MOVED, MONITOR_ISNOTDIR | FILE_MONITOR_POSSIBLY_RECREATED);
+}
+
+/*** kevent/poll callbacks ***************************************************/
+
+static gboolean
+gam_kqueue_kevent_cb (GIOChannel *source,
+		      GIOCondition condition,
+		      gpointer user_data)
+{
+  int nevents;
+  struct kevent ev[1];
+  struct timespec timeout = { 0, 0 };
+  int i;
+
+  nevents = kevent(kq, NULL, 0, ev, G_N_ELEMENTS(ev), &timeout);
+  if (nevents < 0)
+    {
+      GAM_DEBUG(DEBUG_INFO, "kevent() failure: %s\n", g_strerror(errno));
+      return TRUE;		/* keep source */
+    }
+
+  for (i = 0; i < nevents; i++)
+    MONITOR(ev[i].udata)->handle_kevent(ev[i].udata, &ev[i]);
+  
+  return TRUE;			/* keep source */
+}
+
+static void
+gam_kqueue_missing_smon_poll (SubMonitor *smon)
+{
+  struct stat sb;
+
+  if (lstat(MONITOR(smon)->pathname, &sb) >= 0)
+    {
+      gam_kqueue_poller_remove_sub_monitor(&missing_smon_poller, smon);
+      gam_kqueue_sub_monitor_enable_notification(smon, SUB_MONITOR_WAS_MISSING | ((sb.st_mode & S_IFDIR) != 0 ? MONITOR_ISDIR : MONITOR_ISNOTDIR));
+    }
+}
+
+static void
+gam_kqueue_unsupported_smon_poll (SubMonitor *smon)
+{
+  Monitor *mon = MONITOR(smon);
+  MiniStat sb;
+  GaminEventType event;
+
+  if (++mon->poll_count == CFG_UNSUPPORTED_SMON_KQUEUE_RETRY_FREQUENCY)
+    {
+      mon->poll_count = 0;
+      if (gam_kqueue_monitor_enable_kqueue(mon))
+	gam_kqueue_poller_remove_sub_monitor(&missing_smon_poller, smon);
+    }
+  
+  gam_kqueue_mini_lstat(mon->pathname, &sb);
+  
+  if (! sb.exists && mon->sb.exists)
+    event = GAMIN_EVENT_DELETED;
+  else if (gam_kqueue_differs(&sb, &mon->sb))
+    event = GAMIN_EVENT_CHANGED;
+  else
+    return;
+	
+  memcpy(&mon->sb, &sb, sizeof(sb));
+  gam_kqueue_sub_monitor_emit_event(smon, event, (sb.mode & S_IFDIR) != 0 ? MONITOR_ISDIR : MONITOR_ISNOTDIR);
+}
+
+static void
+gam_kqueue_unsupported_fmon_poll_foreach_cb (FileMonitor *fmon,
+					     gpointer unused,
+					     gpointer user_data)
+{
+  Monitor *mon = MONITOR(fmon);
+  MiniStat sb;
+  GaminEventType event;
+
+  if (++mon->poll_count == CFG_UNSUPPORTED_FMON_KQUEUE_RETRY_FREQUENCY)
+    {
+      mon->poll_count = 0;
+      if (gam_kqueue_monitor_enable_kqueue(mon))
+	gam_kqueue_hash_table_remove(fmon->smon->unsupported_fmons, fmon);
+    }
+
+  gam_kqueue_mini_lstat(mon->pathname, &sb);
+
+  if (! sb.exists && mon->sb.exists)
+    event = GAMIN_EVENT_DELETED;
+  else if (gam_kqueue_differs(&sb, &mon->sb))
+    event = GAMIN_EVENT_CHANGED;
+  else
+    return;
+
+  memcpy(&mon->sb, &sb, sizeof(sb));
+  gam_kqueue_file_monitor_emit_event(fmon, event, (sb.mode & S_IFDIR) != 0 ? MONITOR_ISDIR : MONITOR_ISNOTDIR);
+}
+
+static void
+gam_kqueue_unsupported_fmon_poll (SubMonitor *smon)
+{
+  gam_kqueue_hash_table_foreach(smon->unsupported_fmons, (GHFunc) gam_kqueue_unsupported_fmon_poll_foreach_cb, NULL);
+}
+
+/*** Gamin backend implementation ********************************************/
+
+/**
+ * Initializes the kqueue system.  This must be called before
+ * any other functions in this module.
+ *
+ * @returns TRUE if initialization succeeded, FALSE otherwise
+ */
+gboolean
+gam_kqueue_init (void)
+{
+  GIOChannel *channel;
+  unsigned int maxfiles;
+  unsigned int maxfilesperproc;
+
+  kq = kqueue();
+  if (kq < 0)
+    {
+      gam_error(DEBUG_INFO, "kqueue initialization failure: %s\n", g_strerror(errno));
+      return FALSE;
+    }
+
+  if (! gam_kqueue_get_uint_sysctl("kern.maxfiles", &maxfiles))
+    return FALSE;
+  if (! gam_kqueue_get_uint_sysctl("kern.maxfilesperproc", &maxfilesperproc))
+    return FALSE;
+
+  /*
+   * We make sure to:
+   *	- never paralyze the system (CFG_GLOBAL_FILE_RESERVE_RATIO)
+   *	- never paralyze our own process (CFG_SELF_FILE_RESERVE)
+   */
+
+  maxfiles *= CFG_GLOBAL_FILE_RESERVE_RATIO;
+  maxfilesperproc = maxfilesperproc > CFG_SELF_FILE_RESERVE
+    ? maxfilesperproc - CFG_SELF_FILE_RESERVE
+    : 0;
+
+  max_open_files = MIN(maxfiles, maxfilesperproc);
+
+  dir_hash = g_hash_table_new(g_str_hash, g_str_equal);
+  file_hash = g_hash_table_new(g_str_hash, g_str_equal);
+
+  gam_kqueue_poller_init(&missing_smon_poller,
+			 gam_kqueue_missing_smon_poll,
+			 CFG_MISSING_SMON_POLL_INTERVAL);
+  gam_kqueue_poller_init(&unsupported_smon_poller,
+			 gam_kqueue_unsupported_smon_poll,
+			 CFG_UNSUPPORTED_SMON_POLL_INTERVAL);
+  gam_kqueue_poller_init(&unsupported_fmon_poller,
+			 gam_kqueue_unsupported_fmon_poll,
+			 CFG_UNSUPPORTED_FMON_POLL_INTERVAL);
+
+  channel = g_io_channel_unix_new(kq);
+  g_io_add_watch(channel, G_IO_IN, gam_kqueue_kevent_cb, NULL);
+
+  gam_backend_add_subscription = gam_kqueue_add_subscription;
+  gam_backend_remove_subscription = gam_kqueue_remove_subscription;
+  gam_backend_remove_all_for = gam_kqueue_remove_all_for;
+
+  return TRUE;
+}
+
+/**
+ * Adds a subscription to be monitored.
+ *
+ * @param sub a #GamSubscription to be polled
+ * @returns TRUE if adding the subscription succeeded, FALSE otherwise
+ */
+gboolean
+gam_kqueue_add_subscription (GamSubscription *sub)
+{
+  const char *path;
+  GHashTable *hash;
+  SubMonitor *smon;
+
+  gam_listener_add_subscription(gam_subscription_get_listener(sub), sub);
+
+  path = gam_subscription_get_path(sub);
+  hash = gam_subscription_is_dir(sub) ? dir_hash : file_hash;
+  smon = g_hash_table_lookup(hash, path);
+
+  if (smon)
+    {
+      smon->subs = g_list_append(smon->subs, sub);
+      return TRUE;
+    }
+  
+  smon = gam_kqueue_sub_monitor_new(sub);
+  smon->subs = g_list_append(smon->subs, sub);
+
+  g_hash_table_insert(hash, MONITOR(smon)->pathname, smon);
+  gam_kqueue_sub_monitor_enable_notification(smon, 0);
+
+  return TRUE;
+}
+
+/**
+ * Removes a subscription which was being monitored.
+ *
+ * @param sub a #GamSubscription to remove
+ * @returns TRUE if removing the subscription succeeded, FALSE otherwise
+ */
+gboolean
+gam_kqueue_remove_subscription (GamSubscription *sub)
+{
+  GHashTable *hash;
+  SubMonitor *smon;
+
+  hash = gam_subscription_is_dir(sub) ? dir_hash : file_hash;
+  smon = g_hash_table_lookup(hash, gam_subscription_get_path(sub));
+
+  if (! smon)
+    return FALSE;
+
+  smon->subs = g_list_remove_all(smon->subs, sub);
+  if (! smon->subs)
+    {
+      g_hash_table_remove(hash, MONITOR(smon)->pathname);
+      gam_kqueue_sub_monitor_free(smon);
+    }
+
+  gam_subscription_cancel(sub);
+  gam_listener_remove_subscription(gam_subscription_get_listener(sub), sub);
+
+  return TRUE;
+}
+
+/**
+ * Stop monitoring all subscriptions for a given listener.
+ *
+ * @param listener a #GamListener
+ * @returns TRUE if removing the subscriptions succeeded, FALSE otherwise
+ */
+gboolean
+gam_kqueue_remove_all_for (GamListener *listener)
+{
+  GList *subs;
+  GList *l;
+  gboolean success = TRUE;
+
+  subs = gam_listener_get_subscriptions(listener);
+
+  for (l = subs; l != NULL; l = l->next)
+    if (! gam_kqueue_remove_subscription(l->data))
+      success = FALSE;
+
+  g_list_free(subs);
+  
+  return success;
+}
