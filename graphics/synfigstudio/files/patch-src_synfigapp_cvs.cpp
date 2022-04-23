--- src/synfigapp/cvs.cpp.orig	2022-04-20 22:29:43.537492000 -0700
+++ src/synfigapp/cvs.cpp	2022-04-20 22:30:03.473447000 -0700
@@ -62,7 +62,7 @@
 #define HAVE_STRPTIME
 #endif
 
-#if defined(__APPLE__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 time_t _daylight_() { time_t t(time(0)); return localtime(&t)->tm_gmtoff; }
 #define daylight _daylight_()
 #endif
