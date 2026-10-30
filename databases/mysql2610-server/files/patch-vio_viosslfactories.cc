--- vio/viosslfactories.cc.orig	2026-10-30 11:03:27 UTC
+++ vio/viosslfactories.cc
@@ -56,6 +56,7 @@
 #include <tls_ciphers.h>
 
 #include "my_openssl_fips.h"
+#include "openssl/crypto.h"
 #define TLS_VERSION_OPTION_SIZE 256
 
 static bool ssl_initialized = false;
