 Remove conflict with system alloca.

--- 3rdparty/bx/include/bx/bx.h.orig	2023-11-10 16:47:29 UTC
+++ 3rdparty/bx/include/bx/bx.h
@@ -6,7 +6,6 @@
 #ifndef BX_H_HEADER_GUARD
 #define BX_H_HEADER_GUARD
 
-#include <alloca.h> // alloca
 #include <stdarg.h> // va_list
 #include <stdint.h> // uint32_t
 #include <stdlib.h> // size_t
