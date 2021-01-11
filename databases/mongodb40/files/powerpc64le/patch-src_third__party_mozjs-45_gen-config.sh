--- src/third_party/mozjs-45/gen-config.sh.orig	2020-11-30 15:51:50 UTC
+++ src/third_party/mozjs-45/gen-config.sh
@@ -27,6 +27,9 @@ case "$_Path" in
     "platform/aarch64/linux")
         _CONFIG_OPTS="--host=aarch64-linux"
 	;;
+    "platform/ppc64le/freebsd")
+        _CONFIG_OPTS="--host=ppc64le-freebsd"
+	;;
     "platform/ppc64le/linux")
         _CONFIG_OPTS="--host=ppc64le-linux"
 	;;
@@ -81,7 +84,7 @@ esac
 cd mozilla-release/js/src
 rm config.cache
 
-PYTHON=python ./configure --without-x --without-intl-api --enable-posix-nspr-emulation --disable-trace-logging "$_CONFIG_OPTS"
+PYTHON=python2.7 ./configure --without-x --without-intl-api --enable-posix-nspr-emulation --disable-trace-logging "$_CONFIG_OPTS"
 
 cd ../../..
 
