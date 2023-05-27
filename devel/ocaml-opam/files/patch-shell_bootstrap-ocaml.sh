--- shell/bootstrap-ocaml.sh.orig	2023-05-27 13:09:27 UTC
+++ shell/bootstrap-ocaml.sh
@@ -42,6 +42,9 @@
   mkdir -p ${V}
 fi
 cd ${V}
+for p in ../../src_ext/ocaml-patches/*.patch; do
+  patch -p1 < $p;
+done;
 PATH_PREPEND=
 LIB_PREPEND=
 INC_PREPEND=
