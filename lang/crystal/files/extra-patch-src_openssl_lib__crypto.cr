--- src/openssl/lib_crypto.cr.orig	2021-08-08 15:06:11 UTC
+++ src/openssl/lib_crypto.cr
@@ -1,21 +1,11 @@
 {% begin %}
   lib LibCrypto
-    {% from_libressl = (`hash pkg-config 2> /dev/null || printf %s false` != "false") &&
-                       (`test -f $(pkg-config --silence-errors --variable=includedir libcrypto)/openssl/opensslv.h || printf %s false` != "false") &&
-                       (`printf "#include <openssl/opensslv.h>\nLIBRESSL_VERSION_NUMBER" | ${CC:-cc} $(pkg-config --cflags --silence-errors libcrypto || true) -E -`.chomp.split('\n').last != "LIBRESSL_VERSION_NUMBER") %}
-    {% ssl_version = `hash pkg-config 2> /dev/null && pkg-config --silence-errors --modversion libcrypto || printf %s 0.0.0`.split.last.gsub(/[^0-9.]/, "") %}
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
 
-@[Link(ldflags: "`command -v pkg-config > /dev/null && pkg-config --libs --silence-errors libcrypto || printf %s '-lcrypto'`")]
+@[Link(ldflags: "-LCRYSTAL_SSL_LDFLAGS -lcrypto")]
 lib LibCrypto
   alias Char = LibC::Char
   alias Int = LibC::Int
