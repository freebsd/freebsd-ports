--- src/openssl/lib_ssl.cr.orig	2022-04-09 14:24:40.000000000 -0700
+++ src/openssl/lib_ssl.cr	2022-04-09 14:24:07.000000000 -0700
@@ -6,32 +6,8 @@
 
 {% begin %}
   lib LibSSL
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
-                         (`test -f $(pkg-config --silence-errors --variable=includedir libssl)/openssl/opensslv.h || printf %s false` != "false") &&
-                         (`printf "#include <openssl/opensslv.h>\nLIBRESSL_VERSION_NUMBER" | ${CC:-cc} $(pkg-config --cflags --silence-errors libssl || true) -E -`.chomp.split('\n').last != "LIBRESSL_VERSION_NUMBER") %}
-      {% ssl_version = `hash pkg-config 2> /dev/null && pkg-config --silence-errors --modversion libssl || printf %s 0.0.0`.split.last.gsub(/[^0-9.]/, "") %}
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
 
-@[Link(ldflags: "`command -v pkg-config > /dev/null && pkg-config --libs --silence-errors libssl || printf %s '-lssl -lcrypto'`")]
+@[Link(ldflags: "-LCRYSTAL_SSL_LDFLAGS -lssl")]
 lib LibSSL
   alias Int = LibC::Int
   alias Char = LibC::Char
