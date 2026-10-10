--- src/third_party/mozjs/scripts/gen-config.sh.orig
+++ src/third_party/mozjs/scripts/gen-config.sh
@@ -29,6 +29,15 @@ _xcode_setup() {
 }
 
 case "$_Path" in
+    "platform/aarch64/freebsd")
+        _CONFIG_OPTS="--host=aarch64-freebsd"
+    ;;
+    "platform/ppc64le/freebsd")
+        _CONFIG_OPTS="--host=ppc64le-freebsd"
+    ;;
+    "platform/x86_64/freebsd")
+        _CONFIG_OPTS="--host=x86_64-freebsd"
+    ;;
     "platform/aarch64/linux")
         _CONFIG_OPTS="--host=aarch64-linux"
     ;;
@@ -73,7 +82,7 @@ rm config.cache || true
 
 echo "Run configure"
 # The 'ppc64le/linux' platform requires the additional 'CXXFLAGS' and 'CFLAGS' flags to compile
-CXXFLAGS="$CXXFLAGS -D__STDC_FORMAT_MACROS"\
+CXXFLAGS="$CXXFLAGS -D__STDC_FORMAT_MACROS" \
 CFLAGS="$CFLAGS -D__STDC_FORMAT_MACROS" \
 ../configure \
     --disable-jemalloc \
@@ -86,7 +95,7 @@ CFLAGS="$CFLAGS -D__STDC_FORMAT_MACROS" \
     --disable-wasm-moz-intgemm \
     "$_CONFIG_OPTS"
 
-make recurse_export
+gmake recurse_export
 
 cd ../../../..
 
@@ -141,7 +150,7 @@ fi
 find "$_Path/build" -name '*.cpp' |
     while read unified_file ; do
         echo "Processing $unified_file"
-        sed "${SEDOPTION[@]}" \
+        gsed "${SEDOPTION[@]}" \
             -e 's|#include ".*/js/src/|#include "|' \
             -e 's|#error ".*/js/src/|#error "|' \
             "$unified_file"
