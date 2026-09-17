--- src/unix.c.orig	2025-12-15 09:04:17 UTC
+++ src/unix.c
@@ -17,6 +17,7 @@
 #include "param.h"
 #include "proto.h"
 
+#include <sys/param.h>
 #include <fcntl.h>
 #if !defined(pyr) && !defined(NOT_BOTH_TIME)
 # include <time.h>			/* on some systems time.h should not be
@@ -73,6 +74,10 @@ extern int execvp __ARGS((const char *, const char **)
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
@@ -828,7 +833,7 @@ mch_settmode(raw)
 {
 #if defined(ECHOE) && defined(ICANON) && !defined(__NeXT__)
 	/* for "new" tty systems */
-# ifdef CONVEX
+#if defined(CONVEX) || defined(BSD4_4)
 	static struct termios told;
 		   struct termios tnew;
 # else
