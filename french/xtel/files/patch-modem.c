--- modem.c.orig	Tue Feb 13 10:39:23 2001
+++ modem.c	Tue Jul 24 00:03:52 2001
@@ -307,14 +307,14 @@
      *  (comme le Hayes Optima par exemple)...
      */
 #ifdef USE_TERMIOS
-    ioctl (fd, TCIOCGETA, &term);
+    ioctl (fd, TIOCGETA, &term);
 #else
     ioctl (fd, TCGETA, &term);
 #endif /* USE_TERMIOS */
     if ((term.c_cflag | CLOCAL) == 0) {
 	term.c_cflag |= CLOCAL;
 #ifdef USE_TERMIOS
-	ioctl (fd, TCIOCSETA, &term);
+	ioctl (fd, TIOCSETA, &term);
 #else
 	ioctl (fd, TCSETA, &term);
 #endif /* USE_TERMIOS */
@@ -592,7 +592,7 @@
     if (cmodem) {
 	term.c_cflag &= ~CLOCAL;
 #ifdef USE_TERMIOS
-	ioctl (fd, TCIOCSETA, &term);
+	ioctl (fd, TIOCSETA, &term);
 #else
 	ioctl (fd, TCSETA, &term);
 #endif /* USE_TERMIOS */
