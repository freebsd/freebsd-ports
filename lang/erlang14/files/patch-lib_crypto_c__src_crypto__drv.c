
$FreeBSD$

--- lib/crypto/c_src/crypto_drv.c.orig	Thu Oct 21 15:37:08 1999
+++ lib/crypto/c_src/crypto_drv.c	Mon Mar  3 15:12:27 2003
@@ -29,6 +29,7 @@
 #include <string.h>
 #include "erl_driver.h"
 
+#define OPENSSL_DES_LIBDES_COMPATIBILITY
 #include "des.h"
 #include "md5.h"
 #include "sha.h"
