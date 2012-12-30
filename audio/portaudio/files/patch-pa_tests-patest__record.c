--- pa_tests/patest_record.c.orig	2012-12-22 13:48:25.000000000 +0100
+++ pa_tests/patest_record.c	2012-12-22 13:48:25.000000000 +0100
@@ -138,10 +138,10 @@
     SAMPLE *wptr = (SAMPLE*)outputBuffer;
     unsigned int i;
     int finished;
+    int framesToPlay, samplesToPlay, samplesPerBuffer;
     unsigned int framesLeft = data->maxFrameIndex - data->frameIndex;
     (void) inputBuffer; /* Prevent unused variable warnings. */
     (void) outTime;
-    int framesToPlay, samplesToPlay, samplesPerBuffer;
 
     if( framesLeft < framesPerBuffer )
     {
