--- sql/mysqld.cc.orig	2018-05-06 19:15:48 UTC
+++ sql/mysqld.cc
@@ -4321,7 +4321,7 @@ static void init_ssl() {
 
 static int init_ssl_communication() {
 #ifdef HAVE_OPENSSL
-#ifndef HAVE_WOLFSSL
+#if !defined(HAVE_WOLFSSL) && !defined(LIBRESSL_VERSION_NUMBER)
   char ssl_err_string[OPENSSL_ERROR_LENGTH] = {'\0'};
   int ret_fips_mode = set_fips_mode(opt_ssl_fips_mode, ssl_err_string);
   if (ret_fips_mode != 1) {
@@ -8647,7 +8647,7 @@ bool mysqld_get_one_option(int optid,
         One can disable SSL later by using --skip-ssl or --ssl=0.
       */
       opt_use_ssl = true;
-#ifdef HAVE_WOLFSSL
+#if defined(HAVE_WOLFSSL) || defined(LIBRESSL_VERSION_NUMBER)
       /* crl has no effect in wolfSSL. */
       opt_ssl_crl = NULL;
       opt_ssl_crlpath = NULL;
