--- utils/llvm-targets/gen-data-layout.sh.orig	2022-02-08 06:25:08 UTC
+++ utils/llvm-targets/gen-data-layout.sh
@@ -93,7 +93,7 @@ TARGETS=(
     #########################

     # FreeBSD amd64
-    "amd64-portbld-freebsd"
+    "x86_64-portbld-freebsd"
     "x86_64-unknown-freebsd" # See #15718

     # FreeBSD ARM
