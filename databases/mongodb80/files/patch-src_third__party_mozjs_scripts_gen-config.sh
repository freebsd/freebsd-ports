--- src/third_party/mozjs/scripts/gen-config.sh.orig
+++ src/third_party/mozjs/scripts/gen-config.sh
@@ -7,7 +7,7 @@
 if [ $# -ne 2 ]
 then
     echo "Please supply an arch: x86_64, i386, etc and a platform: osx, linux, windows, etc"
-    exit 0;
+    exit 1;
 fi
 
 _BuiltPathPrefix="mozilla-release/js/src/_build/js/src"
@@ -29,6 +29,9 @@
 }
 
 case "$_Path" in
+    "platform/aarch64/freebsd")
+        _CONFIG_OPTS="--host=aarch64-freebsd"
+    ;;
     "platform/aarch64/linux")
         _CONFIG_OPTS="--host=aarch64-linux"
     ;;
@@ -98,7 +101,7 @@
 
 echo "Run configure"
 # The 'ppc64le/linux' platform requires the additional 'CXXFLAGS' and 'CFLAGS' flags to compile
-CXXFLAGS="$CXXFLAGS -D__STDC_FORMAT_MACROS"\
+CXXFLAGS="$CXXFLAGS -D__STDC_FORMAT_MACROS" \
 CFLAGS="$CFLAGS -D__STDC_FORMAT_MACROS" \
 ../configure \
     --disable-jemalloc \
@@ -111,7 +114,7 @@
     --disable-wasm-moz-intgemm \
     "$_CONFIG_OPTS"
 
-make recurse_export
+gmake recurse_export
 
 cd ../../../..
 
@@ -166,7 +169,7 @@
 find "$_Path/build" -name '*.cpp' |
     while read unified_file ; do
         echo "Processing $unified_file"
-        sed $SEDOPTION \
+        gsed $SEDOPTION \
             -e 's|#include ".*/js/src/|#include "|' \
             -e 's|#error ".*/js/src/|#error "|' \
             "$unified_file"
