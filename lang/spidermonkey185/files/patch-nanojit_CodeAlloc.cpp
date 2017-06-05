--- nanojit/CodeAlloc.cpp.orig	2016-09-07 UTC
+++ nanojit/CodeAlloc.cpp
@@ -261,7 +261,6 @@ namespace nanojit
 #endif
 
 #if defined(AVMPLUS_UNIX) && defined(NANOJIT_ARM)
-#include <asm/unistd.h>
 extern "C" void __clear_cache(char *BEG, char *END);
 #endif
 
