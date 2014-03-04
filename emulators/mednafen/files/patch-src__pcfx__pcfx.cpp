--- src/pcfx/pcfx.cpp.orig	2009-12-24 11:03:43.000000000 +0100
+++ src/pcfx/pcfx.cpp	2014-02-28 21:38:56.000000000 +0100
@@ -35,6 +35,7 @@
 #include <errno.h>
 #include <string.h>
 #include <math.h>
+#include <unistd.h>
 
 #ifdef WANT_PCFX_MMAP
 #include <sys/mman.h>
