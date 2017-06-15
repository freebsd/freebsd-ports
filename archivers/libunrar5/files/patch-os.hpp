--- os.hpp.orig	2013-12-01 08:10:14 UTC
+++ os.hpp
@@ -151,6 +151,10 @@
 #include <utime.h>
 #include <locale.h>
 
+#ifdef OPENSSL_AES
+#include <openssl/evp.h>
+#endif // OPENSSL_AES
+
 #ifdef  S_IFLNK
 #define SAVE_LINKS
 #endif
