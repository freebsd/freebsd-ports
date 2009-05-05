--- speech_tools/audio/nas.cc.orig	Thu Oct 14 16:26:29 1999
+++ speech_tools/audio/nas.cc	Fri Jun 16 17:24:25 2000
@@ -57,7 +57,8 @@
 
 int nas_supported = TRUE;
 
-int endian_int = 1;
+extern int endian_int;
+int endian_int = 1;
 #define NAS_BIG_ENDIAN (((char *)&endian_int)[0] == 0)
 
 static void na_sync_play_cb(AuServer *aud, AuEventHandlerRec *handler, 
