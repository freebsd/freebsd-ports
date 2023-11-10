--- lib/pty.c.orig	2022-02-15 06:31:19 UTC
+++ lib/pty.c
@@ -91,7 +91,9 @@ _gftp_ptys_open (int fdm, int fds, char *pts_name)
 #include <utmp.h> /* for login_tty */
 #elif HAVE_LIBUTIL_H
 #include <libutil.h>
-#include <utmp.h> /* for login_tty */
+#else
+extern int openpty(int *amaster, int *aslave, char *name, struct termios *termp, struct winsize * winp);
+extern int login_tty(int fd);
 #endif
 
 char *
@@ -118,8 +120,10 @@ _gftp_ptys_open (int fdm, int fds, char *pts_name)
 static int
 _gftp_ptys_open (int fdm, int fds, char *pts_name)
 {
-  if (login_tty (fds) < 0)
+  if (login_tty (fds) < 0) {
+    close(fds);
     return (GFTP_EFATAL);
+  }
 
   return (fds);
 }
