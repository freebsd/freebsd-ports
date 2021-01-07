--- VGMPlay_AddFmts.c.orig	2021-01-06 02:49:31 UTC
+++ VGMPlay_AddFmts.c
@@ -117,7 +117,7 @@ extern INT32 VGMSmplPlayed;
 extern INT32 VGMSampleRate;
 extern UINT32 BlocksSent;
 extern UINT32 BlocksPlayed;
-bool VGMEnd;
+extern bool VGMEnd;
 extern bool EndPlay;
 extern bool PausePlay;
 extern bool FadePlay;
