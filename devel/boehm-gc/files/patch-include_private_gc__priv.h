--- include/private/gc_priv.h.orig	2016-08-08 20:30:31 UTC
+++ include/private/gc_priv.h
@@ -2500,6 +2500,8 @@ GC_INNER ptr_t GC_store_debug_info(ptr_t
 # if !defined(PCR)
 #   define NEED_FIND_LIMIT
 # endif
+  GC_INNER ptr_t GC_FreeBSDGetDataStart(size_t, ptr_t);
+# define DATASTART_IS_FUNC
 #endif /* DATASTART_USES_BSDGETDATASTART */
 
 #if (defined(NETBSD) || defined(OPENBSD)) && defined(__ELF__) \
