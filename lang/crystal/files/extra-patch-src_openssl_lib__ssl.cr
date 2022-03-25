--- src/openssl/lib_ssl.cr.orig	2021-08-08 15:06:09 UTC
+++ src/openssl/lib_ssl.cr
@@ -6,22 +6,12 @@ require "./lib_crypto"
 
 {% begin %}
   lib LibSSL
-    {% from_libressl = (`hash pkg-config 2> /dev/null || printf %s false` != "false") &&
-                       (`test -f $(pkg-config --silence-errors --variable=includedir libssl)/openssl/opensslv.h || printf %s false` != "false") &&
-                       (`printf "#include <openssl/opensslv.h>\nLIBRESSL_VERSION_NUMBER" | ${CC:-cc} $(pkg-config --cflags --silence-errors libssl || true) -E -`.chomp.split('\n').last != "LIBRESSL_VERSION_NUMBER") %}
-    {% ssl_version = `hash pkg-config 2> /dev/null && pkg-config --silence-errors --modversion libssl || printf %s 0.0.0`.split.last.gsub(/[^0-9.]/, "") %}
-
-    {% if from_libressl %}
-      LIBRESSL_VERSION = {{ ssl_version }}
-      OPENSSL_VERSION = "0.0.0"
-    {% else %}
-      LIBRESSL_VERSION = "0.0.0"
-      OPENSSL_VERSION = {{ ssl_version }}
-    {% end %}
+    LIBRESSL_VERSION = "0.0.0"
+    OPENSSL_VERSION = "CRYSTAL_SSL_VERSION"
   end
 {% end %}
 
-@[Link(ldflags: "`command -v pkg-config > /dev/null && pkg-config --libs --silence-errors libssl || printf %s '-lssl -lcrypto'`")]
+@[Link(ldflags: "-LCRYSTAL_SSL_LDFLAGS -lssl")]
 lib LibSSL
   alias Int = LibC::Int
   alias Char = LibC::Char
