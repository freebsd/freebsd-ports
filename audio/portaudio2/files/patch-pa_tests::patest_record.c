--- pa_tests/patest_record.c.orig	Sun Dec  7 14:48:31 2003
+++ pa_tests/patest_record.c	Sun Dec  7 14:48:53 2003
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
