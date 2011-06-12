
$FreeBSD$

--- mono/metadata/sgen-gc.c.orig
+++ mono/metadata/sgen-gc.c
@@ -222,14 +222,12 @@
 #include "utils/mach-support.h"
 #endif
 
+#include <ucontext.h>
+#include "mini/mini.h"
+
 #define OPDEF(a,b,c,d,e,f,g,h,i,j) \
 	a = i,
 
-enum {
-#include "mono/cil/opcode.def"
-	CEE_LAST
-};
-
 #undef OPDEF
 
 #undef pthread_create
