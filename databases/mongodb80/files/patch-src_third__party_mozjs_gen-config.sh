--- src/third_party/mozjs/gen-config.sh.orig	2024-07-22 19:17:33 UTC
+++ src/third_party/mozjs/gen-config.sh
@@ -29,6 +29,9 @@ case "$_Path" in
 }
 
 case "$_Path" in
+    "platform/aarch64/freebsd")
+        _CONFIG_OPTS="--host=aarch64-freebsd"
+	;;
     "platform/aarch64/linux")
         _CONFIG_OPTS="--host=aarch64-linux"
     ;;
@@ -109,7 +112,7 @@ CFLAGS="$CFLAGS -D__STDC_FORMAT_MACROS" \
     --disable-js-shell \
     --disable-tests "$_CONFIG_OPTS"
 
-make recurse_export
+gmake recurse_export
 
 cd ../../../..
 
@@ -164,7 +167,7 @@ find "$_Path/build" -name '*.cpp' |
 find "$_Path/build" -name '*.cpp' |
     while read unified_file ; do
         echo "Processing $unified_file"
-        sed $SEDOPTION \
+        gsed $SEDOPTION \
             -e 's|#include ".*/js/src/|#include "|' \
             -e 's|#error ".*/js/src/|#error "|' \
             "$unified_file"
