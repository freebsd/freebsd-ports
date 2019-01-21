--- DisplayOutput/OpenGL/FontGL.cpp.orig	2018-06-21 01:42:17 UTC
+++ DisplayOutput/OpenGL/FontGL.cpp
@@ -5,7 +5,7 @@
 #include	<iostream>
 
 #ifdef LINUX_GNU
-#include <endian.h>
+#include <sys/endian.h>
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 #define __LITTLE_ENDIAN__ __LITTLE_ENDIAN
 #undef __BIG_ENDIAN__
