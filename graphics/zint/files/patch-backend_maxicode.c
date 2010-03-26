
$FreeBSD$

--- backend/maxicode.c.orig
+++ backend/maxicode.c
@@ -29,7 +29,6 @@
 #ifdef __APPLE__
 #include <sys/malloc.h> 
 #else
-#include <malloc.h> 
 #endif
 
 int maxi_codeword[144];
