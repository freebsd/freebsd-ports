--- src/third_party/mozjs-60/gen-config.sh.orig	2020-11-25 13:19:42 UTC
+++ src/third_party/mozjs-60/gen-config.sh
@@ -31,6 +31,9 @@ case "$_Path" in
     "platform/aarch64/linux")
         _CONFIG_OPTS="--host=aarch64-linux"
 	;;
+    "platform/ppc64le/freebsd")
+        _CONFIG_OPTS="--host=ppc64le-freebsd"
+	;;
     "platform/ppc64le/linux")
         _CONFIG_OPTS="--host=ppc64le-linux"
 	;;
@@ -82,9 +85,9 @@ esac
 cd mozilla-release/js/src
 rm config.cache || true
 
-PYTHON=python ./configure --without-intl-api --enable-posix-nspr-emulation --disable-trace-logging --disable-js-shell --disable-tests "$_CONFIG_OPTS"
+PYTHON=python2.7 ./configure --without-intl-api --enable-posix-nspr-emulation --disable-trace-logging --disable-js-shell --disable-tests "$_CONFIG_OPTS"
 
-make recurse_export
+gmake recurse_export
 
 cd ../../..
 
