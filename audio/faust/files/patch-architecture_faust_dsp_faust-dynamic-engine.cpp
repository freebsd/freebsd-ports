--- architecture/faust/dsp/faust-dynamic-engine.cpp.orig	2020-09-21 21:50:12 UTC
+++ architecture/faust/dsp/faust-dynamic-engine.cpp
@@ -57,7 +57,7 @@
 
 #endif
 
-#if defined(_WIN32) || defined(__APPLE__) || defined(__linux__)
+#if defined(_WIN32) || defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__)
     #define HAS_JACK 1
 #endif 
 
