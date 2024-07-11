--- os.hpp.orig	2024-05-12 10:19:01 UTC
+++ os.hpp
@@ -166,6 +166,10 @@
 #endif
 #endif
 
+#if defined(OPENSSL_AES)
+#include <openssl/evp.h>
+#endif // OPENSSL_AES
+
 #ifdef  S_IFLNK
 #define SAVE_LINKS
 #endif
