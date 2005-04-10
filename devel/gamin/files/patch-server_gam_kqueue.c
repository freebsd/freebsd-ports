--- server/gam_kqueue.c.orig	Sun Apr 10 13:21:46 2005
+++ server/gam_kqueue.c	Sun Apr 10 13:29:17 2005
@@ -0,0 +1,730 @@
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
+ *     * To monitor changes made to files within a monitored
+ *       directory, we periodically poll the files. If we wanted to
+ *       use kqueue, we would have to open every file in the
+ *       directory, which is not acceptable.
+ *
+ *     * The creation of missing monitored files is detected by
+ *       performing a stat() every second. Although using kqueue to
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
+#include "config.h"
+#include <string.h>
+#include <fcntl.h>
+#include <unistd.h>
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <sys/event.h>
+#include <sys/time.h>
+#include <errno.h>
+#include "gam_error.h"
+#include "gam_kqueue.h"
+#include "gam_event.h"
+#include "gam_server.h"
+
+#define VN_NOTE_ALL	(NOTE_DELETE | NOTE_WRITE | NOTE_EXTEND | \
+			 NOTE_ATTRIB | NOTE_LINK | NOTE_RENAME | \
+			 NOTE_REVOKE)
+#define VN_NOTE_CHANGED	(NOTE_WRITE | NOTE_EXTEND | NOTE_ATTRIB | NOTE_LINK)
+#define VN_NOTE_DELETED (NOTE_DELETE | NOTE_REVOKE)
+
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
+typedef struct
+{
+  const char	*path;		/* belongs to the first sub in subs */
+  GList		*subs;
+  GSList	*files;		/* list of files in directory */
+  MiniStat	sb;		/* for poll */
+  int		fd;		/* for kqueue */
+  gboolean	isdir;		/* is a directory monitor? */
+} Monitor;
+
+typedef struct
+{
+  char		*pathname;
+  char		*filename;	/* pointer into pathname */
+  MiniStat	sb;
+} FileEntry;
+
+typedef struct
+{
+  GSourceFunc	func;
+  unsigned int	interval;
+  unsigned int	timeout_id;
+  GSList	*monitors;
+} Poller;
+
+static int kq = -1;
+
+static GHashTable *dir_hash = NULL;
+static GHashTable *file_hash = NULL;
+
+/*
+ * The poller monitoring file creations. Low usage is expected,
+ * therefore we set a small interval (one second).
+ */
+static gboolean gam_kqueue_missing_poll (gpointer user_data);
+static Poller missing_poller = { gam_kqueue_missing_poll, 1000, -1, NULL };
+
+/*
+ * The poller monitoring files not supported by kqueue (remote files,
+ * etc). Very low usage is expected, but since this poller is likely
+ * going to access the network, we set a medium interval (3 seconds).
+ */
+static gboolean gam_kqueue_unsupported_poll (gpointer user_data);
+static Poller unsupported_poller = { gam_kqueue_unsupported_poll, 3000, -1, NULL };
+
+/*
+ * The poller monitoring files inside monitored directories. Very high
+ * usage is expected (a mail checker monitoring a couple of large MH
+ * folders will lead to thousands of lstat() calls for each check),
+ * therefore we set a large interval (6 seconds, same as FAM's
+ * default).
+ */
+static gboolean gam_kqueue_dirs_poll (gpointer user_data);
+static Poller dirs_poller = { gam_kqueue_dirs_poll, 6000, -1, NULL };
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
+static FileEntry *
+gam_kqueue_file_entry_new (const char *path, const char *filename)
+{
+  FileEntry *entry;
+
+  entry = g_new(FileEntry, 1);
+  entry->pathname = g_build_filename(path, filename, NULL);
+  entry->filename = strrchr(entry->pathname, G_DIR_SEPARATOR);
+  entry->filename = entry->filename ? entry->filename + 1 : entry->pathname;
+  gam_kqueue_mini_lstat(entry->pathname, &entry->sb);
+
+  return entry;
+}
+
+static void
+gam_kqueue_file_entry_free (FileEntry *entry)
+{
+  g_free(entry->pathname);
+  g_free(entry);
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
+static int
+gam_kqueue_files_find (const FileEntry *entry, const char *filename)
+{
+    return strcmp(entry->filename, filename);
+}
+
+static void
+gam_kqueue_poller_add_monitor (Poller *poller, Monitor *mon)
+{
+  if (! g_slist_find(poller->monitors, mon))
+    {
+      poller->monitors = g_slist_prepend(poller->monitors, mon);
+      if (poller->timeout_id == -1)
+	poller->timeout_id = g_timeout_add(poller->interval, poller->func, NULL);
+    }
+}
+
+static void
+gam_kqueue_poller_remove_monitor (Poller *poller, Monitor *mon)
+{
+  poller->monitors = g_slist_remove(poller->monitors, mon);
+  if (! poller->monitors && poller->timeout_id != -1)
+    {
+      g_source_remove(poller->timeout_id);
+      poller->timeout_id = -1;
+    }
+}
+
+static void
+gam_kqueue_monitor_clear_files (Monitor *mon)
+{
+  gam_kqueue_poller_remove_monitor(&dirs_poller, mon);
+  g_slist_foreach(mon->files, (GFunc) gam_kqueue_file_entry_free, NULL);
+  g_slist_free(mon->files);
+  mon->files = NULL;
+}
+
+static void
+gam_kqueue_monitor_set_missing (Monitor *mon)
+{
+  if (mon->fd >= 0)
+    {
+      close(mon->fd);
+      mon->fd = -1;
+    }
+
+  /*
+   * This shouldn't normally happen, since a directory cannot be
+   * deleted unless all its files are deleted first.
+   */
+  if (mon->files)
+    gam_kqueue_monitor_clear_files(mon);
+
+  gam_kqueue_poller_remove_monitor(&unsupported_poller, mon);
+  gam_kqueue_poller_add_monitor(&missing_poller, mon);
+}
+
+static void
+gam_kqueue_monitor_set_unsupported (Monitor *mon)
+{
+  if (mon->fd >= 0)
+    {
+      close(mon->fd);
+      mon->fd = -1;
+    }
+
+  gam_kqueue_mini_lstat(mon->path, &mon->sb);
+  gam_kqueue_poller_add_monitor(&unsupported_poller, mon);
+}
+
+static void
+gam_kqueue_monitor_enable_notification (Monitor *mon, gboolean was_missing)
+{
+  struct stat sb;
+  gboolean exists;
+  gboolean isdir;
+  struct kevent ev[1];
+
+  /* we first send CREATED or EXISTS/DELETED+ENDEXISTS events */
+
+  exists = lstat(mon->path, &sb) >= 0;
+  isdir = exists && (sb.st_mode & S_IFDIR) != 0;
+
+  if (exists)
+    {
+      GaminEventType gevent;
+
+      gevent = was_missing ? GAMIN_EVENT_CREATED : GAMIN_EVENT_EXISTS;
+      gam_server_emit_event(mon->path, isdir, gevent, mon->subs, 1);
+
+      if (mon->isdir && isdir)
+	{
+	  GDir *dir;
+	  GError *err = NULL;
+
+	  if (mon->files)
+	    {
+	      /* be robust, handle the bug gracefully */
+	      GAM_DEBUG(DEBUG_INFO, "there is a bug in gam_kqueue: monitor had files\n");
+	      gam_kqueue_monitor_clear_files(mon);
+	    }
+
+	  dir = g_dir_open(mon->path, 0, &err);
+	  if (dir)
+	    {
+	      const char *filename;
+
+	      while ((filename = g_dir_read_name(dir)))
+		{
+		  FileEntry *entry;
+
+		  entry = gam_kqueue_file_entry_new(mon->path, filename);
+		  mon->files = g_slist_prepend(mon->files, entry);
+
+		  gam_server_emit_event(entry->pathname,
+					(entry->sb.mode & S_IFDIR) != 0,
+					gevent, mon->subs, 1);
+		}
+
+	      g_dir_close(dir);
+	    }
+	  else
+	    {
+	      GAM_DEBUG(DEBUG_INFO, "unable to open directory %s: %s\n", mon->path, err->message);
+	      g_error_free(err);
+	    }
+
+	  if (mon->files)
+	    gam_kqueue_poller_add_monitor(&dirs_poller, mon);
+	}
+
+      if (! was_missing)
+	gam_server_emit_event(mon->path, isdir, GAMIN_EVENT_ENDEXISTS, mon->subs, 1);
+    }
+  else
+    {
+      if (! was_missing)
+	{
+	  gam_server_emit_event(mon->path, isdir, GAMIN_EVENT_DELETED, mon->subs, 1);
+	  gam_server_emit_event(mon->path, isdir, GAMIN_EVENT_ENDEXISTS, mon->subs, 1);
+	}
+
+      gam_kqueue_monitor_set_missing(mon);
+      return;
+    }
+
+  /* then we enable kqueue notification, falling back to poll if necessary */
+
+  mon->fd = open(mon->path, O_RDONLY | O_NOFOLLOW);
+  if (mon->fd < 0)
+    {
+      GAM_DEBUG(DEBUG_INFO, "cannot open %s (%s), falling back to poll\n", mon->path, g_strerror(errno));
+      gam_kqueue_monitor_set_unsupported(mon);
+      return;
+    }
+
+  EV_SET(ev, mon->fd, EVFILT_VNODE, EV_ADD | EV_ENABLE | EV_CLEAR, VN_NOTE_ALL, 0, mon);
+  if (kevent(kq, ev, G_N_ELEMENTS(ev), NULL, 0, NULL) < 0)
+    {
+      GAM_DEBUG(DEBUG_INFO, "cannot enable kqueue notification for %s (%s), falling back to poll\n", mon->path, g_strerror(errno));
+      gam_kqueue_monitor_set_unsupported(mon);
+    }
+}
+
+static void
+gam_kqueue_monitor_handle_directory_change (Monitor *mon, gboolean isdir)
+{
+  GSList *filenames = NULL;
+  GSList *l;
+  GSList *tmp_files;
+
+  if (isdir)			/* do not follow symbolic links */
+    {
+      GDir *dir;
+      GError *err = NULL;
+
+      dir = g_dir_open(mon->path, 0, &err);
+      if (dir)
+	{
+	  const char *filename;
+
+	  while ((filename = g_dir_read_name(dir)))
+	    filenames = g_slist_prepend(filenames, g_strdup(filename));
+
+	  g_dir_close(dir);
+	}
+      else
+	{
+	  GAM_DEBUG(DEBUG_INFO, "unable to open directory %s: %s\n", mon->path, err->message);
+	  g_error_free(err);
+	}
+    }
+
+  /* handle created files */
+  for (l = filenames; l; l = l->next)
+    if (! g_slist_find_custom(mon->files, l->data, (GCompareFunc) gam_kqueue_files_find))
+      {
+	FileEntry *entry;
+
+	entry = gam_kqueue_file_entry_new(mon->path, l->data);
+	mon->files = g_slist_prepend(mon->files, entry);
+
+	gam_server_emit_event(entry->pathname,
+			      (entry->sb.mode & S_IFDIR) != 0,
+			      GAMIN_EVENT_CREATED, mon->subs, 1);
+      }
+
+  /* handle deleted files */
+  tmp_files = g_slist_copy(mon->files);
+  for (l = tmp_files; l; l = l->next)
+    {
+      FileEntry *entry = l->data;
+
+      if (! g_slist_find_custom(filenames, entry->filename, (GCompareFunc) strcmp))
+	{
+	  mon->files = g_slist_remove(mon->files, entry);
+
+	  gam_server_emit_event(entry->pathname,
+				(entry->sb.mode & S_IFDIR) != 0,
+				GAMIN_EVENT_DELETED, mon->subs, 1);
+
+	  gam_kqueue_file_entry_free(entry);
+	}
+    }
+  g_slist_free(tmp_files);
+
+  if (filenames)
+    {
+      g_slist_foreach(filenames, (GFunc) g_free, NULL);
+      g_slist_free(filenames);
+    }
+
+  if (mon->files)
+    gam_kqueue_poller_add_monitor(&dirs_poller, mon);
+  else
+    gam_kqueue_poller_remove_monitor(&dirs_poller, mon);
+}
+
+static void
+gam_kqueue_monitor_emit_event (Monitor *mon,
+			       GaminEventType event,
+			       gboolean has_isdir,
+			       gboolean isdir)
+{
+  if (! has_isdir)
+    {
+      struct stat sb;
+      isdir = lstat(mon->path, &sb) >= 0 && (sb.st_mode & S_IFDIR) != 0;
+    }
+
+  switch (event)
+    {
+    case GAMIN_EVENT_CHANGED:
+      if (mon->isdir)
+	{
+	  gam_kqueue_monitor_handle_directory_change(mon, isdir);
+	  return;
+	}
+      break;
+
+    case GAMIN_EVENT_DELETED:
+    case GAMIN_EVENT_MOVED:
+      gam_kqueue_monitor_set_missing(mon);
+      break;
+    }
+
+  gam_server_emit_event(mon->path, isdir, event, mon->subs, 1);
+}
+
+static void
+gam_kqueue_monitor_handle_kevent (Monitor *mon, struct kevent *event)
+{
+  if ((event->flags & EV_ERROR) != 0)
+    {
+      /* kqueue failed, fallback to poll */
+      GAM_DEBUG(DEBUG_INFO, "kqueue failed for %s, falling back to poll\n", mon->path);
+      gam_kqueue_monitor_set_unsupported(mon);
+      return;
+    }
+
+  /*
+   * kevent aggregates events, so we must handle a fflags with
+   * multiple event bits set.
+   */
+  if ((event->fflags & VN_NOTE_CHANGED) != 0)
+    gam_kqueue_monitor_emit_event(mon, GAMIN_EVENT_CHANGED, FALSE, FALSE);
+  if ((event->fflags & VN_NOTE_DELETED) != 0)
+    gam_kqueue_monitor_emit_event(mon, GAMIN_EVENT_DELETED, FALSE, FALSE);
+  if ((event->fflags & NOTE_RENAME) != 0)
+    gam_kqueue_monitor_emit_event(mon, GAMIN_EVENT_MOVED, FALSE, FALSE);
+}
+
+static gboolean
+gam_kqueue_kevent_cb (GIOChannel *source, GIOCondition condition, gpointer user_data)
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
+    gam_kqueue_monitor_handle_kevent(ev[i].udata, &ev[i]);
+
+  return TRUE;			/* keep source */
+}
+
+static gboolean
+gam_kqueue_missing_poll (gpointer user_data)
+{
+  GSList *tmp_list;
+  GSList *l;
+
+  /* the list may be modified while we're iterating, so we use a copy */
+
+  tmp_list = g_slist_copy(missing_poller.monitors);
+  for (l = tmp_list; l; l = l->next)
+    {
+      Monitor *mon = l->data;
+      struct stat sb;
+
+      if (lstat(mon->path, &sb) >= 0)
+	{
+	  gam_kqueue_poller_remove_monitor(&missing_poller, mon);
+	  gam_kqueue_monitor_enable_notification(mon, TRUE);
+	}
+    }
+  g_slist_free(tmp_list);
+
+  return TRUE;
+}
+
+static gboolean
+gam_kqueue_unsupported_poll (gpointer user_data)
+{
+  GSList *tmp_list;
+  GSList *l;
+
+  /* the list may be modified while we're iterating, so we use a copy */
+
+  tmp_list = g_slist_copy(unsupported_poller.monitors);
+  for (l = tmp_list; l; l = l->next)
+    {
+      Monitor *mon = l->data;
+      MiniStat sb;
+      GaminEventType event;
+
+      gam_kqueue_mini_lstat(mon->path, &sb);
+
+      if (! sb.exists && mon->sb.exists)
+	event = GAMIN_EVENT_DELETED;
+      else if (gam_kqueue_differs(&sb, &mon->sb))
+	event = GAMIN_EVENT_CHANGED;
+      else
+	continue;
+
+      memcpy(&mon->sb, &sb, sizeof(sb));
+      gam_kqueue_monitor_emit_event(mon, event, TRUE, (sb.mode & S_IFDIR) != 0);
+    }
+  g_slist_free(tmp_list);
+
+  return TRUE;
+}
+
+static gboolean
+gam_kqueue_dirs_poll (gpointer user_data)
+{
+  GSList *l;
+
+  /* the list cannot be modified while we're iterating */
+
+  for (l = dirs_poller.monitors; l; l = l->next)
+    {
+      Monitor *mon = l->data;
+      GSList *f;
+
+      for (f = mon->files; f; f = f->next)
+	{
+	  FileEntry *entry = f->data;
+	  MiniStat sb;
+
+	  gam_kqueue_mini_lstat(entry->pathname, &sb);
+	  if (gam_kqueue_differs(&sb, &entry->sb))
+	    {
+	      memcpy(&entry->sb, &sb, sizeof(sb));
+	      gam_server_emit_event(entry->pathname,
+				    (sb.mode & S_IFDIR) != 0,
+				    GAMIN_EVENT_CHANGED,
+				    mon->subs, 1);
+	    }
+	}
+    }
+
+  return TRUE;
+}
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
+
+  kq = kqueue();
+  if (kq < 0)
+    {
+      gam_error(DEBUG_INFO, "kqueue initialization failure: %s\n", g_strerror(errno));
+      return FALSE;
+    }
+
+  dir_hash = g_hash_table_new(g_str_hash, g_str_equal);
+  file_hash = g_hash_table_new(g_str_hash, g_str_equal);
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
+  Monitor *mon;
+
+  gam_listener_add_subscription(gam_subscription_get_listener(sub), sub);
+
+  path = gam_subscription_get_path(sub);
+  hash = gam_subscription_is_dir(sub) ? dir_hash : file_hash;
+  mon = g_hash_table_lookup(hash, path);
+
+  if (mon)
+    {
+      mon->subs = g_list_append(mon->subs, sub);
+      return TRUE;
+    }
+
+  mon = g_new0(Monitor, 1);
+  mon->path = path;
+  mon->subs = g_list_append(mon->subs, sub);
+  mon->fd = -1;
+  mon->isdir = hash == dir_hash;
+
+  g_hash_table_insert(hash, (gpointer) mon->path, mon);
+  gam_kqueue_monitor_enable_notification(mon, FALSE);
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
+  Monitor *mon;
+
+  hash = gam_subscription_is_dir(sub) ? dir_hash : file_hash;
+  mon = g_hash_table_lookup(hash, gam_subscription_get_path(sub));
+
+  if (! mon)
+    return FALSE;
+
+  mon->subs = g_list_remove_all(mon->subs, sub);
+  if (! mon->subs)
+    {
+      g_hash_table_remove(hash, mon->path);
+
+      /* might have been in any of these two */
+      gam_kqueue_poller_remove_monitor(&missing_poller, mon);
+      gam_kqueue_poller_remove_monitor(&unsupported_poller, mon);
+
+      if (mon->fd >= 0)
+	close(mon->fd);
+
+      if (mon->files)
+	gam_kqueue_monitor_clear_files(mon);
+
+      g_free(mon);
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
+  for (l = subs; l; l = l->next)
+    if (! gam_kqueue_remove_subscription(l->data))
+      success = FALSE;
+
+  g_list_free(subs);
+
+  return success;
+}
