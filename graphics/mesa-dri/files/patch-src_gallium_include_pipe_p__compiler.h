--- src/gallium/include/pipe/p_compiler.h.orig	2022-10-11 18:53:31 UTC
+++ src/gallium/include/pipe/p_compiler.h
@@ -125,7 +125,7 @@ typedef unsigned char boolean;
  *       aligned, but we only want to align the field.
  */
 #define EXCLUSIVE_CACHELINE(decl) \
-   union { char __cl_space[CACHE_LINE_SIZE]; \
+   union { char __cl_space[MESA_CACHE_LINE_SIZE]; \
            decl; }
 
 #if defined(__cplusplus)
