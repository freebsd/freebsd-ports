--- resources/server/bin/helpers/check-requirements-linux.sh.orig	2024-07-31 20:26:36 UTC
+++ resources/server/bin/helpers/check-requirements-linux.sh
@@ -35,6 +35,9 @@ if [ -f /etc/os-release ]; then
     if [ "$OS_ID" = "nixos" ]; then
         echo "Warning: NixOS detected, skipping GLIBC check"
         exit 0
+    elif [ "$OS_ID" = "freebsd" ]; then
+        echo "Warning: FreeBSD detected, skipping GLIBC check"
+        exit 0
     fi
 fi
 
