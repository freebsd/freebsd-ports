--- lib/pty.c.orig	Mon Nov 15 18:09:32 2004
+++ lib/pty.c	Mon Nov 15 18:18:21 2004
@@ -59,6 +59,49 @@
   return (new_fds);
 }
 
+#elif HAVE_OPENPTY
+
+#ifdef HAVE_PTY_H
+#include <pty.h>
+#include <utmp.h> /* for login_tty */
+#elif HAVE_LIBUTIL_H
+#include <libutil.h>
+#include <utmp.h> /* for login_tty */
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
+  if (login_tty (fds) < 0)
+    return (GFTP_EFATAL);
+
+  return (fds);
+}
+
 #elif HAVE_GRANTPT
 
 #include <stropts.h>
@@ -78,8 +121,8 @@
 
   if ((fdm = open ("/dev/ptmx", O_RDWR)) < 0)
     return (GFTP_ERETRYABLE);
-
-  if (grantpt (fdm) < 0)
+  
+  if (grantpt (fdm) < 0)   
     {
       close (fdm);
       return (GFTP_ERETRYABLE);
@@ -123,49 +166,6 @@
 #endif
 
   return (new_fds);
-}
-
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
 }
 
 #else
