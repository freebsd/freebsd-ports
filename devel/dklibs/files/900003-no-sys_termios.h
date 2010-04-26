--- dktypes.h.orig	2010-04-20 22:32:58.000000000 -0700
+++ dktypes.h	2010-04-20 22:33:13.000000000 -0700
@@ -121,9 +121,6 @@
 #if DK_HAVE_TERMIOS_H
 #include <termios.h>
 #endif
-#if DK_HAVE_SYS_TERMIOS_H
-#include <sys/termios.h>
-#endif
 #if DK_HAVE_SYS_TTOLD_H
 #include <sys/ttold.h>
 #endif
--- dksf.c.orig	2010-04-20 22:48:51.000000000 -0700
+++ dksf.c	2010-04-20 22:49:02.000000000 -0700
@@ -87,9 +87,6 @@
 #if DK_HAVE_TERMIOS_H
 #include <termios.h>
 #endif
-#if DK_HAVE_SYS_TERMIOS_H
-#include <sys/termios.h>
-#endif
 #if DK_HAVE_SYS_TTOLD_H
 #include <sys/ttold.h>
 #endif
