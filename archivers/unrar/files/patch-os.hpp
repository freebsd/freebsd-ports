--- os.hpp.orig	2019-04-27 20:05:18 UTC
+++ os.hpp
@@ -166,6 +166,10 @@
 #include <locale.h>
 
 
+#ifdef OPENSSL_AES
+#include <openssl/evp.h>
+#endif // OPENSSL_AES
+
 #ifdef  S_IFLNK
 #define SAVE_LINKS
 #endif
