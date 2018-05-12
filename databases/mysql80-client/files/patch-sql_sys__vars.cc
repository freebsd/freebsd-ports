--- sql/sys_vars.cc.orig	2018-05-06 19:16:02 UTC
+++ sql/sys_vars.cc
@@ -4098,7 +4098,7 @@ static Sys_var_charptr Sys_tls_version(
     READ_ONLY GLOBAL_VAR(opt_tls_version), SSL_OPT(OPT_TLS_VERSION),
     IN_FS_CHARSET, "TLSv1,TLSv1.1,TLSv1.2");
 
-#ifndef HAVE_WOLFSSL
+#if !defined(HAVE_WOLFSSL) && !defined(LIBRESSL_VERSION_NUMBER)
 static bool update_fips_mode(sys_var *, THD *, enum_var_type) {
   char ssl_err_string[OPENSSL_ERROR_LENGTH] = {'\0'};
   if (set_fips_mode(opt_ssl_fips_mode, ssl_err_string) != 1) {
@@ -4110,7 +4110,7 @@ static bool update_fips_mode(sys_var *, 
 }
 #endif
 
-#ifdef HAVE_WOLFSSL
+#if defined(HAVE_WOLFSSL) || defined(LIBRESSL_VERSION_NUMBER)
 static const char *ssl_fips_mode_names[] = {"OFF", 0};
 #else
 static const char *ssl_fips_mode_names[] = {"OFF", "ON", "STRICT", 0};
@@ -4121,7 +4121,7 @@ static Sys_var_enum Sys_ssl_fips_mode(
     GLOBAL_VAR(opt_ssl_fips_mode), SSL_OPT(OPT_SSL_FIPS_MODE),
     ssl_fips_mode_names, DEFAULT(0), NO_MUTEX_GUARD, NOT_IN_BINLOG,
     ON_CHECK(NULL),
-#ifndef HAVE_WOLFSSL
+#if !defined(HAVE_WOLFSSL) && !defined(LIBRESSL_VERSION_NUMBER)
     ON_UPDATE(update_fips_mode),
 #else
     ON_UPDATE(NULL),
