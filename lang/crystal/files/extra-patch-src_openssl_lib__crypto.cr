--- src/openssl/lib_crypto.cr.orig	2022-04-09 14:20:55.000000000 -0700
+++ src/openssl/lib_crypto.cr	2022-04-09 14:15:51.000000000 -0700
@@ -1,31 +1,7 @@
 {% begin %}
   lib LibCrypto
-    {% if flag?(:win32) %}
-      {% from_libressl = false %}
-      {% ssl_version = nil %}
-      {% for dir in Crystal::LIBRARY_PATH.split(';') %}
-        {% unless ssl_version %}
-          {% config_path = "#{dir.id}\\openssl_VERSION" %}
-          {% if config_version = read_file?(config_path) %}
-            {% ssl_version = config_version.chomp %}
-          {% end %}
-        {% end %}
-      {% end %}
-      {% ssl_version ||= "0.0.0" %}
-    {% else %}
-      {% from_libressl = (`hash pkg-config 2> /dev/null || printf %s false` != "false") &&
-                         (`test -f $(pkg-config --silence-errors --variable=includedir libcrypto)/openssl/opensslv.h || printf %s false` != "false") &&
-                         (`printf "#include <openssl/opensslv.h>\nLIBRESSL_VERSION_NUMBER" | ${CC:-cc} $(pkg-config --cflags --silence-errors libcrypto || true) -E -`.chomp.split('\n').last != "LIBRESSL_VERSION_NUMBER") %}
-      {% ssl_version = `hash pkg-config 2> /dev/null && pkg-config --silence-errors --modversion libcrypto || printf %s 0.0.0`.split.last.gsub(/[^0-9.]/, "") %}
-    {% end %}
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
 
@@ -34,7 +10,7 @@
   @[Link("crypt32")] # CertOpenStore, ...
   @[Link("user32")]  # GetProcessWindowStation, GetUserObjectInformationW, _MessageBoxW
 {% else %}
-  @[Link(ldflags: "`command -v pkg-config > /dev/null && pkg-config --libs --silence-errors libcrypto || printf %s '-lcrypto'`")]
+  @[Link(ldflags: "-LCRYSTAL_SSL_LDFLAGS -lcrypto")]
 {% end %}
 lib LibCrypto
   alias Char = LibC::Char

