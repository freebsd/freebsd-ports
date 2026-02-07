--- src/synfigapp/cvs.cpp.orig	2024-05-21 08:01:41 UTC
+++ src/synfigapp/cvs.cpp
@@ -62,7 +62,7 @@
 #define HAVE_STRPTIME
 #endif
 
-#if defined(__APPLE__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 time_t _daylight_() { time_t t(time(0)); return localtime(&t)->tm_gmtoff; }
 #define daylight _daylight_()
 #endif
