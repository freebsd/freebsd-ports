--- src/engine/qsoperations.cpp.orig	Mon Jul 12 15:04:29 2004
+++ src/engine/qsoperations.cpp	Mon Jul 12 15:23:49 2004
@@ -61,6 +61,13 @@
 }
 #endif
 
+#ifdef __FreeBSD__
+extern "C" {
+    int isnan( double );
+    int isinf( double );
+}
+#endif
+
 using namespace QS;
 
 bool QS::isNaN( double d )
