--- packages/ssl/cryptolib.c.orig	2017-02-27 14:25:52 UTC
+++ packages/ssl/cryptolib.c
@@ -284,7 +284,7 @@ bio_control(BIO* bio, int cmd, long num,
 static int
 bio_create(BIO* bio)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
    bio->shutdown = 1;
    bio->init = 1;
    bio->num = -1;
@@ -312,7 +312,7 @@ bio_destroy(BIO* bio)
    return 1;
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 /*
  * Specify the BIO read and write function structures
  */
