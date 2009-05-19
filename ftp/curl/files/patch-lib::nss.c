Fix a typo in a comment.

--- a/lib/nss.c
+++ b/lib/nss.c
@@ -157,7 +157,7 @@
 #endif
 };
 
-/* following ciphers are new in NSS 3.4 and not enabled by default, therefor
+/* following ciphers are new in NSS 3.4 and not enabled by default, therefore
    they are enabled explicitly */
 static const int enable_ciphers_by_default[] = {
   TLS_DHE_DSS_WITH_AES_128_CBC_SHA,
