--- pkg-openssl.c.orig	2011-02-26 21:05:07 UTC
+++ pkg-openssl.c
@@ -164,7 +164,7 @@ tls_verify_callback(int preverify_ok, X509_STORE_CTX *
         char buf[512];
         printf("%s tls_verify_callback(%d, ...)\n", time_stamp(), preverify_ok);
 
-        X509_NAME_oneline(X509_get_issuer_name(ctx->current_cert), buf, sizeof buf);
+        X509_NAME_oneline(X509_get_issuer_name(X509_STORE_CTX_get_current_cert(ctx)), buf, sizeof buf);
         printf("depth %d: %s\n", X509_STORE_CTX_get_error_depth(ctx), buf);
     }
     return MY_TRUE;
@@ -801,10 +801,10 @@ tls_check_certificate (interactive_t *ip, Bool more)
                     break;
                 }
                 /* extension name */
-                len = OBJ_obj2txt(buf, sizeof buf, ext->object, 1),
+                len = OBJ_obj2txt(buf, sizeof buf, X509_EXTENSION_get_object(ext), 1),
                 put_c_n_string(&(extensions->item[3 * i]), (char *)buf, len);
 
-                len = OBJ_obj2txt(buf, sizeof buf, ext->object, 0),
+                len = OBJ_obj2txt(buf, sizeof buf, X509_EXTENSION_get_object(ext), 0),
                 put_c_n_string(&(extensions->item[3 * i + 1]), (char *)buf, len);
 
                 /* extension values */
@@ -1050,20 +1050,38 @@ calc_digest (digest_t md, void *dest, size_t destlen, 
         errorf("OpenSSL wasn't configured to provide the hmac() method.\n");
         /* NOTREACHED */
 #else
+# if OPENSSL_VERSION_NUMBER < 0x10100005L
         HMAC_CTX ctx;
 
         HMAC_Init(&ctx, key, keylen, md);
         HMAC_Update(&ctx, msg, msglen);
         HMAC_Final(&ctx, dest, NULL);
+# else
+        HMAC_CTX *ctx = HMAC_CTX_new();
+
+        HMAC_Init(ctx, key, keylen, md);
+        HMAC_Update(ctx, msg, msglen);
+        HMAC_Final(ctx, dest, NULL);
+        HMAC_CTX_free(ctx);
+# endif
 #endif
     }
     else
     {
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
         EVP_MD_CTX ctx;
 
         EVP_DigestInit(&ctx, md);
         EVP_DigestUpdate(&ctx, msg, msglen);
         EVP_DigestFinal(&ctx, dest, NULL);
+#else
+        EVP_MD_CTX *ctx = EVP_MD_CTX_new();
+
+        EVP_DigestInit(ctx, md);
+        EVP_DigestUpdate(ctx, msg, msglen);
+        EVP_DigestFinal(ctx, dest, NULL);
+        EVP_MD_CTX_free(ctx);
+#endif
     }
 } /* calc_digest() */
 
