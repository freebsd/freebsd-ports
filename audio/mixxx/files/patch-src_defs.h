--- src/defs.h.orig	2013-05-08 23:20:26 UTC
+++ src/defs.h
@@ -87,6 +87,8 @@ inline double zap_denormal(double x)
 #define math_min(a,b)            (((a) < (b)) ? (a) : (b))
 #endif
 
+#if !defined(__GNUC__)
+
 // MSVC 2005/2008 needs these
 #ifndef fmax
 #define fmax math_max
@@ -98,3 +100,5 @@ inline double zap_denormal(double x)
 
 #endif
 
+#endif
+
