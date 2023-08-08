--- m4/pdns_check_libcrypto.m4.orig	2023-03-27 15:08:37 UTC
+++ m4/pdns_check_libcrypto.m4
@@ -75,8 +75,10 @@ AC_DEFUN([PDNS_CHECK_LIBCRYPTO], [
         for ssldir in $ssldirs; do
             AC_MSG_CHECKING([for openssl/crypto.h in $ssldir])
             if test -f "$ssldir/include/openssl/crypto.h"; then
-                LIBCRYPTO_INCLUDES="-I$ssldir/include"
-                LIBCRYPTO_LDFLAGS="-L$ssldir/lib"
+                if test $ssldir != /usr; then
+                    LIBCRYPTO_INCLUDES="-I$ssldir/include"
+                    LIBCRYPTO_LDFLAGS="-L$ssldir/lib"
+                fi
                 LIBCRYPTO_LIBS="-lcrypto"
                 found=true
                 AC_MSG_RESULT([yes])
@@ -108,7 +110,7 @@ AC_DEFUN([PDNS_CHECK_LIBCRYPTO], [
     LIBS="$LIBCRYPTO_LIBS $LIBS"
     CPPFLAGS="$LIBCRYPTO_INCLUDES $CPPFLAGS"
     AC_LINK_IFELSE(
-        [AC_LANG_PROGRAM([#include <openssl/crypto.h>], [ERR_load_CRYPTO_strings()])],
+        [AC_LANG_PROGRAM([#include <openssl/bn.h>], [BN_new()])],
         [
             AC_MSG_RESULT([yes])
             AC_CHECK_FUNCS([RAND_bytes RAND_pseudo_bytes CRYPTO_memcmp OPENSSL_init_crypto EVP_MD_CTX_new EVP_MD_CTX_free RSA_get0_key])
