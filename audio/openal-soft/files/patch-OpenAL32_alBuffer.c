--- OpenAL32/alBuffer.c.orig	2016-01-25 03:12:39 UTC
+++ OpenAL32/alBuffer.c
@@ -1209,7 +1209,7 @@ static ALboolean DecomposeFormat(ALenum 
         { AL_FORMAT_BFORMAT3D_16,      FmtBFormat3D, FmtShort },
         { AL_FORMAT_BFORMAT3D_FLOAT32, FmtBFormat3D, FmtFloat },
     };
-    ALuint i;
+    volatile ALuint i;
 
     for(i = 0;i < COUNTOF(list);i++)
     {
