--- mysys_ssl/openssl.c
+++ mysys_ssl/openssl.c
@@ -36,8 +36,12 @@
 static uint testing;
 static size_t alloc_size, alloc_count;
 
-static void *coc_malloc(size_t size, const char *f __attribute__((unused)),
-                                             int l __attribute__((unused)))
+static void *coc_malloc(size_t size
+#if !(defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER >= 0x30500000L)
+                                           , const char *f __attribute__((unused)),
+                                             int l __attribute__((unused))
+#endif
+)
 {
   if (unlikely(testing))
   {
