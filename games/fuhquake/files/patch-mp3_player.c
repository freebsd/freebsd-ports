--- mp3_player.c.orig	Wed May 21 17:18:36 2003
+++ mp3_player.c	Wed May 21 17:21:23 2003
@@ -48,6 +48,7 @@
 
 #ifdef __XMMS__
 
+#include <sys/signal.h>
 #include <sys/wait.h>
 
 cvar_t mp3_dir = {"mp3_xmms_dir", "/usr/local/bin"};
@@ -769,7 +770,7 @@
 
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 
 #ifdef __XMMS__
 
