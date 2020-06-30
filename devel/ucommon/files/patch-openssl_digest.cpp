--- openssl/digest.cpp.orig	2015-10-11 02:32:36 UTC
+++ openssl/digest.cpp
@@ -37,20 +37,30 @@ void Digest::set(const char *type)
 
     hashtype = (void *)EVP_get_digestbyname(type);
     if(hashtype) {
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+        context = EVP_MD_CTX_new();
+#else
         context = new EVP_MD_CTX;
         EVP_MD_CTX_init((EVP_MD_CTX *)context);
+#endif
         EVP_DigestInit_ex((EVP_MD_CTX *)context, (const EVP_MD *)hashtype, NULL);
     }
 }
 
 void Digest::release(void)
 {
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
     if(context)
         EVP_MD_CTX_cleanup((EVP_MD_CTX *)context);
+#endif
 
     if(context) {
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+        EVP_MD_CTX_free((EVP_MD_CTX *)context);
+#else
         memset(context, 0, sizeof(EVP_MD_CTX));
         delete (EVP_MD_CTX *)context;
+#endif
         context = NULL;
     }
 
@@ -71,8 +81,12 @@ void Digest::reset(void)
 {
     if(!context) {
         if(hashtype) {
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+            context = EVP_MD_CTX_new();
+#else
             context = new EVP_MD_CTX;
             EVP_MD_CTX_init((EVP_MD_CTX *)context);
+#endif
         }
         else
             return;
