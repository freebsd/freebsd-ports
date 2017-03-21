$OpenBSD: patch-include_portaudio_h,v 1.2 2013/03/12 00:59:50 brad Exp $
--- include/portaudio.h.orig	2016-06-22 08:28:31 UTC
+++ include/portaudio.h
@@ -236,7 +236,8 @@ typedef enum PaHostApiTypeId
     paWDMKS=11,
     paJACK=12,
     paWASAPI=13,
-    paAudioScienceHPI=14
+    paAudioScienceHPI=14,
+    paSndio=15
 } PaHostApiTypeId;
 
 
