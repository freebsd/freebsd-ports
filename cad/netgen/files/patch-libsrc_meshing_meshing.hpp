--- ./libsrc/meshing/meshing.hpp.orig	Thu Oct  7 00:23:46 2004
+++ ./libsrc/meshing/meshing.hpp	Tue May 29 22:55:52 2007
@@ -34,7 +34,7 @@
 #ifndef SMALLLIB
 #define _INCLUDE_MORE
 #endif
-#ifdef LINUX
+#if defined(LINUX ) || defined(FREEBSD)
 #define _INCLUDE_MORE
 #endif
 
