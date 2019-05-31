Obtained from:	https://github.com/curl/curl/commit/0dc9a8019962d31787c4929d36de6817ae3090e7

--- lib/md4.c.orig	2019-05-20 08:13:23 UTC
+++ lib/md4.c
@@ -38,6 +38,10 @@
 
 #include "curl_setup.h"
 
+#ifdef USE_OPENSSL
+#include <openssl/opensslconf.h>
+#endif
+
 /* The NSS, OS/400, and when not included, OpenSSL and mbed TLS crypto
  * libraries do not provide the MD4 hash algorithm, so we use this
  * implementation of it */
