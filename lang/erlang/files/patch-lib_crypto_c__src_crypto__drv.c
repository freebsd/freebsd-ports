
$FreeBSD$

--- lib/crypto/c_src/crypto_drv.c.orig	Sun Jun  1 18:15:54 2003
+++ lib/crypto/c_src/crypto_drv.c	Sun Jun  1 18:15:50 2003
@@ -29,6 +29,7 @@
 #include <string.h>
 #include "erl_driver.h"
 
+#define OPENSSL_DES_LIBDES_COMPATIBILITY
 #include "des.h"
 #include "md5.h"
 #include "sha.h"
@@ -207,9 +208,9 @@
     cfs.SHA1_Init = driver_dl_sym(lib_handle, "SHA1_Init");
     cfs.SHA1_Update = driver_dl_sym(lib_handle, "SHA1_Update");
     cfs.SHA1_Final = driver_dl_sym(lib_handle, "SHA1_Final");
-    cfs.des_set_key = driver_dl_sym(lib_handle, "des_set_key");
-    cfs.des_ncbc_encrypt = driver_dl_sym(lib_handle, "des_ncbc_encrypt");
-    cfs.des_ede3_cbc_encrypt = driver_dl_sym(lib_handle, "des_ede3_cbc_encrypt");
+    cfs.des_set_key = driver_dl_sym(lib_handle, "_ossl_old_des_set_key");
+    cfs.des_ncbc_encrypt = driver_dl_sym(lib_handle, "_ossl_old_des_ncbc_encrypt");
+    cfs.des_ede3_cbc_encrypt = driver_dl_sym(lib_handle, "_ossl_old_des_ede3_cbc_encrypt");
 
     /* Check that all pointer where initialized */
     for (i = 0; i < sizeof(crypto_funcs)/sizeof(void*); i++) {
