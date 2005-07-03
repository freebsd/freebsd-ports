--- bus/dir-watch.c.orig	Tue Jun 14 22:31:38 2005
+++ bus/dir-watch.c	Sun Jul  3 02:07:14 2005
@@ -28,17 +28,25 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <fcntl.h>
+#elif defined(DBUS_BUS_ENABLE_KQUEUE_ON_FREEBSD)
+#include <sys/types.h>
+#include <sys/event.h>
+#include <sys/time.h>
+#include <signal.h>
+#include <fcntl.h>
+#include <unistd.h>
+#include "bus.h"
+#include <dbus/dbus-watch.h>
 #endif /* DBUS_BUS_ENABLE_DNOTIFY_ON_LINUX */
 
 #include <dbus/dbus-internals.h>
 #include "dir-watch.h"
 
+#define MAX_DIRS_TO_WATCH 128
 
 /* D_NOTIFY is available on Linux 2.4 or greater - the actual SIGIO signal is handled in main.c:signal_handler() */
 #ifdef DBUS_BUS_ENABLE_DNOTIFY_ON_LINUX 
 
-#define MAX_DIRS_TO_WATCH 128
-
 /* use a static array to avoid handling OOM */
 static int fds[MAX_DIRS_TO_WATCH];
 static int num_fds = 0;
@@ -92,6 +100,144 @@ bus_drop_all_directory_watches (void)
 	}
     }
   
+  num_fds = 0;
+}
+
+#elif defined(DBUS_BUS_ENABLE_KQUEUE_ON_FREEBSD)
+
+static int kq = -1;
+static int fds[MAX_DIRS_TO_WATCH];
+static int num_fds = 0;
+static DBusWatch *watch = NULL;
+static DBusLoop *loop = NULL;
+
+static dbus_bool_t
+_kqueue_watch_callback (DBusWatch *watch, unsigned int condition, void *data)
+{
+  return dbus_watch_handle (watch, condition);
+}
+
+static dbus_bool_t
+_handle_kqueue_watch (DBusWatch *watch, unsigned int flags, void *data)
+{
+  struct kevent ev;
+  struct timespec nullts = { 0, 0 };
+  int res;
+  pid_t pid;
+
+  res = kevent (kq, NULL, 0, &ev, 1, &nullts);
+
+  if (res > 0)
+    {
+      pid = getpid ();
+      _dbus_verbose ("Sending SIGHUP signal on reception of a kevent\n");
+      (void) kill (pid, SIGHUP);
+    }
+  else if (res < 0 && errno == EBADF)
+    {
+      kq = -1;
+      if (watch != NULL)
+	{
+	  _dbus_loop_remove_watch (loop, watch, _kqueue_watch_callback, NULL);
+          _dbus_watch_unref (watch);
+	  watch = NULL;
+	}
+      pid = getpid ();
+      _dbus_verbose ("Sending SIGHUP signal since kqueue has been closed\n");
+      (void) kill (pid, SIGHUP);
+    }
+
+  return TRUE;
+}
+
+void
+bus_watch_directory (const char *dir, void *userdata)
+{
+  int fd;
+  struct kevent ev;
+
+  _dbus_assert (dir != NULL);
+
+  if (kq < 0)
+    {
+
+      kq = kqueue ();
+      if (kq < 0)
+        {
+          _dbus_warn ("Cannot create kqueue; error '%s'\n", _dbus_strerror (errno));
+	  goto out;
+	}
+
+        loop = userdata;
+
+        watch = _dbus_watch_new (kq, DBUS_WATCH_READABLE, TRUE,
+                                 _handle_kqueue_watch, NULL, NULL);
+
+	if (watch == NULL)
+          {
+            _dbus_warn ("Unable to create kqueue watch\n");
+	    close (kq);
+	    kq = -1;
+	    goto out;
+	  }
+
+	if (!_dbus_loop_add_watch (loop, watch, _kqueue_watch_callback,
+                                   NULL, NULL))
+          {
+            _dbus_warn ("Unable to add reload watch to main loop");
+	    close (kq);
+	    kq = -1;
+	    _dbus_watch_unref (watch);
+	    watch = NULL;
+            goto out;
+	  }
+    }
+
+  if (num_fds >= MAX_DIRS_TO_WATCH )
+    {
+      _dbus_warn ("Cannot watch config directory '%s'. Already watching %d directories\n", dir, MAX_DIRS_TO_WATCH);
+      goto out;
+    }
+
+  fd = open (dir, O_RDONLY);
+  if (fd < 0)
+    {
+      _dbus_warn ("Cannot open directory '%s'; error '%s'\n", dir, _dbus_strerror (errno));
+      goto out;
+    }
+
+  EV_SET (&ev, fd, EVFILT_VNODE, EV_ADD | EV_ENABLE | EV_CLEAR,
+          NOTE_DELETE | NOTE_EXTEND | NOTE_WRITE | NOTE_LINK | NOTE_RENAME |
+	  NOTE_REVOKE, 0, 0);
+  if (kevent (kq, &ev, 1, NULL, 0, NULL) == -1)
+    {
+      _dbus_warn ("Cannot setup a kevent for '%s'; error '%s'\n", dir, _dbus_strerror (errno));
+      close (fd);
+      goto out;
+    }
+
+  fds[num_fds++] = fd;
+  _dbus_verbose ("Added kqueue watch on config directory '%s'\n", dir);
+
+ out:
+  ;
+}
+
+void
+bus_drop_all_directory_watches (void)
+{
+  int i;
+
+  _dbus_verbose ("Dropping all watches on config directories\n");
+
+  for (i = 0; i < num_fds; i++)
+    {
+      if (close (fds[i]) != 0)
+        {
+          _dbus_verbose ("Error closing fd %d for config directory watch\n", fds[i]);
+	}
+    }
+
   num_fds = 0;
 }
 
