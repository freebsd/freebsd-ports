--- mp3_player.c.orig	Thu Apr  6 20:23:18 2006
+++ mp3_player.c	Wed Aug 30 20:11:52 2006
@@ -21,6 +21,7 @@
 */
 
 
+#include <dlfcn.h>
 #include "quakedef.h"
 #include "mp3_player.h"
 
@@ -58,9 +59,10 @@
 
 #include <sys/wait.h>
 #include <sys/types.h> // fork, execv, usleep
+#include <signal.h>
 #include <unistd.h> // fork, execv, usleep
 
-cvar_t mp3_dir = {"mp3_xmms_dir", "/usr/local/bin"};
+cvar_t mp3_dir = {"mp3_xmms_dir", "%%X11BASE%%/bin"};
 cvar_t mp3_xmms_session = {"mp3_xmms_session", "0"};
 
 #endif
@@ -134,7 +136,7 @@
 }
 
 static void XMMS_LoadLibrary(void) {
-	if (!(libxmms_handle = dlopen("libxmms.so.1", RTLD_NOW)) && !(libxmms_handle = dlopen("libxmms.so", RTLD_NOW)))
+	if (!(libxmms_handle = dlopen("libxmms.so", RTLD_NOW)))
 		return;
 
 	if (!QLib_ProcessProcdef(libxmms_handle, xmmsProcs, NUM_XMMSPROCS)) {
