--- thirdparty/OGDF/ogdf/basic/basic.h.orig	2011-08-02 12:31:30.000000000 +0200
+++ thirdparty/OGDF/ogdf/basic/basic.h	2011-08-02 12:31:51.000000000 +0200
@@ -161,7 +161,7 @@
 #endif
 
 // Note: Apple OS X machines will be both OGDF_SYSTEM_UNIX and OGDF_SYSTEM_OSX
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #define OGDF_SYSTEM_OSX
 #endif
 
