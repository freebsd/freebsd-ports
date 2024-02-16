--- resources/server/bin/helpers/check-requirements-linux.sh.orig	2024-02-16 05:42:44 UTC
+++ resources/server/bin/helpers/check-requirements-linux.sh
@@ -29,6 +29,9 @@ if [ "$OS_ID" = "nixos" ]; then
 if [ "$OS_ID" = "nixos" ]; then
   echo "Warning: NixOS detected, skipping GLIBC check"
   exit 0
+elif [ "$OS_ID" = "freebsd" ]; then
+  echo "Warning: FreeBSD detected, skipping GLIBC check"
+  exit 0
 fi
 
 # Based on https://github.com/bminor/glibc/blob/520b1df08de68a3de328b65a25b86300a7ddf512/elf/cache.c#L162-L245
