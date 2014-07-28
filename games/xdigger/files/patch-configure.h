--- configure.h.orig	Sun Jul  4 18:50:04 1999
+++ configure.h	Thu Oct 26 04:40:37 2000
@@ -19,8 +19,8 @@
 #define _CONFIGURE_H
 
 /* Directories */
-#define XDIGGER_LIB_DIR     "/usr/lib/X11/xdigger"
-#define XDIGGER_HISCORE_DIR "/var/X11R6/scores"
+#define XDIGGER_LIB_DIR     "%%PREFIX%%/share/xdigger"
+#define XDIGGER_HISCORE_DIR "%%PREFIX%%/share/xdigger"
 
 #define SOUND_DSP_AUDIO
 
