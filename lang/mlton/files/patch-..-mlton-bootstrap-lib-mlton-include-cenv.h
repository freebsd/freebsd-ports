--- ../mlton-bootstrap/lib/mlton/include/cenv.h.orig	2007-11-24 15:52:08.000000000 +0100
+++ ../mlton-bootstrap/lib/mlton/include/cenv.h	2010-06-22 12:36:33.111364813 +0200
@@ -116,7 +116,7 @@
 #error unknown platform arch
 #endif
 
-#include "gmp.h"
+#include "/usr/local/include/gmp.h"
 
 COMPILE_TIME_ASSERT(sizeof_uintptr_t__is__sizeof_voidStar, 
                     sizeof(uintptr_t) == sizeof(void*));
