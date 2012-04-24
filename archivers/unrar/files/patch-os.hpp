--- os.hpp.orig	2012-04-05 22:20:56.000000000 +0200
+++ os.hpp	2012-04-05 22:21:36.000000000 +0200
@@ -193,6 +193,10 @@
 #include <utime.h>
 #include <locale.h>
 
+#ifdef OPENSSL_AES
+#include <openssl/evp.h>
+#endif
+
 #ifdef  S_IFLNK
 #define SAVE_LINKS
 #endif
