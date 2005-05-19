--- server/gam_kqueue.c.orig	Thu May 19 20:34:55 2005
+++ server/gam_kqueue.c	Thu May 19 20:35:11 2005
@@ -1,5 +1,37 @@
 /*
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
  * Copyright (C) 2005 Joe Marcus Clarke <marcus@FreeBSD.org>
+ * Copyright (C) 2005 Jean-Yves Lefort <jylefort@FreeBSD.org>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of the GNU Lesser General Public
@@ -16,508 +48,1068 @@
  * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
  */
 
-
-#include "server_config.h"
+#include "config.h"
+#include <string.h>
+#include <fcntl.h>
+#include <unistd.h>
 #include <sys/types.h>
+#include <sys/sysctl.h>
+#include <sys/stat.h>
 #include <sys/event.h>
 #include <sys/time.h>
-#include <fcntl.h>
-#include <sys/ioctl.h>
-#include <signal.h>
-#include <unistd.h>
-#include <stdio.h>
-#include <string.h>
-#include <glib.h>
+#include <errno.h>
 #include "gam_error.h"
 #include "gam_kqueue.h"
-#include "gam_tree.h"
 #include "gam_event.h"
 #include "gam_server.h"
-#include "gam_event.h"
 
-typedef struct {
-    char *path;
-    int fd;
-    int refcount;
-    gboolean isdir;
-    GList *subs;
-    GSList *dirlist;
-} KQueueData;
+/*** tunable constants, modify to tweak the backend aggressivity *************/
 
-static GHashTable *dir_path_hash = NULL;
-static GHashTable *file_path_hash = NULL;
-static GHashTable *fd_hash = NULL;
+/*
+ * The backend will use at most n file descriptors, where n is the
+ * minimum value between (kern.maxfiles * CFG_GLOBAL_FILE_RESERVE_RATIO)
+ * and (kern.maxfilesperproc - CFG_SELF_FILE_RESERVE).
+ */
+#define CFG_GLOBAL_FILE_RESERVE_RATIO			0.7
+#define CFG_SELF_FILE_RESERVE				200
 
-static GSList *exist_list = NULL;
+/*
+ * If a SubMonitor or FileMonitor is not supported by kqueue and has
+ * to be polled, the backend will re-attempt to enable kqueue
+ * notification every n polls.
+ */
+#define CFG_UNSUPPORTED_SMON_KQUEUE_RETRY_FREQUENCY	10
+#define CFG_UNSUPPORTED_FMON_KQUEUE_RETRY_FREQUENCY	10
 
-static GList *new_subs = NULL;
-G_LOCK_DEFINE_STATIC(new_subs);
-static GList *removed_subs = NULL;
-G_LOCK_DEFINE_STATIC(removed_subs);
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
 
-G_LOCK_DEFINE_STATIC(kqueue);
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
 
-static gboolean have_consume_idler = FALSE;
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
 
-int kq = -1;
+typedef enum
+{
+  MONITOR_ISDIR		= 1 << 0,
+  MONITOR_ISNOTDIR	= 1 << 1
+} MonitorFlags;
+#define MONITOR_FLAGS_SHIFT	2
 
-static KQueueData *
-gam_kqueue_data_new(const char *path, int fd)
+/* monitor for Gamin subscriptions */
+typedef struct
 {
-    KQueueData *data;
+  Monitor	base;
+  GList		*subs;
+  HashTable	*fmons;			/* FileMonitor objects */
+  HashTable	*unsupported_fmons;	/* subset of fmons to poll */
+  gboolean	isdir;			/* is a directory subscription? */
+} SubMonitor;
+#define SUB_MONITOR(ptr)	((SubMonitor *) ptr)
 
-    data = g_new0(KQueueData, 1);
-    data->path = g_strdup(path);
-    data->fd = fd;
-    data->refcount = 1;
-    data->isdir = FALSE;
-    data->subs = NULL;
-    data->dirlist = NULL;
+typedef enum
+{
+  SUB_MONITOR_WAS_MISSING		= 1 << MONITOR_FLAGS_SHIFT
+} SubMonitorFlags;
 
-    return data;
-}
+/* monitor for files within directory subscriptions */
+typedef struct
+{
+  Monitor	base;
+  SubMonitor	*smon;		/* the SubMonitor this fmon belongs to */
+  char		*filename;	/* pointer into base.pathname */
+} FileMonitor;
+#define FILE_MONITOR(ptr)	((FileMonitor *) ptr)
 
-static GSList *
-gam_kqueue_lsdir(const char *path)
+typedef enum
 {
-    GDir *dir;
-    GSList *lst = NULL;
-    const gchar *entry;
+  FILE_MONITOR_POSSIBLY_RECREATED	= 1 << MONITOR_FLAGS_SHIFT
+} FileMonitorFlags;
 
-    if (!path)
-        return NULL;
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
 
-    dir = g_dir_open(path, 0, NULL);
-    if (!dir)
-        return NULL;
+/*** helpers *****************************************************************/
 
-    entry = g_dir_read_name(dir);
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
 
-    while (entry) {
-        lst = g_slist_prepend(lst, g_strdup(entry));
-        entry = g_dir_read_name(dir);
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
     }
+}
 
-    g_dir_close(dir);
+static gboolean
+gam_kqueue_get_uint_sysctl (const char *name, unsigned int *value)
+{
+  unsigned int value_len = sizeof(*value);
 
-    return lst;
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
 }
 
 static void
-gam_kqueue_cmplst(GSList *lst1, GSList *lst2, GSList **added, GSList **deleted)
+gam_kqueue_hash_table_default_add_cb (GHashTable *table,
+				      gpointer item,
+				      gpointer user_data)
 {
-    int found;
-    GSList *l;
+  g_hash_table_insert(table, item, GINT_TO_POINTER(TRUE));
+}
 
-    if (!lst1 && !lst2)
-        return;
+static void
+gam_kqueue_hash_table_default_remove_cb (GHashTable *table,
+					 gpointer item,
+					 gpointer user_data)
+{
+  g_hash_table_remove(table, item);
+}
 
-    if (!lst1) {
-        *added = g_slist_copy(lst2);
-        return;
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
     }
+}
 
-    if (!lst2) {
-        *deleted = g_slist_copy(lst1);
-        return;
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
     }
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
 
-    for (l = lst1; l; l = l->next) {
-        found = 0;
-        if (g_slist_find_custom(lst2, l->data, (GCompareFunc)strcmp)) {
-            found = 1;
-        }
-        if (found == 0) {
-            *deleted = g_slist_prepend(*deleted, l->data);
-        }
+      for (l = table->pending_additions; l != NULL; l = l->next)
+	table->methods->add(table->main, l->data, table->user_data);
+
+      g_slist_free(table->pending_additions);
+      table->pending_additions = NULL;
+
+      if (table->methods->post_add)
+	table->methods->post_add(table->main, table->user_data);
     }
 
-    for (l = lst2; l; l = l->next) {
-        found = 0;
-        if (g_slist_find_custom(lst1, l->data, (GCompareFunc)strcmp)) {
-            found = 1;
-        }
-        if (found == 0) {
-            *added = g_slist_prepend(*added, l->data);
-        }
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
     }
 }
 
 static void
-gam_kqueue_data_free(KQueueData * data)
+gam_kqueue_hash_table_destroy (HashTable *table)
 {
-    g_free(data->path);
-    if (data->dirlist) {
-        g_slist_foreach(data->dirlist, (GFunc)g_free, NULL);
-        g_slist_free(data->dirlist);
-    }
-    if (data->subs) {
-	g_list_free(data->subs);
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
     }
-    g_free(data);
 }
 
 static void
-gam_kqueue_add_rm_handler(const char *path, GamSubscription *sub, gboolean added, gboolean was_missing)
+gam_kqueue_poller_add_sub_monitor (Poller *poller, SubMonitor *smon)
+{
+  gam_kqueue_hash_table_add(poller->smons, smon);
+}
+
+static void
+gam_kqueue_poller_remove_sub_monitor (Poller *poller, SubMonitor *smon)
 {
-    KQueueData *data;
-    struct kevent ev[1];
-    int isdir = 0;
-    int fd;
+  gam_kqueue_hash_table_remove(poller->smons, smon);
+}
 
-    G_LOCK(kqueue);
+/*** Monitor *****************************************************************/
 
-    isdir = g_file_test(path, G_FILE_TEST_IS_DIR);
-    if (gam_subscription_is_dir(sub)) {
-        data = g_hash_table_lookup(dir_path_hash, path);
+static gboolean
+gam_kqueue_monitor_enable_kqueue (Monitor *mon)
+{
+  struct kevent ev[1];
+
+  if (open_files == max_open_files)
+    {
+      GAM_DEBUG(DEBUG_INFO, "cannot open %s (max_open_files limit reached), falling back to poll\n", mon->pathname);
+      return FALSE;
     }
-    else {
-        data = g_hash_table_lookup(file_path_hash, path);
+  
+  mon->fd = open(mon->pathname, O_RDONLY | O_NOFOLLOW);
+  if (mon->fd < 0)
+    {
+      GAM_DEBUG(DEBUG_INFO, "cannot open %s (%s), falling back to poll\n", mon->pathname, g_strerror(errno));
+      return FALSE;
     }
 
-    if (added) {
-	GList *subs;
+  EV_SET(ev, mon->fd, EVFILT_VNODE, EV_ADD | EV_ENABLE | EV_CLEAR, VN_NOTE_ALL, 0, mon);
+  if (kevent(kq, ev, G_N_ELEMENTS(ev), NULL, 0, NULL) < 0)
+    {
+      GAM_DEBUG(DEBUG_INFO, "cannot enable kqueue notification for %s (%s), falling back to poll\n", mon->pathname, g_strerror(errno));
 
-	subs = NULL;
-	subs = g_list_append(subs, sub);
+      close(mon->fd);
+      mon->fd = -1;
 
-        if (data != NULL) {
-            data->refcount++;
-	    data->subs = g_list_prepend(data->subs, sub);
-            G_UNLOCK(kqueue);
-	    GAM_DEBUG(DEBUG_INFO, "kqueue updated refcount\n");
-	    if (!was_missing) {
-	        gam_server_emit_event (path, isdir, GAMIN_EVENT_EXISTS, subs, 1);
-                gam_server_emit_event (path, isdir, GAMIN_EVENT_ENDEXISTS, subs, 1);
-	    }
-	    else {
-                gam_server_emit_event (path, isdir, GAMIN_EVENT_CREATED, subs, 1);
-	    }
-            return;
-        }
+      return FALSE;
+    }
 
-	if (!g_file_test(path, G_FILE_TEST_EXISTS)) {
-	    data = gam_kqueue_data_new(path, -1);
-	    data->subs = g_list_prepend(data->subs, sub);
-            exist_list = g_slist_append(exist_list, data);
-	    gam_server_emit_event (path, isdir, GAMIN_EVENT_DELETED, subs, 1);
-	    gam_server_emit_event (path, isdir, GAMIN_EVENT_ENDEXISTS, subs, 1);
-	    G_UNLOCK(kqueue);
-	    return;
-	}
+  open_files++;
+  return TRUE;
+}
 
-	fd = open(path, O_RDONLY);
+static void
+gam_kqueue_monitor_set_unsupported (Monitor *mon)
+{
+  if (mon->fd >= 0)
+    {
+      close(mon->fd);
+      mon->fd = -1;
 
-	if (fd < 0) {
-            G_UNLOCK(kqueue);
-	    return;
-	}
+      open_files--;
+    }
 
-        EV_SET(ev, fd, EVFILT_VNODE,
-            EV_ADD | EV_ENABLE | EV_CLEAR, VN_NOTE_ALL, 0, 0);
-        kevent(kq, ev, 1, NULL, 0, NULL);
+  gam_kqueue_mini_lstat(mon->pathname, &mon->sb);
+}
 
-        data = gam_kqueue_data_new(path, fd);
-        data->subs = g_list_prepend(data->subs, sub);
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
 
-	if (!was_missing) {
-            gam_server_emit_event (path, isdir, GAMIN_EVENT_EXISTS, subs, 1);
-	}
-	else {
-            gam_server_emit_event (path, isdir, GAMIN_EVENT_CREATED, subs, 1);
-	}
-        if (gam_subscription_is_dir(sub) && isdir) {
-	    GSList *l;
+/*** SubMonitor **************************************************************/
 
-            data->isdir = TRUE;
-            data->dirlist = gam_kqueue_lsdir(path);
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
 
-	    for (l = data->dirlist; l; l = l->next) {
-                char *tmpentry;
+static SubMonitor *
+gam_kqueue_sub_monitor_new (GamSubscription *sub)
+{
+  SubMonitor *smon;
+  Monitor *mon;
 
-                tmpentry = g_build_filename(path, l->data, NULL);
-		if (!was_missing) {
-		    gam_server_emit_event (tmpentry,
-                        g_file_test(tmpentry, G_FILE_TEST_IS_DIR),
-		        GAMIN_EVENT_EXISTS, subs, 1);
-		}
-		g_free(tmpentry);
-	    }
-	}
+  smon = g_new0(SubMonitor, 1);
 
-	if (!was_missing) {
-	    gam_server_emit_event (path, isdir, GAMIN_EVENT_ENDEXISTS, subs, 1);
-	}
+  mon = MONITOR(smon);
+  mon->handle_kevent = gam_kqueue_sub_monitor_handle_kevent;
+  mon->pathname = g_strdup(gam_subscription_get_path(sub));
+  mon->fd = -1;
 
-        g_hash_table_insert(fd_hash, GINT_TO_POINTER(data->fd), data);
-	if (data->isdir) {
-            g_hash_table_insert(dir_path_hash, data->path, data);
-	}
-	else {
-            g_hash_table_insert(file_path_hash, data->path, data);
-	}
+  smon->isdir = gam_subscription_is_dir(sub);
+  gam_kqueue_sub_monitor_init_fmons(smon);
 
-	if (subs)
-            g_list_free(subs);
+  return smon;
+}
 
-        GAM_DEBUG(DEBUG_INFO, "added kqueue watch for %s\n", path);
-    } else {
+static void
+gam_kqueue_sub_monitor_clear_fmons (SubMonitor *smon)
+{
+  if (g_hash_table_size(smon->unsupported_fmons->main) > 0)
+    gam_kqueue_poller_remove_sub_monitor(&unsupported_fmon_poller, smon);
 
-        if (!data) {
-            G_UNLOCK(kqueue);
-            return;
-        }
+  gam_kqueue_hash_table_destroy(smon->unsupported_fmons);
+  gam_kqueue_hash_table_destroy(smon->fmons);
+}
 
-	if (g_list_find (data->subs, sub)) {
-		data->subs = g_list_remove_all (data->subs, sub);
-	}
-        data->refcount--;
-	    GAM_DEBUG(DEBUG_INFO, "kqueue decremeneted refcount for %s\n", path);
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
 
-        if (data->refcount == 0) {
-            GList *l;
+static void
+gam_kqueue_sub_monitor_add_fmon_cb (GHashTable *table,
+				    FileMonitor *fmon,
+				    SubMonitor *smon)
+{
+  g_hash_table_replace(table, fmon->filename, fmon);
+}
 
-	    close(data->fd);
-            l = data->subs;
-            for (l = l; l; l = l->next) {
-                GamSubscription *sub = l->data;
-                gam_kqueue_remove_subscription (sub);
-            }
-            GAM_DEBUG(DEBUG_INFO, "removed kqueue watch for %s\n", data->path);
-	    if (data->isdir) {
-                g_hash_table_remove(dir_path_hash, data->path);
-	    }
-	    else {
-		g_hash_table_remove(file_path_hash, data->path);
-	    }
-            g_hash_table_remove(fd_hash, GINT_TO_POINTER(data->fd));
-            gam_kqueue_data_free(data);
-        }
-    }
-    G_UNLOCK(kqueue);
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
 }
 
-static GaminEventType kqueue_event_to_gamin_event (int mask)
+static void
+gam_kqueue_sub_monitor_post_remove_unsupported_fmon_cb (GHashTable *table,
+							SubMonitor *smon)
 {
-	if ((mask & VN_NOTE_CHANGED) != 0)
-		return GAMIN_EVENT_CHANGED;
-	else if ((mask & NOTE_DELETE) != 0)
-		return GAMIN_EVENT_DELETED;
-	else if ((mask & NOTE_REVOKE) != 0)
-		return GAMIN_EVENT_ENDEXISTS;
-	else if ((mask & NOTE_RENAME) != 0)
-		return GAMIN_EVENT_MOVED;
-	else
-		return GAMIN_EVENT_UNKNOWN;
+  if (g_hash_table_size(table) == 0)
+    gam_kqueue_poller_remove_sub_monitor(&unsupported_fmon_poller, smon);
 }
 
-static void gam_kqueue_emit_event (KQueueData *data, struct kevent *event)
+static void
+gam_kqueue_sub_monitor_set_missing (SubMonitor *smon)
 {
-	GaminEventType gevent;
-	int isdir = 0;
-	char *event_path;
+  Monitor *mon = MONITOR(smon);
 
-	if (!data||!event)
-		return;
+  if (mon->fd >= 0)
+    {
+      close(mon->fd);
+      mon->fd = -1;
 
-	gevent = kqueue_event_to_gamin_event (event->fflags);
+      open_files--;
+    }
 
-	if (gevent == GAMIN_EVENT_UNKNOWN) {
-		return;
-	}
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
 
-	isdir = g_file_test(data->path, G_FILE_TEST_IS_DIR);
+  gam_kqueue_poller_remove_sub_monitor(&unsupported_smon_poller, smon);
+  gam_kqueue_poller_add_sub_monitor(&missing_smon_poller, smon);
+}
 
-	if (gevent == GAMIN_EVENT_CHANGED && data->isdir) {
-	    GSList *dirlist = NULL, *added = NULL, *deleted = NULL;
-	    GSList *l;
-
-	    dirlist = gam_kqueue_lsdir(data->path);
-	    gam_kqueue_cmplst(data->dirlist, dirlist, &added, &deleted);
-	    if (added || deleted) {
-	        for (l = deleted; l; l = l->next) {
-                    data->dirlist = g_slist_remove(data->dirlist, l->data);
-		    event_path = g_build_filename(data->path, l->data, NULL);
-		    g_free(l->data);
-		    isdir = g_file_test(event_path, G_FILE_TEST_IS_DIR);
-
-                    GAM_DEBUG(DEBUG_INFO, "kqueue emitting event %s for %s\n", gam_event_to_string(GAMIN_EVENT_DELETED) , event_path);
-
-                    gam_server_emit_event (event_path, isdir,
-                        GAMIN_EVENT_DELETED, data->subs, 1);
-		    g_free(event_path);
-		}
+static void
+gam_kqueue_sub_monitor_set_unsupported (SubMonitor *smon)
+{
+  Monitor *mon = MONITOR(smon);
 
-		for (l = added; l; l = l->next) {
-                    dirlist = g_slist_remove(dirlist, l->data);
-		    data->dirlist = g_slist_prepend(data->dirlist,
-                        g_strdup(l->data));
-		    event_path = g_build_filename(data->path, l->data, NULL);
-		    g_free(l->data);
-		    isdir = g_file_test(event_path, G_FILE_TEST_IS_DIR);
-
-		    GAM_DEBUG(DEBUG_INFO, "kqueue emitting event %s for %s\n", gam_event_to_string(GAMIN_EVENT_CREATED) , event_path);
-
-		    gam_server_emit_event (event_path, isdir,
-                        GAMIN_EVENT_CREATED, data->subs, 1);
-		    g_free(event_path);
-		}
+  gam_kqueue_monitor_set_unsupported(mon);
+  gam_kqueue_poller_add_sub_monitor(&unsupported_smon_poller, smon);
+}
 
-		if (added)
-                  g_slist_free(added);
-		if (deleted)
-                  g_slist_free(deleted);
-	    }
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
 
-	    if (dirlist) {
-	        g_slist_foreach(dirlist, (GFunc)g_free, NULL);
-	        g_slist_free(dirlist);
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
 	    }
-            return;
-	}
-	else {
-	    event_path = g_strdup (data->path);
 	}
 
-        isdir = g_file_test(event_path, G_FILE_TEST_IS_DIR);
+      if ((flags & SUB_MONITOR_WAS_MISSING) == 0)
+	gam_kqueue_sub_monitor_emit_event(smon, GAMIN_EVENT_ENDEXISTS, flags);
+    }
+  else
+    {
+      gam_kqueue_sub_monitor_emit_event(smon, GAMIN_EVENT_DELETED, flags);
+      gam_kqueue_sub_monitor_emit_event(smon, GAMIN_EVENT_ENDEXISTS, flags);
 
-	GAM_DEBUG(DEBUG_INFO, "kqueue emitting event %s for %s\n", gam_event_to_string(gevent) , event_path);
+      return;
+    }
+    
+  /* then we enable kqueue notification, falling back to poll if necessary */
 
-	gam_server_emit_event (event_path, isdir, gevent, data->subs, 1);
+  if (! gam_kqueue_monitor_enable_kqueue(mon))
+    gam_kqueue_sub_monitor_set_unsupported(smon);
+}
 
-	g_free (event_path);
+static void
+gam_kqueue_sub_monitor_handle_directory_change_removal_cb (const char *filename,
+							   FileMonitor *fmon,
+							   GHashTable *filenames)
+{
+  if (! g_hash_table_lookup(filenames, filename))
+    gam_kqueue_file_monitor_emit_event(fmon, GAMIN_EVENT_DELETED, MONITOR_ISNOTDIR);
 }
 
-static gboolean
-gam_kqueue_exist_check (gpointer user_data)
+static void
+gam_kqueue_sub_monitor_handle_directory_change (SubMonitor *smon,
+						gboolean isdir)
 {
-    GSList *l, *tmplst;
-    KQueueData *data;
+  Monitor *mon = MONITOR(smon);
+  GHashTable *filenames;
 
-    tmplst = g_slist_copy(exist_list);
+  filenames = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, NULL);
 
-    for (l = tmplst; l; l = l->next) {
-        data = l->data;
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
 
-	if (g_file_test(data->path, G_FILE_TEST_EXISTS)) {
-            /* The subs list is guaranteed to have only one entry. */
-            GamSubscription *sub = data->subs->data;
+  /*
+   * Handle deleted files (they are also handled at the FileMonitor
+   * level, but we must use whichever event comes first).
+   */
+  gam_kqueue_hash_table_foreach(smon->fmons, (GHFunc) gam_kqueue_sub_monitor_handle_directory_change_removal_cb, filenames);
+  g_hash_table_destroy(filenames);
+}
 
-            exist_list = g_slist_remove(exist_list, data);
-	    gam_kqueue_add_rm_handler(data->path, sub, TRUE, TRUE);
-	    gam_kqueue_data_free(data);
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
 	}
+      break;
+
+    case GAMIN_EVENT_DELETED:
+    case GAMIN_EVENT_MOVED:
+      gam_kqueue_sub_monitor_set_missing(smon);
+      break;
     }
 
-    if (tmplst)
-        g_slist_free(tmplst);
+  gam_server_emit_event(mon->pathname, isdir, event, smon->subs, 1);
+}
 
-    return TRUE;
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
 }
 
-static gboolean
-gam_kqueue_event_handler (gpointer user_data)
+/*** FileMonitor *************************************************************/
+
+static void
+gam_kqueue_file_monitor_set_unsupported (FileMonitor *fmon)
 {
-    KQueueData *data;
-    struct kevent ev[1];
-    struct timespec timeout = { 0, 0 };
-    int fd, i, nevents;
-
-    G_LOCK(kqueue);
-
-    GAM_DEBUG(DEBUG_INFO, "gam_kqueue_event_handler()\n");
-
-    nevents = kevent(kq, NULL, 0, ev, 1, &timeout);
-    if (nevents == -1)
-        return FALSE;
-    for (i = 0; i < nevents; i++) {
-        fd = ev[i].ident;
-
-	data = g_hash_table_lookup (fd_hash, GINT_TO_POINTER(fd));
-	if (!data) {
-	    GAM_DEBUG(DEBUG_INFO, "kqueue can't find fd %d\n", fd);
-	    GAM_DEBUG(DEBUG_INFO, "weird things have happened to kqueue.\n");
-	} else {
-	    gam_kqueue_emit_event (data, &ev[i]);
-	}
+  Monitor *mon = MONITOR(fmon);
 
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
     }
 
-    G_UNLOCK(kqueue);
+  return fmon;
+}
 
-    return TRUE;
+static void
+gam_kqueue_file_monitor_free (FileMonitor *fmon)
+{
+  gam_kqueue_monitor_free(MONITOR(fmon));
 }
 
-static gboolean
-gam_kqueue_consume_subscriptions_real(gpointer data)
+static void
+gam_kqueue_file_monitor_emit_event (FileMonitor *fmon,
+				    GaminEventType event,
+				    FileMonitorFlags flags)
 {
-	GList *subs, *l;
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
 
-	G_LOCK(new_subs);
-	if (new_subs) {
-		subs = new_subs;
-		new_subs = NULL;
-		G_UNLOCK(new_subs);
-
-		for (l = subs; l; l = l->next) {
-			GamSubscription *sub = l->data;
-			GAM_DEBUG(DEBUG_INFO, "called gam_kqueue_add_handler()\n");
-			gam_kqueue_add_rm_handler (gam_subscription_get_path (sub), sub, TRUE, FALSE);
-		}
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
 
-	} else {
-		G_UNLOCK(new_subs);
-	}
+	      new_fmon = gam_kqueue_file_monitor_new(fmon->smon, fmon->filename, &new_fmon_flags);
+	      gam_kqueue_file_monitor_emit_event(new_fmon, GAMIN_EVENT_CREATED, new_fmon_flags);
 
-	G_LOCK(removed_subs);
-	if (removed_subs) {
-		subs = removed_subs;
-		removed_subs = NULL;
-		G_UNLOCK(removed_subs);
-
-		for (l = subs; l; l = l->next) {
-			GamSubscription *sub = l->data;
-			GAM_DEBUG(DEBUG_INFO, "called gam_kqueue_rm_handler()\n");
-			gam_kqueue_add_rm_handler (gam_subscription_get_path (sub), sub, FALSE, FALSE);
-		}
-	} else {
-		G_UNLOCK(removed_subs);
+	      break;		/* do not remove the fmon we've just created */
+	    }
 	}
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
 
-	GAM_DEBUG(DEBUG_INFO, "gam_kqueue_consume_subscriptions()\n");
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
 
-	have_consume_idler = FALSE;
-	return FALSE;
+  if (lstat(MONITOR(smon)->pathname, &sb) >= 0)
+    {
+      gam_kqueue_poller_remove_sub_monitor(&missing_smon_poller, smon);
+      gam_kqueue_sub_monitor_enable_notification(smon, SUB_MONITOR_WAS_MISSING | ((sb.st_mode & S_IFDIR) != 0 ? MONITOR_ISDIR : MONITOR_ISNOTDIR));
+    }
 }
 
 static void
-gam_kqueue_consume_subscriptions(void)
+gam_kqueue_unsupported_smon_poll (SubMonitor *smon)
 {
-	GSource *source;
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
 
-	if (have_consume_idler)
-		return;
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
 
-	have_consume_idler = TRUE;
+  gam_kqueue_mini_lstat(mon->pathname, &sb);
 
-	source = g_idle_source_new ();
-	g_source_set_callback (source, gam_kqueue_consume_subscriptions_real, NULL, NULL);
+  if (! sb.exists && mon->sb.exists)
+    event = GAMIN_EVENT_DELETED;
+  else if (gam_kqueue_differs(&sb, &mon->sb))
+    event = GAMIN_EVENT_CHANGED;
+  else
+    return;
 
-	g_source_attach (source, NULL);
+  memcpy(&mon->sb, &sb, sizeof(sb));
+  gam_kqueue_file_monitor_emit_event(fmon, event, (sb.mode & S_IFDIR) != 0 ? MONITOR_ISDIR : MONITOR_ISNOTDIR);
 }
 
-/**
- * @defgroup kqueue kqueue backend
- * @ingroup Backends
- * @brief kqueue backend API
- *
- * Since 4.1, FreeBSD kernels have included the kernel event notification
- * machanism (kqueue).  This backend uses kqueue to know when
- * files are changed/created/deleted.
- *
- * @{
- */
+static void
+gam_kqueue_unsupported_fmon_poll (SubMonitor *smon)
+{
+  gam_kqueue_hash_table_foreach(smon->unsupported_fmons, (GHFunc) gam_kqueue_unsupported_fmon_poll_foreach_cb, NULL);
+}
 
+/*** Gamin backend implementation ********************************************/
 
 /**
  * Initializes the kqueue system.  This must be called before
@@ -526,28 +1118,58 @@
  * @returns TRUE if initialization succeeded, FALSE otherwise
  */
 gboolean
-gam_kqueue_init(void)
+gam_kqueue_init (void)
 {
-    kq = kqueue();
-    if (kq == -1) {
-	GAM_DEBUG(DEBUG_INFO, "Could not initialize a new kqueue\n");
-	return FALSE;
+  GIOChannel *channel;
+  unsigned int maxfiles;
+  unsigned int maxfilesperproc;
+
+  kq = kqueue();
+  if (kq < 0)
+    {
+      gam_error(DEBUG_INFO, "kqueue initialization failure: %s\n", g_strerror(errno));
+      return FALSE;
     }
 
-    g_timeout_add(1000, gam_kqueue_exist_check, NULL);
-    g_timeout_add(1000, gam_kqueue_event_handler, NULL);
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
 
-    dir_path_hash = g_hash_table_new(g_str_hash, g_str_equal);
-    file_path_hash = g_hash_table_new(g_str_hash, g_str_equal);
-    fd_hash = g_hash_table_new(g_direct_hash, g_direct_equal);
-
-    GAM_DEBUG(DEBUG_INFO, "kqueue initialized\n");
-
-    gam_backend_add_subscription = gam_kqueue_add_subscription;
-    gam_backend_remove_subscription = gam_kqueue_remove_subscription;
-    gam_backend_remove_all_for = gam_kqueue_remove_all_for;
-
-    return TRUE;
+  return TRUE;
 }
 
 /**
@@ -557,18 +1179,31 @@
  * @returns TRUE if adding the subscription succeeded, FALSE otherwise
  */
 gboolean
-gam_kqueue_add_subscription(GamSubscription * sub)
+gam_kqueue_add_subscription (GamSubscription *sub)
 {
-	gam_listener_add_subscription(gam_subscription_get_listener(sub), sub);
-
-	G_LOCK(new_subs);
-	new_subs = g_list_prepend(new_subs, sub);
-	G_UNLOCK(new_subs);
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
 
-	GAM_DEBUG(DEBUG_INFO, "kqueue_add_sub\n");
+  g_hash_table_insert(hash, MONITOR(smon)->pathname, smon);
+  gam_kqueue_sub_monitor_enable_notification(smon, 0);
 
-	gam_kqueue_consume_subscriptions();
-    return TRUE;
+  return TRUE;
 }
 
 /**
@@ -578,28 +1213,28 @@
  * @returns TRUE if removing the subscription succeeded, FALSE otherwise
  */
 gboolean
-gam_kqueue_remove_subscription(GamSubscription * sub)
+gam_kqueue_remove_subscription (GamSubscription *sub)
 {
-	G_LOCK(new_subs);
-	if (g_list_find(new_subs, sub)) {
-		GAM_DEBUG(DEBUG_INFO, "removed sub found on new_subs\n");
-		new_subs = g_list_remove_all (new_subs, sub);
-		G_UNLOCK(new_subs);
-		return TRUE;
-	}
-	G_UNLOCK(new_subs);
+  GHashTable *hash;
+  SubMonitor *smon;
 
-	gam_subscription_cancel (sub);
-	gam_listener_remove_subscription(gam_subscription_get_listener(sub), sub);
+  hash = gam_subscription_is_dir(sub) ? dir_hash : file_hash;
+  smon = g_hash_table_lookup(hash, gam_subscription_get_path(sub));
 
-	G_LOCK(removed_subs);
-	removed_subs = g_list_prepend (removed_subs, sub);
-	G_UNLOCK(removed_subs);
+  if (! smon)
+    return FALSE;
 
-	GAM_DEBUG(DEBUG_INFO, "kqueue_remove_sub\n");
-	gam_kqueue_consume_subscriptions();
+  smon->subs = g_list_remove_all(smon->subs, sub);
+  if (! smon->subs)
+    {
+      g_hash_table_remove(hash, MONITOR(smon)->pathname);
+      gam_kqueue_sub_monitor_free(smon);
+    }
 
-    return TRUE;
+  gam_subscription_cancel(sub);
+  gam_listener_remove_subscription(gam_subscription_get_listener(sub), sub);
+
+  return TRUE;
 }
 
 /**
@@ -609,28 +1244,19 @@
  * @returns TRUE if removing the subscriptions succeeded, FALSE otherwise
  */
 gboolean
-gam_kqueue_remove_all_for(GamListener * listener)
+gam_kqueue_remove_all_for (GamListener *listener)
 {
-	GList *subs, *l = NULL;
-
-	subs = gam_listener_get_subscriptions (listener);
-
-	for (l = subs; l; l = l->next) {
-		GamSubscription *sub = l->data;
-
-		g_assert (sub != NULL);
-
-		gam_kqueue_remove_subscription (sub);
-
-	}
-
-	if (subs) {
-		g_list_free (subs);
-		gam_kqueue_consume_subscriptions();
-		return TRUE;
-	} else {
-		return FALSE;
-	}
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
 }
-
-/** @} */
