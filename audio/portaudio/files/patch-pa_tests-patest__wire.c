--- pa_tests/patest_wire.c.orig	2012-12-22 13:48:25.000000000 +0100
+++ pa_tests/patest_wire.c	2012-12-22 13:48:25.000000000 +0100
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
