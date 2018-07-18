--- src/common/pa_stream.c.orig	2018-07-17 06:44:39 UTC
+++ src/common/pa_stream.c
@@ -93,6 +93,8 @@ void PaUtil_InitializeStreamRepresentation( PaUtilStre
     streamRepresentation->streamInfo.inputLatency = 0.;
     streamRepresentation->streamInfo.outputLatency = 0.;
     streamRepresentation->streamInfo.sampleRate = 0.;
+
+    streamRepresentation->hostApiType = 0;
 }
 
 
