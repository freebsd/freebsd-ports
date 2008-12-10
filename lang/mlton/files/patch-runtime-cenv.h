--- runtime/cenv.h.orig	2008-04-27 10:56:05.000000000 +1000
+++ runtime/cenv.h	2008-04-27 10:56:20.000000000 +1000
@@ -116,7 +116,7 @@
 #error unknown platform arch
 #endif
 
-#include "gmp.h"
+#include "/usr/local/include/gmp.h"
 
 COMPILE_TIME_ASSERT(sizeof_uintptr_t__is__sizeof_voidStar, 
                     sizeof(uintptr_t) == sizeof(void*));
