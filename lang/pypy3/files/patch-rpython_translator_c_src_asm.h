--- rpython/translator/c/src/asm.h.orig	2016-06-14 07:46:04 UTC
+++ rpython/translator/c/src/asm.h
@@ -10,10 +10,6 @@
 #  include "src/asm_gcc_x86_64.h"
 #endif
 
-#if defined(__GNUC__) && defined(__ppc__)
-#  include "src/asm_ppc.h"
-#endif
-
 #if defined(MS_WINDOWS) && defined(_MSC_VER)
 #  include "src/asm_msvc.h"
 #endif
