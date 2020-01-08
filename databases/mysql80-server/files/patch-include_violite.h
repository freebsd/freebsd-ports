--- include/violite.h.orig	2019-09-20 08:30:51 UTC
+++ include/violite.h
@@ -269,9 +269,11 @@ struct st_VioSSLFd *new_VioSSLConnectorFd(
 
 long process_tls_version(const char *tls_version);
 
+#ifndef LIBRESSL_VERSION_NUMBER
 int set_fips_mode(const uint fips_mode, char *err_string);
 
 uint get_fips_mode();
+#endif
 
 struct st_VioSSLFd *new_VioSSLAcceptorFd(
     const char *key_file, const char *cert_file, const char *ca_file,
