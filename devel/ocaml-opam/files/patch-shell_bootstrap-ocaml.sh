--- shell/bootstrap-ocaml.sh.orig	2021-12-07 16:13:53 UTC
+++ shell/bootstrap-ocaml.sh
@@ -8,7 +8,6 @@ elif command -v wget > /dev/null; then
   CURL=wget
 else
   echo "This script requires curl or wget"
-  exit 1
 fi
 BOOTSTRAP_DIR=${BOOTSTRAP_DIR:-bootstrap}
 BOOTSTRAP_ROOT=${BOOTSTRAP_ROOT:-..}
@@ -43,6 +42,9 @@ else
   mkdir -p ${V}
 fi
 cd ${V}
+for p in ../../src_ext/ocaml-patches/*.patch; do
+    patch -p1 < $p;
+done;
 PATH_PREPEND=
 LIB_PREPEND=
 INC_PREPEND=
