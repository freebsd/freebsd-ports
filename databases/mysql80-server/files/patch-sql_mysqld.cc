--- sql/mysqld.cc.orig	2018-04-08 06:44:49 UTC
+++ sql/mysqld.cc
@@ -4309,7 +4309,7 @@ static int warn_self_signed_ca() {
 static void init_ssl() {
 #ifdef HAVE_OPENSSL
 #ifndef HAVE_WOLFSSL
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if defined(LIBRESSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER < 0x10100000L
   CRYPTO_malloc_init();
 #else  /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   OPENSSL_malloc_init();
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
