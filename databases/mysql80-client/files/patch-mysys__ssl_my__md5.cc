--- mysys/my_md5.cc.orig	2018-04-08 06:44:49 UTC
+++ mysys/my_md5.cc
@@ -56,7 +56,7 @@ static void my_md5_hash(unsigned char *d
 int compute_md5_hash(char *digest, const char *buf, int len) {
   int retval = 0;
   int fips_mode = 0;
-#if !defined(HAVE_WOLFSSL)
+#if !defined(HAVE_WOLFSSL) && !defined(LIBRESSL_VERSION_NUMBER)
   fips_mode = FIPS_mode();
 #endif /* HAVE_WOLFSSL */
   /* If fips mode is ON/STRICT restricted method calls will result into abort,
