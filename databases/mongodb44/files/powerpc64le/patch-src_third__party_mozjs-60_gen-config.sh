--- src/third_party/mozjs-60/gen-config.sh.orig	2020-11-24 21:42:33 UTC
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
