--- OpenAL32/alBuffer.c.orig	2017-07-30 05:09:21 UTC
+++ OpenAL32/alBuffer.c
@@ -1171,7 +1171,7 @@ static ALboolean DecomposeUserFormat(ALenum format, en
         { AL_FORMAT_BFORMAT3D_FLOAT32, UserFmtBFormat3D, UserFmtFloat },
         { AL_FORMAT_BFORMAT3D_MULAW,   UserFmtBFormat3D, UserFmtMulaw },
     };
-    ALuint i;
+    volatile ALuint i;
 
     for(i = 0;i < COUNTOF(list);i++)
     {
