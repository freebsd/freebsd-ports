--- include/violite.h.orig	2021-12-17 16:07:27 UTC
+++ include/violite.h
@@ -268,9 +268,11 @@ struct st_VioSSLFd *new_VioSSLConnectorFd(
 
 long process_tls_version(const char *tls_version);
 
+#ifndef LIBRESSL_VERSION_NUMBER
 int set_fips_mode(const uint fips_mode, char *err_string);
 
 uint get_fips_mode();
+#endif
 
 int test_ssl_fips_mode(char *err_string);
 
