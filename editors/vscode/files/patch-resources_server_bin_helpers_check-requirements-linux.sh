--- resources/server/bin/helpers/check-requirements-linux.sh.orig	2024-02-27 22:50:23 UTC
+++ resources/server/bin/helpers/check-requirements-linux.sh
@@ -29,6 +29,9 @@ if [ -f /etc/os-release ]; then
     if [ "$OS_ID" = "nixos" ]; then
         echo "Warning: NixOS detected, skipping GLIBC check"
         exit 0
+    elif [ "$OS_ID" = "freebsd" ]; then
+        echo "Warning: FreeBSD detected, skipping GLIBC check"
+        exit 0
     fi
 fi
 
