--- ./libsrc/csg/csg.hpp.orig	Thu Oct  7 00:10:13 2004
+++ ./libsrc/csg/csg.hpp	Tue May 29 22:54:13 2007
@@ -22,7 +22,7 @@
 #ifndef SMALLLIB
 #define _INCLUDE_MORE
 #endif
-#ifdef LINUX
+#if defined(LINUX ) || defined(FREEBSD)
 #define _INCLUDE_MORE
 #endif
 
