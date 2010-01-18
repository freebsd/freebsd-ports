--- lib/pty.c.orig	2007-03-13 02:56:43.000000000 +0100
+++ lib/pty.c	2010-01-17 17:34:25.000000000 +0100
@@ -59,6 +59,50 @@
   return (new_fds);
 }
 
+#elif HAVE_OPENPTY
+
+#ifdef HAVE_PTY_H
+#include <pty.h>
+#include <utmp.h> /* for login_tty */
+#elif HAVE_LIBUTIL_H
+#include <libutil.h>
+#else
+extern int openpty(int *amaster, int *aslave, char *name, struct termios *termp, struct winsize * winp);
+extern int login_tty(int fd);
+#endif
+
+char *
+gftp_get_pty_impl (void)
+{
+  return ("openpty");
+}
+
+
+static int
+_gftp_ptym_open (char *pts_name, size_t len, int *fds)
+{
+  int fdm;
+
+  if (openpty (&fdm, fds, pts_name, NULL, NULL) < 0)
+    return (GFTP_ERETRYABLE);
+
+  ioctl (*fds, TIOCSCTTY, NULL);
+
+  return (fdm);
+}
+
+
+static int
+_gftp_ptys_open (int fdm, int fds, char *pts_name)
+{
+  if (login_tty (fds) < 0) {
+    close(fds);
+    return (GFTP_EFATAL);
+  }
+
+  return (fds);
+}
+
 #elif HAVE_GRANTPT
 
 #if !(defined(__FreeBSD__) || defined(__NetBSD__) || defined(__APPLE__))
@@ -131,49 +192,6 @@
   return (new_fds);
 }
 
-#elif HAVE_OPENPTY
-
-#ifdef HAVE_PTY_H
-#include <pty.h>
-#include <utmp.h> /* for login_tty */
-#elif HAVE_LIBUTIL_H
-#include <libutil.h>
-#include <utmp.h> /* for login_tty */
-#else
-extern int openpty(int *amaster, int *aslave, char *name, struct termios *termp, struct winsize * winp);
-extern int login_tty(int fd);
-#endif
-
-char *
-gftp_get_pty_impl (void)
-{
-  return ("openpty");
-}
-
-
-static int
-_gftp_ptym_open (char *pts_name, size_t len, int *fds)
-{
-  int fdm;
-
-  if (openpty (&fdm, fds, pts_name, NULL, NULL) < 0)
-    return (GFTP_ERETRYABLE);
-
-  ioctl (*fds, TIOCSCTTY, NULL);
-
-  return (fdm);
-}
-
-
-static int
-_gftp_ptys_open (int fdm, int fds, char *pts_name)
-{
-  if (login_tty (fds) < 0)
-    return (GFTP_EFATAL);
-
-  return (fds);
-}
-
 #else
 
 /* Fall back to *BSD... */
