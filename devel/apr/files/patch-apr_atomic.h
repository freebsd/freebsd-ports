--- apr-0.9.4/include/apr_atomic.h.orig	Sun Nov  2 01:57:08 2003
+++ apr-0.9.4/include/apr_atomic.h	Sun Nov  2 02:20:37 2003
@@ -206,10 +206,16 @@
 
 #define apr_atomic_t apr_uint32_t
 #define apr_atomic_add(mem, val)     atomic_add_int(mem,val)
-#define apr_atomic_dec(mem)          atomic_subtract_int(mem,1)
 #define apr_atomic_inc(mem)          atomic_add_int(mem,1)
 #define apr_atomic_set(mem, val)     atomic_set_int(mem, val)
 #define apr_atomic_read(mem)         (*mem)
+
+#define apr_atomic_dec(mem)                                     \
+({                                                              \
+   atomic_subtract_int(mem,1);                                  \
+   *(int *)mem;                                                 \
+  })
+
 
 #elif (defined(__linux__) || defined(__EMX__)) && defined(__i386__) && !APR_FORCE_ATOMIC_GENERIC
 
