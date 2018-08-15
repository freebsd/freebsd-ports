From 75de15ddcdab6efe7faf3ca1f6b5c6e5b6ba57cc Mon Sep 17 00:00:00 2001
From: Kazuki Yamaguchi <k@rhe.jp>
Date: Sat, 24 Mar 2018 01:44:37 +0900
Subject: [PATCH] extconf.rb: fix build with LibreSSL 2.7.0

Our compat implementation of accessor functions that were introduced in
OpenSSL 1.1.0 conflicts with those from LibreSSL 2.7.0. Use the
HAVE_OPAQUE_OPENSSL code path when LibreSSL 2.7 or newer is detected.

Fix suggested by Joel Sing.

Fixes: https://github.com/ruby/openssl/issues/192

--- ext/openssl/extconf.rb.orig
+++ ext/openssl/extconf.rb
@@ -157,8 +157,11 @@ def find_openssl_library
 have_func("SSL_is_server")
 
 # added in 1.1.0
+if !have_struct_member("SSL", "ctx", "openssl/ssl.h") ||
+    try_static_assert("LIBRESSL_VERSION_NUMBER >= 0x2070000fL", "openssl/opensslv.h")
+  $defs.push("-DHAVE_OPAQUE_OPENSSL")
+end
 have_func("CRYPTO_lock") || $defs.push("-DHAVE_OPENSSL_110_THREADING_API")
-have_struct_member("SSL", "ctx", "openssl/ssl.h") || $defs.push("-DHAVE_OPAQUE_OPENSSL")
 have_func("BN_GENCB_new")
 have_func("BN_GENCB_free")
 have_func("BN_GENCB_get_arg")
