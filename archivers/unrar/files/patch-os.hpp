--- os.hpp.orig	2024-02-26 09:03:52 UTC
+++ os.hpp
@@ -165,6 +165,10 @@
 #endif
 #endif
 
+#if defined(OPENSSL_AES)
+#include <openssl/evp.h>
+#endif // OPENSSL_AES
+
 #ifdef  S_IFLNK
 #define SAVE_LINKS
 #endif
