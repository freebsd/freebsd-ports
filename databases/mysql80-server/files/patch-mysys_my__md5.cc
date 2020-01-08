--- mysys/my_md5.cc.orig	2019-09-20 08:30:51 UTC
+++ mysys/my_md5.cc
@@ -56,7 +56,9 @@ static void my_md5_hash(unsigned char *digest, unsigne
 int compute_md5_hash(char *digest, const char *buf, int len) {
   int retval = 0;
   int fips_mode = 0;
+#ifndef LIBRESSL_VERSION_NUMBER
   fips_mode = FIPS_mode();
+#endif /* LIBRESSL_VERSION_NUMBER */
   /* If fips mode is ON/STRICT restricted method calls will result into abort,
    * skipping call. */
   if (fips_mode == 0) {
