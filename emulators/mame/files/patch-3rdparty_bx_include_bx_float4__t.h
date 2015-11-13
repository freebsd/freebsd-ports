--- 3rdparty/bx/include/bx/float4_t.h.orig	2015-09-30 06:29:01 UTC
+++ 3rdparty/bx/include/bx/float4_t.h
@@ -18,7 +18,8 @@
 #elif BX_COMPILER_CLANG \
 		&& !BX_PLATFORM_EMSCRIPTEN \
 		&& !BX_PLATFORM_IOS \
-		&& BX_CLANG_HAS_EXTENSION(attribute_ext_vector_type)
+		&& BX_CLANG_HAS_EXTENSION(attribute_ext_vector_type) \
+		&& !BX_PLATFORM_FREEBSD
 #	include "float4_langext.h"
 #else
 #	ifndef BX_FLOAT4_WARN_REFERENCE_IMPL
