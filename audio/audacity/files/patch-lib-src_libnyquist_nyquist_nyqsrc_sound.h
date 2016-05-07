--- lib-src/libnyquist/nyquist/nyqsrc/sound.h.orig	2016-01-08 22:05:48 UTC
+++ lib-src/libnyquist/nyquist/nyqsrc/sound.h
@@ -459,7 +459,7 @@ double step_to_hz(double);
 
 #ifdef WIN32
 double log2(double x);
-#endif WIN32
+#endif /*WIN32*/
 
 /* macros for access to samples within a suspension */
 /* NOTE: assume suspension structure is named "susp" */
