--- mp3_player.c.orig	Wed Feb  4 21:19:26 2004
+++ mp3_player.c	Wed Feb  4 21:23:46 2004
@@ -56,9 +56,10 @@
 
 #ifdef __XMMS__
 
+#include <sys/signal.h>
 #include <sys/wait.h>
 
-cvar_t mp3_dir = {"mp3_xmms_dir", "/usr/local/bin"};
+cvar_t mp3_dir = {"mp3_xmms_dir", "%%X11BASE%%/bin"};
 cvar_t mp3_xmms_session = {"mp3_xmms_session", "0"};
 
 #endif
