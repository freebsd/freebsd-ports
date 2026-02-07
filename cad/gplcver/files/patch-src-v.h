--- src/v.h.orig	Fri Jan 20 15:02:16 2006
+++ src/v.h	Fri Jan 20 15:02:33 2006
@@ -119,7 +119,6 @@
 #endif
 } w64_u;
 #else
-#include <sys/isa_defs.h>
 
 typedef union {
  word64 w64v; 
