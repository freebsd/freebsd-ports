--- src/compiler/spirv/spirv_to_nir.c.orig	2020-10-21 16:03:29.994285000 +0200
+++ src/compiler/spirv/spirv_to_nir.c	2020-10-21 18:45:12.746719000 +0200
@@ -37,8 +37,12 @@
 
 #include <stdio.h>
 #if UTIL_ARCH_BIG_ENDIAN
+#ifdef __linux__
 #include <byteswap.h>
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
 #endif
+#endif
 
 void
 vtn_log(struct vtn_builder *b, enum nir_spirv_debug_level level,
@@ -415,7 +419,7 @@
    {
       uint32_t *copy = ralloc_array(b, uint32_t, word_count);
       for (unsigned i = 0; i < word_count; i++)
-         copy[i] = bswap_32(words[i]);
+         copy[i] = bswap32(words[i]);
       words = copy;
    }
 #endif
