--- src/unix.c.orig	Sun Jun 27 12:56:25 2004
+++ src/unix.c	Sun Jun 27 12:58:11 2004
@@ -17,6 +17,7 @@
 #include "param.h"
 #include "proto.h"
 
+#include <sys/param.h>
 #include <fcntl.h>
 #if !defined(pyr) && !defined(NOT_BOTH_TIME)
 # include <time.h>			/* on some systems time.h should not be
@@ -73,6 +74,10 @@
 #  if defined(hpux) && !defined(SIGWINCH)	/* hpux 9.01 has it */
 #   define SIGWINCH SIGWINDOW
 #  endif
+# elif defined(BSD4_4)
+#  include <termios.h>
+#  define TCGETA TIOCGETA
+#  define TCSETA TIOCSETA
 # else
 #  include <sgtty.h>
 # endif	/* hpux */
@@ -828,7 +833,7 @@
 {
 #if defined(ECHOE) && defined(ICANON) && !defined(__NeXT__)
 	/* for "new" tty systems */
-# ifdef CONVEX
+#if defined(CONVEX) || defined(BSD4_4)
 	static struct termios told;
 		   struct termios tnew;
 # else
