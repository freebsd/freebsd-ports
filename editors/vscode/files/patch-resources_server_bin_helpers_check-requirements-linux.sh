--- resources/server/bin/helpers/check-requirements-linux.sh.orig	2024-04-08 09:12:23 UTC
+++ resources/server/bin/helpers/check-requirements-linux.sh
@@ -34,6 +34,9 @@ if [ -f /etc/os-release ]; then
     if [ "$OS_ID" = "nixos" ]; then
         echo "Warning: NixOS detected, skipping GLIBC check"
         exit 0
+    elif [ "$OS_ID" = "freebsd" ]; then
+        echo "Warning: FreeBSD detected, skipping GLIBC check"
+        exit 0
     fi
 fi
 
