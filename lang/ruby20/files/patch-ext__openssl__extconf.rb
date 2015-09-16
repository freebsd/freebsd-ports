$OpenBSD: patch-ext_openssl_extconf_rb,v 1.1 2015/08/27 15:55:04 kili Exp $
--- ext/openssl/extconf.rb.orig	Thu Dec 20 08:42:56 2012
+++ ext/openssl/extconf.rb	Thu Aug 27 17:18:32 2015
@@ -103,6 +103,9 @@ have_func("OPENSSL_cleanse")
 have_func("SSLv2_method")
 have_func("SSLv2_server_method")
 have_func("SSLv2_client_method")
+have_func("SSLv3_method")
+have_func("SSLv3_server_method")
+have_func("SSLv3_client_method")
 have_func("TLSv1_1_method")
 have_func("TLSv1_1_server_method")
 have_func("TLSv1_1_client_method")
