--- src/third_party/mozjs/gen-config.sh.orig	2025-05-13 16:37:03 UTC
+++ src/third_party/mozjs/gen-config.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 
 set -e
 set -v
@@ -29,6 +29,9 @@ case "$_Path" in
 }
 
 case "$_Path" in
+    "platform/aarch64/freebsd")
+        _CONFIG_OPTS="--host=aarch64-freebsd"
+	;;
     "platform/aarch64/linux")
         _CONFIG_OPTS="--host=aarch64-linux"
     ;;
@@ -111,7 +114,7 @@ CFLAGS="$CFLAGS -D__STDC_FORMAT_MACROS" \
     --disable-wasm-moz-intgemm \
     "$_CONFIG_OPTS"
 
-make recurse_export
+gmake recurse_export
 
 cd ../../../..
 
@@ -166,7 +169,7 @@ find "$_Path/build" -name '*.cpp' |
 find "$_Path/build" -name '*.cpp' |
     while read unified_file ; do
         echo "Processing $unified_file"
-        sed $SEDOPTION \
+        gsed $SEDOPTION \
             -e 's|#include ".*/js/src/|#include "|' \
             -e 's|#error ".*/js/src/|#error "|' \
             "$unified_file"
