--- src/wm_tty.c.orig	2017-02-26 17:30:45 UTC
+++ src/wm_tty.c
@@ -27,6 +27,7 @@
 #if !(defined(_WIN32) || defined(__DJGPP__) || defined(WILDMIDI_AMIGA) || defined(__OS2__) || defined(__EMX__))
 
 #define _XOPEN_SOURCE 600 /* for ONLCR */
+#define __BSD_VISIBLE 1 /* for ONLCR in *BSD */
 
 #include <unistd.h>
 #include <termios.h>
