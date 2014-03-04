--- os.hpp.orig	2013-12-01 16:10:14.000000000 +0800
+++ os.hpp	2014-02-04 08:46:43.448882590 +0800
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
