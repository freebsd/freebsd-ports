--- pa_tests/patest_wire.c.orig	Sun Dec  7 14:49:15 2003
+++ pa_tests/patest_wire.c	Sun Dec  7 14:49:52 2003
@@ -74,9 +74,9 @@
     SAMPLE *out = (SAMPLE*)outputBuffer;
     SAMPLE *in = (SAMPLE*)inputBuffer;
     unsigned int i;
-    (void) outTime;
     int samplesPerFrame;
     int numSamples;
+    (void) outTime;
     
     samplesPerFrame = (int) userData;
     numSamples =  framesPerBuffer * samplesPerFrame;
