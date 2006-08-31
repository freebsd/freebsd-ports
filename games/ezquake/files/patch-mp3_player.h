--- ./mp3_player.h.orig	Fri Sep  9 08:00:27 2005
+++ ./mp3_player.h	Tue Aug 29 21:05:59 2006
@@ -19,7 +19,7 @@
 */
 
 
-#if defined(__linux__) && defined(WITH_XMMS)
+#if defined(__unix__) && defined(WITH_XMMS)
 #define __XMMS__
 #endif
 
