
$FreeBSD$

--- Solvers/herbie.c.orig
+++ Solvers/herbie.c
@@ -25,12 +25,7 @@
 // NOTE: memalign is not provided in MacOS X, but malloc is guaranteed to
 //	 return 16-byte aligned blocks. (We assume 32 bit pointers
 //	 everywhere -- what a crappy assumption.)
-#ifdef SYS_MACOSX
 #define memalign(a,s)	malloc(s)
-#include <malloc/malloc.h>
-#else
-#include <malloc.h>
-#endif
 
 // #define HERBIE_DEBUG
   
