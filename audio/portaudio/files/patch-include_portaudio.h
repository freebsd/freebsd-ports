$OpenBSD: patch-include_portaudio_h,v 1.2 2013/03/12 00:59:50 brad Exp $
--- include/portaudio.h.orig	2018-07-17 06:55:08 UTC
+++ include/portaudio.h
@@ -236,7 +236,8 @@ typedef enum PaHostApiTypeId
     paWDMKS=11,
     paJACK=12,
     paWASAPI=13,
-    paAudioScienceHPI=14
+    paAudioScienceHPI=14,
+    paSndio=15
 } PaHostApiTypeId;
 
 
@@ -1144,6 +1145,15 @@ signed long Pa_GetStreamReadAvailable( PaStream* strea
  error is encountered.
 */
 signed long Pa_GetStreamWriteAvailable( PaStream* stream );
+
+
+/** Retrieve the host type handling an open stream.
+
+ @return Returns a non-negative value representing the host API type
+ handling an open stream or, a PaErrorCode (which are always negative)
+ if PortAudio is not initialized or an error is encountered.
+*/
+PaHostApiTypeId Pa_GetStreamHostApiType( PaStream* stream );
 
 
 /* Miscellaneous utilities */
