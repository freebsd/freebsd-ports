--- server/gam_kqueue.c.orig	Wed Apr  6 22:46:40 2005
+++ server/gam_kqueue.c	Wed Apr  6 22:47:16 2005
@@ -0,0 +1,720 @@
+/*
+ * Copyright (C) 2005 Joe Marcus Clarke <marcus@FreeBSD.org>
+ * Copyright (C) 2005 Jean-Yves Lefort <jylefort@brutele.be>
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
+
+#include <config.h>
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <sys/event.h>
+#include <sys/time.h>
+#include <fcntl.h>
+#include <sys/ioctl.h>
+#include <signal.h>
+#include <unistd.h>
+#include <stdio.h>
+#include <string.h>
+#include <glib.h>
+#include "gam_error.h"
+#include "gam_kqueue.h"
+#include "gam_tree.h"
+#include "gam_event.h"
+#include "gam_server.h"
+#include "gam_event.h"
+
+typedef struct {
+    char *path;
+    int fd;
+    int refcount;
+    gboolean isdir;
+    GList *subs;
+    GSList *dirlist;
+} KQueueData;
+
+typedef struct
+{
+    ino_t ino;
+    mode_t mode;
+    uid_t uid;
+    gid_t gid;
+    time_t mtime;
+    time_t ctime;
+    off_t size;
+} MiniStat;
+
+typedef struct {
+    char *pathname;
+    char *filename;		/* pointer into pathname */
+    MiniStat sb;
+} FileData;
+  
+static GHashTable *dir_path_hash = NULL;
+static GHashTable *file_path_hash = NULL;
+static GHashTable *fd_hash = NULL;
+
+static GSList *exist_list = NULL;
+
+static GList *new_subs = NULL;
+G_LOCK_DEFINE_STATIC(new_subs);
+static GList *removed_subs = NULL;
+G_LOCK_DEFINE_STATIC(removed_subs);
+
+G_LOCK_DEFINE_STATIC(kqueue);
+
+static gboolean have_consume_idler = FALSE;
+
+int kq = -1;
+
+static KQueueData *
+gam_kqueue_data_new(const char *path, int fd)
+{
+    KQueueData *data;
+
+    data = g_new0(KQueueData, 1);
+    data->path = g_strdup(path);
+    data->fd = fd;
+    data->refcount = 1;
+    data->isdir = FALSE;
+    data->subs = NULL;
+    data->dirlist = NULL;
+
+    return data;
+}
+
+static void
+gam_kqueue_mini_stat (const char *pathname, MiniStat *mini_sb)
+{
+    struct stat sb;
+
+    if (lstat(pathname, &sb) == 0) {
+        mini_sb->ino = sb.st_ino;
+	mini_sb->mode = sb.st_mode;
+	mini_sb->uid = sb.st_uid;
+	mini_sb->gid = sb.st_gid;
+        mini_sb->mtime = sb.st_mtime;
+	mini_sb->ctime = sb.st_ctime;
+	mini_sb->size = sb.st_size;
+    } else {
+        memset(mini_sb, 0, sizeof(*mini_sb));
+    }
+}
+
+static FileData *
+gam_kqueue_file_data_new (const char *path, const char *filename)
+{
+    FileData *fdata;
+
+    fdata = g_new(FileData, 1);
+    fdata->pathname = g_build_filename(path, filename, NULL);
+    fdata->filename = strrchr(fdata->pathname, G_DIR_SEPARATOR);
+    fdata->filename = fdata->filename ? fdata->filename + 1 : fdata->pathname;
+    gam_kqueue_mini_stat(fdata->pathname, &fdata->sb);
+
+    return fdata;
+}
+
+static void
+gam_kqueue_file_data_free (FileData *fdata)
+{
+    g_free(fdata->pathname);
+    g_free(fdata);
+}
+
+static void
+gam_kqueue_data_free(KQueueData * data)
+{
+    g_free(data->path);
+    if (data->dirlist) {
+        g_slist_foreach(data->dirlist, (GFunc)gam_kqueue_file_data_free, NULL);
+        g_slist_free(data->dirlist);
+    }
+    if (data->subs) {
+	g_list_free(data->subs);
+    }
+    g_free(data);
+}
+
+static int
+gam_kqueue_dirlist_find (FileData *fdata, const char *filename)
+{
+    return strcmp(fdata->filename, filename);
+}
+
+static void
+gam_kqueue_add_rm_handler(const char *path, GamSubscription *sub, gboolean added, gboolean was_missing)
+{
+    KQueueData *data;
+    struct kevent ev[1];
+    int isdir = 0;
+    int fd;
+
+    G_LOCK(kqueue);
+
+    isdir = g_file_test(path, G_FILE_TEST_IS_DIR);
+    if (gam_subscription_is_dir(sub)) {
+        data = g_hash_table_lookup(dir_path_hash, path);
+    }
+    else {
+        data = g_hash_table_lookup(file_path_hash, path);
+    }
+
+    if (added) {
+	GList *subs;
+
+	subs = NULL;
+	subs = g_list_append(subs, sub);
+
+        if (data != NULL) {
+            data->refcount++;
+	    data->subs = g_list_prepend(data->subs, sub);
+            G_UNLOCK(kqueue);
+	    GAM_DEBUG(DEBUG_INFO, "kqueue updated refcount\n");
+	    if (!was_missing) {
+	        gam_server_emit_event (path, isdir, GAMIN_EVENT_EXISTS, subs, 1);
+                gam_server_emit_event (path, isdir, GAMIN_EVENT_ENDEXISTS, subs, 1);
+	    }
+	    else {
+                gam_server_emit_event (path, isdir, GAMIN_EVENT_CREATED, subs, 1);
+	    }
+            return;
+        }
+
+	if (!g_file_test(path, G_FILE_TEST_EXISTS)) {
+	    data = gam_kqueue_data_new(path, -1);
+	    data->subs = g_list_prepend(data->subs, sub);
+            exist_list = g_slist_append(exist_list, data);
+	    gam_server_emit_event (path, isdir, GAMIN_EVENT_DELETED, subs, 1);
+	    gam_server_emit_event (path, isdir, GAMIN_EVENT_ENDEXISTS, subs, 1);
+	    G_UNLOCK(kqueue);
+	    return;
+	}
+
+	fd = open(path, O_RDONLY);
+
+	if (fd < 0) {
+            G_UNLOCK(kqueue);
+	    return;
+	}
+
+        EV_SET(ev, fd, EVFILT_VNODE,
+            EV_ADD | EV_ENABLE | EV_CLEAR, VN_NOTE_ALL, 0, 0);
+        kevent(kq, ev, 1, NULL, 0, NULL);
+
+        data = gam_kqueue_data_new(path, fd);
+        data->subs = g_list_prepend(data->subs, sub);
+
+	if (!was_missing) {
+            gam_server_emit_event (path, isdir, GAMIN_EVENT_EXISTS, subs, 1);
+	}
+	else {
+            gam_server_emit_event (path, isdir, GAMIN_EVENT_CREATED, subs, 1);
+	}
+        if (gam_subscription_is_dir(sub) && isdir) {
+	    GDir *dir;
+
+            data->isdir = TRUE;
+	    data->dirlist = NULL;
+
+	    dir = g_dir_open(path, 0, NULL);
+	    if (dir) {
+	        const char *entry;
+
+		while ((entry = g_dir_read_name(dir))) {
+		    FileData *fdata;
+
+		    fdata = gam_kqueue_file_data_new(path, entry);
+		    data->dirlist = g_slist_prepend(data->dirlist, fdata);
+
+		    if (!was_missing) {
+		        gam_server_emit_event(fdata->pathname,
+					      g_file_test(fdata->pathname, G_FILE_TEST_IS_DIR),
+					      GAMIN_EVENT_EXISTS, subs, 1);
+		    }
+		}
+
+		g_dir_close(dir);
+	    }
+	}
+
+	if (!was_missing) {
+	    gam_server_emit_event (path, isdir, GAMIN_EVENT_ENDEXISTS, subs, 1);
+	}
+
+        g_hash_table_insert(fd_hash, GINT_TO_POINTER(data->fd), data);
+	if (data->isdir) {
+            g_hash_table_insert(dir_path_hash, data->path, data);
+	}
+	else {
+            g_hash_table_insert(file_path_hash, data->path, data);
+	}
+
+	if (subs)
+            g_list_free(subs);
+
+        GAM_DEBUG(DEBUG_INFO, "added kqueue watch for %s\n", path);
+    } else {
+
+        if (!data) {
+            G_UNLOCK(kqueue);
+            return;
+        }
+
+	if (g_list_find (data->subs, sub)) {
+		data->subs = g_list_remove_all (data->subs, sub);
+	}
+        data->refcount--;
+	    GAM_DEBUG(DEBUG_INFO, "kqueue decremeneted refcount for %s\n", path);
+
+        if (data->refcount == 0) {
+            GList *l;
+
+	    close(data->fd);
+            l = data->subs;
+            for (l = l; l; l = l->next) {
+                GamSubscription *sub = l->data;
+                gam_kqueue_remove_subscription (sub);
+            }
+            GAM_DEBUG(DEBUG_INFO, "removed kqueue watch for %s\n", data->path);
+	    if (data->isdir) {
+                g_hash_table_remove(dir_path_hash, data->path);
+	    }
+	    else {
+		g_hash_table_remove(file_path_hash, data->path);
+	    }
+            g_hash_table_remove(fd_hash, GINT_TO_POINTER(data->fd));
+            gam_kqueue_data_free(data);
+        }
+    }
+    G_UNLOCK(kqueue);
+}
+
+static GaminEventType kqueue_event_to_gamin_event (int mask)
+{
+	if ((mask & VN_NOTE_CHANGED) != 0)
+		return GAMIN_EVENT_CHANGED;
+	else if ((mask & NOTE_DELETE) != 0)
+		return GAMIN_EVENT_DELETED;
+	else if ((mask & NOTE_REVOKE) != 0)
+		return GAMIN_EVENT_ENDEXISTS;
+	else if ((mask & NOTE_RENAME) != 0)
+		return GAMIN_EVENT_MOVED;
+	else
+		return GAMIN_EVENT_UNKNOWN;
+}
+
+static void gam_kqueue_emit_event (KQueueData *data, struct kevent *event)
+{
+	GaminEventType gevent;
+	int isdir = 0;
+	char *event_path;
+
+	if (!data||!event)
+		return;
+
+	gevent = kqueue_event_to_gamin_event (event->fflags);
+
+	if (gevent == GAMIN_EVENT_UNKNOWN) {
+		return;
+	}
+
+	isdir = g_file_test(data->path, G_FILE_TEST_IS_DIR);
+
+	if (gevent == GAMIN_EVENT_CHANGED && data->isdir) {
+	    GSList *dirlist = NULL;
+	    GSList *l;
+	    GDir *dir;
+
+	    dir = g_dir_open(data->path, 0, NULL);
+	    if (dir) {
+	        const char *entry;
+
+		while ((entry = g_dir_read_name(dir))) {
+		    dirlist = g_slist_prepend(dirlist, g_strdup(entry));
+		}
+
+		g_dir_close(dir);
+	    }
+
+	    for (l = dirlist; l; l = l->next) {
+	        if (! g_slist_find_custom(data->dirlist, l->data, (GCompareFunc) gam_kqueue_dirlist_find)) {
+		    FileData *fdata;
+
+		    fdata = gam_kqueue_file_data_new(data->path, l->data);
+		    data->dirlist = g_slist_prepend(data->dirlist, fdata);
+
+		    GAM_DEBUG(DEBUG_INFO, "kqueue emitting event %s for %s\n", gam_event_to_string(GAMIN_EVENT_CREATED), fdata->pathname);
+		    gam_server_emit_event(fdata->pathname,
+					  g_file_test(fdata->pathname, G_FILE_TEST_IS_DIR),
+					  GAMIN_EVENT_CREATED, data->subs, 1);
+		}
+	    }
+
+	iterate:
+	    for (l = data->dirlist; l; l = l->next) {
+	        FileData *fdata = l->data;
+
+	        if (! g_slist_find_custom(dirlist, fdata->filename, (GCompareFunc) strcmp)) {
+		    data->dirlist = g_slist_remove(data->dirlist, fdata);
+
+                    GAM_DEBUG(DEBUG_INFO, "kqueue emitting event %s for %s\n", gam_event_to_string(GAMIN_EVENT_DELETED), fdata->pathname);
+		    gam_server_emit_event(fdata->pathname,
+					  g_file_test(fdata->pathname, G_FILE_TEST_IS_DIR),
+					  GAMIN_EVENT_DELETED, data->subs, 1);
+
+		    gam_kqueue_file_data_free(fdata);
+		    goto iterate; /* list changed, start again */
+		}
+	    }
+
+	    if (dirlist) {
+	        g_slist_foreach(dirlist, (GFunc)g_free, NULL);
+	        g_slist_free(dirlist);
+	    }
+            return;
+	}
+	else {
+	    event_path = g_strdup (data->path);
+
+	    if (gevent == GAMIN_EVENT_DELETED
+		|| gevent == GAMIN_EVENT_ENDEXISTS
+		|| gevent == GAMIN_EVENT_MOVED) {
+	      /* close and move to exist_list, to catch next creation */
+	      close(data->fd);
+	      if (data->isdir) {
+		  g_hash_table_remove(dir_path_hash, data->path);
+	      }
+	      else {
+		  g_hash_table_remove(file_path_hash, data->path);
+	      }
+	      g_hash_table_remove(fd_hash, GINT_TO_POINTER(data->fd));
+
+	      exist_list = g_slist_append(exist_list, data);
+	    }
+	}
+
+        isdir = g_file_test(event_path, G_FILE_TEST_IS_DIR);
+
+	GAM_DEBUG(DEBUG_INFO, "kqueue emitting event %s for %s\n", gam_event_to_string(gevent) , event_path);
+
+	gam_server_emit_event (event_path, isdir, gevent, data->subs, 1);
+
+	g_free (event_path);
+}
+
+static gboolean
+gam_kqueue_exist_check (gpointer user_data)
+{
+    GSList *l, *tmplst;
+    KQueueData *data;
+
+    tmplst = g_slist_copy(exist_list);
+
+    for (l = tmplst; l; l = l->next) {
+        data = l->data;
+
+	if (g_file_test(data->path, G_FILE_TEST_EXISTS)) {
+            /* The subs list is guaranteed to have only one entry. */
+            GamSubscription *sub = data->subs->data;
+
+            exist_list = g_slist_remove(exist_list, data);
+	    gam_kqueue_add_rm_handler(data->path, sub, TRUE, TRUE);
+	    gam_kqueue_data_free(data);
+	}
+    }
+
+    if (tmplst)
+        g_slist_free(tmplst);
+
+    return TRUE;
+}
+
+static void
+gam_kqueue_dirlist_check_cb (const char *path, KQueueData *data, gpointer user_data)
+{
+    GSList *l;
+
+    for (l = data->dirlist; l; l = l->next) {
+        FileData *fdata = l->data;
+	MiniStat sb;
+
+	gam_kqueue_mini_stat(fdata->pathname, &sb);
+
+	if (sb.mtime != fdata->sb.mtime
+	    || sb.ctime != fdata->sb.ctime
+	    || sb.size != fdata->sb.size
+	    || sb.mode != fdata->sb.mode
+	    || sb.uid != fdata->sb.uid
+	    || sb.gid != fdata->sb.gid
+	    || sb.ino != fdata->sb.ino)
+	  {
+	      memcpy(&fdata->sb, &sb, sizeof(sb));
+
+	      GAM_DEBUG(DEBUG_INFO, "kqueue emitting event %s for %s\n", gam_event_to_string(GAMIN_EVENT_CHANGED), fdata->pathname);
+	      gam_server_emit_event(fdata->pathname,
+				    g_file_test(fdata->pathname, G_FILE_TEST_IS_DIR),
+				    GAMIN_EVENT_CHANGED, data->subs, 1);
+	  }
+    }
+}
+
+static gboolean
+gam_kqueue_dirlist_check (gpointer user_data)
+{
+    G_LOCK(kqueue);
+
+    GAM_DEBUG(DEBUG_INFO, "gam_kqueue_dirlist_check()\n");
+
+    g_hash_table_foreach(dir_path_hash, (GHFunc) gam_kqueue_dirlist_check_cb, NULL);
+
+    G_UNLOCK(kqueue);
+
+    return TRUE;
+}
+
+static gboolean
+gam_kqueue_event_handler (GIOChannel *source, GIOCondition condition, gpointer user_data)
+{
+    KQueueData *data;
+    struct kevent ev[1];
+    struct timespec timeout = { 0, 0 };
+    int fd, i, nevents;
+
+    G_LOCK(kqueue);
+
+    GAM_DEBUG(DEBUG_INFO, "gam_kqueue_event_handler()\n");
+
+    nevents = kevent(kq, NULL, 0, ev, 1, &timeout);
+    if (nevents == -1)
+        return FALSE;
+    for (i = 0; i < nevents; i++) {
+        fd = ev[i].ident;
+
+	data = g_hash_table_lookup (fd_hash, GINT_TO_POINTER(fd));
+	if (!data) {
+	    GAM_DEBUG(DEBUG_INFO, "kqueue can't find fd %d\n", fd);
+	    GAM_DEBUG(DEBUG_INFO, "weird things have happened to kqueue.\n");
+	} else {
+	    gam_kqueue_emit_event (data, &ev[i]);
+	}
+
+    }
+
+    G_UNLOCK(kqueue);
+
+    return TRUE;
+}
+
+static gboolean
+gam_kqueue_consume_subscriptions_real(gpointer data)
+{
+	GList *subs, *l;
+
+	G_LOCK(new_subs);
+	if (new_subs) {
+		subs = new_subs;
+		new_subs = NULL;
+		G_UNLOCK(new_subs);
+
+		for (l = subs; l; l = l->next) {
+			GamSubscription *sub = l->data;
+			GAM_DEBUG(DEBUG_INFO, "called gam_kqueue_add_handler()\n");
+			gam_kqueue_add_rm_handler (gam_subscription_get_path (sub), sub, TRUE, FALSE);
+		}
+
+	} else {
+		G_UNLOCK(new_subs);
+	}
+
+	G_LOCK(removed_subs);
+	if (removed_subs) {
+		subs = removed_subs;
+		removed_subs = NULL;
+		G_UNLOCK(removed_subs);
+
+		for (l = subs; l; l = l->next) {
+			GamSubscription *sub = l->data;
+			GAM_DEBUG(DEBUG_INFO, "called gam_kqueue_rm_handler()\n");
+			gam_kqueue_add_rm_handler (gam_subscription_get_path (sub), sub, FALSE, FALSE);
+		}
+	} else {
+		G_UNLOCK(removed_subs);
+	}
+
+	GAM_DEBUG(DEBUG_INFO, "gam_kqueue_consume_subscriptions()\n");
+
+	have_consume_idler = FALSE;
+	return FALSE;
+}
+
+static void
+gam_kqueue_consume_subscriptions(void)
+{
+	GSource *source;
+
+	if (have_consume_idler)
+		return;
+
+	have_consume_idler = TRUE;
+
+	source = g_idle_source_new ();
+	g_source_set_callback (source, gam_kqueue_consume_subscriptions_real, NULL, NULL);
+
+	g_source_attach (source, NULL);
+}
+
+/**
+ * @defgroup kqueue kqueue backend
+ * @ingroup Backends
+ * @brief kqueue backend API
+ *
+ * Since 4.1, FreeBSD kernels have included the kernel event notification
+ * machanism (kqueue).  This backend uses kqueue to know when
+ * files are changed/created/deleted.
+ *
+ * @{
+ */
+
+
+/**
+ * Initializes the kqueue system.  This must be called before
+ * any other functions in this module.
+ *
+ * @returns TRUE if initialization succeeded, FALSE otherwise
+ */
+gboolean
+gam_kqueue_init(void)
+{
+    GIOChannel *channel;
+
+    kq = kqueue();
+    if (kq == -1) {
+	GAM_DEBUG(DEBUG_INFO, "Could not initialize a new kqueue\n");
+	return FALSE;
+    }
+
+    g_timeout_add(1000, gam_kqueue_exist_check, NULL);
+
+    channel = g_io_channel_unix_new(kq);
+    g_io_add_watch(channel, G_IO_IN, gam_kqueue_event_handler, NULL);
+
+    dir_path_hash = g_hash_table_new(g_str_hash, g_str_equal);
+    file_path_hash = g_hash_table_new(g_str_hash, g_str_equal);
+    fd_hash = g_hash_table_new(g_direct_hash, g_direct_equal);
+
+    /*
+     * gam_kqueue_dirlist_check() has to lstat() every file in every
+     * monitored directory. This can easily become an intensive task
+     * if a few large directories are monitored (for instance a mail
+     * checker monitoring a couple of MH folders), therefore we use a
+     * reasonable poll interval (6 seconds, same as FAM's default).
+     */
+    g_timeout_add(6000, gam_kqueue_dirlist_check, NULL);
+
+    GAM_DEBUG(DEBUG_INFO, "kqueue initialized\n");
+
+    gam_backend_add_subscription = gam_kqueue_add_subscription;
+    gam_backend_remove_subscription = gam_kqueue_remove_subscription;
+    gam_backend_remove_all_for = gam_kqueue_remove_all_for;
+
+    return TRUE;
+}
+
+/**
+ * Adds a subscription to be monitored.
+ *
+ * @param sub a #GamSubscription to be polled
+ * @returns TRUE if adding the subscription succeeded, FALSE otherwise
+ */
+gboolean
+gam_kqueue_add_subscription(GamSubscription * sub)
+{
+	gam_listener_add_subscription(gam_subscription_get_listener(sub), sub);
+
+	G_LOCK(new_subs);
+	new_subs = g_list_prepend(new_subs, sub);
+	G_UNLOCK(new_subs);
+
+	GAM_DEBUG(DEBUG_INFO, "kqueue_add_sub\n");
+
+	gam_kqueue_consume_subscriptions();
+    return TRUE;
+}
+
+/**
+ * Removes a subscription which was being monitored.
+ *
+ * @param sub a #GamSubscription to remove
+ * @returns TRUE if removing the subscription succeeded, FALSE otherwise
+ */
+gboolean
+gam_kqueue_remove_subscription(GamSubscription * sub)
+{
+	G_LOCK(new_subs);
+	if (g_list_find(new_subs, sub)) {
+		GAM_DEBUG(DEBUG_INFO, "removed sub found on new_subs\n");
+		new_subs = g_list_remove_all (new_subs, sub);
+		G_UNLOCK(new_subs);
+		return TRUE;
+	}
+	G_UNLOCK(new_subs);
+
+	gam_subscription_cancel (sub);
+	gam_listener_remove_subscription(gam_subscription_get_listener(sub), sub);
+
+	G_LOCK(removed_subs);
+	removed_subs = g_list_prepend (removed_subs, sub);
+	G_UNLOCK(removed_subs);
+
+	GAM_DEBUG(DEBUG_INFO, "kqueue_remove_sub\n");
+	gam_kqueue_consume_subscriptions();
+
+    return TRUE;
+}
+
+/**
+ * Stop monitoring all subscriptions for a given listener.
+ *
+ * @param listener a #GamListener
+ * @returns TRUE if removing the subscriptions succeeded, FALSE otherwise
+ */
+gboolean
+gam_kqueue_remove_all_for(GamListener * listener)
+{
+	GList *subs, *l = NULL;
+
+	subs = gam_listener_get_subscriptions (listener);
+
+	for (l = subs; l; l = l->next) {
+		GamSubscription *sub = l->data;
+
+		g_assert (sub != NULL);
+
+		gam_kqueue_remove_subscription (sub);
+
+	}
+
+	if (subs) {
+		g_list_free (subs);
+		gam_kqueue_consume_subscriptions();
+		return TRUE;
+	} else {
+		return FALSE;
+	}
+}
+
+/** @} */
