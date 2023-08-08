--- src/util/u_memory.h.orig	2022-12-01 11:58:25 UTC
+++ src/util/u_memory.h
@@ -91,8 +91,8 @@ mem_dup(const void *src, size_t size)
 
 
 /* Allocate a structure aligned to a cache line. (used to make atomic ops faster) */
-#define MALLOC_STRUCT_CL(T) (struct T *)align_malloc(sizeof(struct T), CACHE_LINE_SIZE)
-#define CALLOC_STRUCT_CL(T) (struct T *)align_calloc(sizeof(struct T), CACHE_LINE_SIZE)
+#define MALLOC_STRUCT_CL(T) (struct T *)align_malloc(sizeof(struct T), MESA_CACHE_LINE_SIZE)
+#define CALLOC_STRUCT_CL(T) (struct T *)align_calloc(sizeof(struct T), MESA_CACHE_LINE_SIZE)
 #define FREE_CL(ptr) align_free(ptr)
 
 #ifdef __cplusplus
