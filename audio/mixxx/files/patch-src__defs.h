--- src/defs.h.orig
+++ src/defs.h
@@ -87,6 +87,8 @@
 #define math_min(a,b)            (((a) < (b)) ? (a) : (b))
 #endif
 
+#if !defined(__GNUC__)
+
 // MSVC 2005/2008 needs these
 #ifndef fmax
 #define fmax math_max
@@ -98,3 +100,5 @@
 
 #endif
 
+#endif
+
