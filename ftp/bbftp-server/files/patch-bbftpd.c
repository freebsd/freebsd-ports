--- bbftpd.c.orig	2005-05-03 08:43:34 UTC
+++ bbftpd.c
@@ -104,6 +104,7 @@
 #include <byteswap.h>
 #endif
 
+#include <openssl/err.h>
 #include <openssl/rsa.h>
 
 #ifdef WITH_GZIP
