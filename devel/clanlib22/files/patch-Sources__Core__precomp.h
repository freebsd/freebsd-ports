--- Sources/Core/precomp.h.orig	2014-04-05 12:54:07.000000000 +0200
+++ Sources/Core/precomp.h	2014-04-05 12:29:52.000000000 +0200
@@ -61,4 +61,5 @@
 #define BREAKPOINT asm("int $03");
 #endif
 
+#include <unistd.h>
 
