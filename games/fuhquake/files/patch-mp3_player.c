--- mp3_player.c.orig	Mon Sep  1 18:18:40 2003
+++ mp3_player.c	Mon Sep  1 18:20:09 2003
@@ -48,9 +48,10 @@
 
 #ifdef __XMMS__
 
+#include <sys/signal.h>
 #include <sys/wait.h>
 
-cvar_t mp3_dir = {"mp3_xmms_dir", "/usr/local/bin"};
+cvar_t mp3_dir = {"mp3_xmms_dir", "/usr/X11R6/bin"};
 cvar_t mp3_xmms_session = {"mp3_xmms_session", "0"};
 
 #endif
@@ -288,7 +289,7 @@
 #define XMMS_COMMAND(Name, Param)						\
     void MP3_##Name##_f(void) {							\
 	   if (MP3_IsPlayerRunning()) {						\
-		   xmms_remote_##Param##(XMMS_SESSION);			\
+		   xmms_remote_##Param(XMMS_SESSION);			\
 	   } else {											\
 		   Com_Printf("%s\n", mp3_notrunning_msg);		\
 	   }												\
@@ -769,7 +770,7 @@
 
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 
 #ifdef __XMMS__
 
