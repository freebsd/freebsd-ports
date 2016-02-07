--- cmp3.h.orig	2001-07-01 06:38:08.000000000 +0200
+++ cmp3.h
@@ -1,7 +1,7 @@
 #ifndef _CMP3_H
 #define _CMP3_H
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <ncurses.h>
 #include <termios.h>
 #else
