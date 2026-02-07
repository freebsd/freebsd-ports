--- tools/quake3/q3map2/q3map2.h.orig	2006-02-10 22:01:20 UTC
+++ tools/quake3/q3map2/q3map2.h
@@ -939,6 +939,10 @@
 }
 surfaceType_t;
 
+// Q_EXTERN is defined only later :(
+#ifndef MAIN_C
+extern
+#endif
 char			*surfaceTypes[ NUM_SURFACE_TYPES ]
 #ifndef MAIN_C
 				;
