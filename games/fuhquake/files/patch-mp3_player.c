--- mp3_player.c.orig	Wed Jan  7 00:45:20 2004
+++ mp3_player.c	Sun Jan 22 22:07:23 2006
@@ -56,9 +56,10 @@
 
 #ifdef __XMMS__
 
+#include <sys/signal.h>
 #include <sys/wait.h>
 
-cvar_t mp3_dir = {"mp3_xmms_dir", "/usr/local/bin"};
+cvar_t mp3_dir = {"mp3_xmms_dir", X11BASE "/bin"};
 cvar_t mp3_xmms_session = {"mp3_xmms_session", "0"};
 
 #endif
