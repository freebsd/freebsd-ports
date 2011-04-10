--- backend/maxicode.c.orig	2011-03-30 15:17:49.000000000 +0800
+++ backend/maxicode.c	2011-03-30 15:18:15.000000000 +0800
@@ -29,7 +29,6 @@
 #ifdef __APPLE__
 #include <sys/malloc.h> 
 #else
-#include <malloc.h> 
 #endif
 
 int maxi_codeword[144];
