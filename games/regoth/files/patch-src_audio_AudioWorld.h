--- src/audio/AudioWorld.h.orig	2020-01-06 00:33:46 UTC
+++ src/audio/AudioWorld.h
@@ -13,7 +13,7 @@
 #include <utils/Utils.h>
 #include <vdfs/fileIndex.h>
 
-typedef struct ALCcontext_struct ALCcontext;
+typedef struct ALCcontext ALCcontext;
 
 #ifdef RE_USE_SOUND
 #define RE_NUM_MUSIC_BUFFERS 3
