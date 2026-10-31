--- tools/deps/crypto_link_flags.sh.orig	2026-10-31 12:04:23 UTC
+++ tools/deps/crypto_link_flags.sh
@@ -67,6 +67,7 @@ if [ "$(sh "$here/detect_libressl.sh" 2>/dev/null)" = 
 if [ "$(sh "$here/detect_libressl.sh" 2>/dev/null)" = "-d:awktuaHostLibressl" ]; then
     if command -v pkg-config >/dev/null 2>&1; then
         flags=$(pkg-config --silence-errors --libs libcrypto 2>/dev/null | tr -d '\n')
+        flags="$flags $(pkg-config --silence-errors --libs libsodium sqlite3 libzstd bzip2 2>/dev/null | tr -d '\n')"
     else
         flags="-lcrypto"
     fi
