--- os.hpp.orig	2017-04-28 17:28:46 UTC
+++ os.hpp
@@ -150,6 +150,10 @@
 #include <locale.h>
 
 
+#ifdef OPENSSL_AES
+#include <openssl/evp.h>
+#endif // OPENSSL_AES
+
 #ifdef  S_IFLNK
 #define SAVE_LINKS
 #endif
