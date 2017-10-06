--- vendor/src/github.com/spacemonkeygo/openssl/version.go.orig	2017-07-31 12:00:22.000000000 -0700
+++ vendor/src/github.com/spacemonkeygo/openssl/version.go	2017-08-18 10:09:51.467808000 -0700
@@ -19,4 +19,4 @@ package openssl
 // #include <openssl/opensslv.h>
 import "C"
 
-const Version string = C.OPENSSL_VERSION_TEXT
+const Version string = C.LIBRESSL_VERSION_TEXT
