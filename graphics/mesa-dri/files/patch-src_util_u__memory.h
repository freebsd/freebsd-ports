--- src/util/u_memory.h.orig	2023-09-06 23:29:52 UTC
+++ src/util/u_memory.h
@@ -90,7 +90,7 @@ mem_dup(const void *src, size_t size)
 #define Offset(TYPE, MEMBER) ((uintptr_t)&(((TYPE *)NULL)->MEMBER))
 
 /* TODO: this could be different on non-x86 architectures. */
-#define CACHE_LINE_SIZE 64
+#define MESA_CACHE_LINE_SIZE 64
 
 /**
  * Declare a variable on its own cache line.
@@ -107,12 +107,12 @@ mem_dup(const void *src, size_t size)
  *       aligned, but we only want to align the field.
  */
 #define EXCLUSIVE_CACHELINE(decl) \
-   union { char __cl_space[CACHE_LINE_SIZE]; \
+   union { char __cl_space[MESA_CACHE_LINE_SIZE]; \
            decl; }
 
 /* Allocate a structure aligned to a cache line. (used to make atomic ops faster) */
-#define MALLOC_STRUCT_CL(T) (struct T *)align_malloc(sizeof(struct T), CACHE_LINE_SIZE)
-#define CALLOC_STRUCT_CL(T) (struct T *)align_calloc(sizeof(struct T), CACHE_LINE_SIZE)
+#define MALLOC_STRUCT_CL(T) (struct T *)align_malloc(sizeof(struct T), MESA_CACHE_LINE_SIZE)
+#define CALLOC_STRUCT_CL(T) (struct T *)align_calloc(sizeof(struct T), MESA_CACHE_LINE_SIZE)
 #define FREE_CL(ptr) align_free(ptr)
 
 #ifdef __cplusplus
