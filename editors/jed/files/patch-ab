--- src/jprocess.c.orig	Thu Feb 20 20:19:47 2003
+++ src/jprocess.c	Thu Feb 20 20:24:36 2003
@@ -58,7 +58,9 @@
 
 #ifdef REALLY_HAVE_TERMIOS_H
 # ifndef __os2__
-#  define USE_PTY
+#  ifndef __FreeBSD__ 
+#   define USE_PTY
+#  endif
 # endif
 #endif
 
