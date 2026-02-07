--- ./skelton/svgalib/video.cpp.orig	2010-08-25 01:55:26.000000000 +0000
+++ ./skelton/svgalib/video.cpp	2012-02-17 20:50:29.997843122 +0000
@@ -24,7 +24,9 @@
 #ifdef WIN32
 #include <malloc.h>
 #else
-#include <alloca.h>
+  #if !defined __FreeBSD__ /* alloca is part of stdlib in FreeBSD */
+    #include <alloca.h> 
+  #endif
 #endif
 #include "sprite.h"
 #include "command.h"
