--- src/FaacEncoder.cpp.orig	2015-05-18 17:38:07 UTC
+++ src/FaacEncoder.cpp
@@ -95,7 +95,9 @@ FaacEncoder :: open ( void )
     faacConfig->useTns        = 1;
     faacConfig->shortctl      = SHORTCTL_NORMAL;
     faacConfig->useLfe        = 0;
-    faacConfig->allowMidside  = 1;
+    //Do not set allowMidside for API compatibility with faac,
+    //see https://github.com/knik0/faac/issues/8 for details
+    //faacConfig->allowMidside  = 1;
     faacConfig->bitRate       = getOutBitrate() * 1000 / getOutChannel();
     faacConfig->bandWidth     = lowpass;
     faacConfig->quantqual     = (unsigned long) (getOutQuality() * 1000.0);
