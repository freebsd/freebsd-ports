--- src/synfigapp/cvs.cpp.orig	2007-11-13 18:13:07.000000000 +0900
+++ src/synfigapp/cvs.cpp	2008-03-14 19:39:08.000000000 +0900
@@ -62,7 +62,7 @@
 #define HAVE_STRPTIME
 #endif
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 time_t _daylight_() { time_t t(time(0)); return localtime(&t)->tm_gmtoff; }
 #define daylight _daylight_()
 #endif
