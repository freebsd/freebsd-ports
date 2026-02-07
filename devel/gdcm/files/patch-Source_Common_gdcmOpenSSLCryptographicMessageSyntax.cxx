--- Source/Common/gdcmOpenSSLCryptographicMessageSyntax.cxx.orig	2023-12-04 07:33:11 UTC
+++ Source/Common/gdcmOpenSSLCryptographicMessageSyntax.cxx
@@ -24,6 +24,22 @@
 #include <openssl/err.h>
 #include <openssl/rand.h>
 
+#if LIBRESSL_VERSION_NUMBER >= 0x3080200fL
+// implementation copied from LibreSSL before removal in 3.8.2
+static void *BUF_memdup(const void *data, size_t siz)
+{
+  void *ret = NULL;
+  if (data != NULL)
+    {
+    if ((ret = malloc(siz)) == NULL)
+      ERR_PUT_error(ERR_LIB_BUF,(0xfff),ERR_R_MALLOC_FAILURE,__FILE__,__LINE__);
+    else
+      (void) memcpy(ret, data, siz);
+    }
+  return ret;
+}
+#endif
+
 namespace gdcm
 {
 
