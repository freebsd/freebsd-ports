--- m4/efl.m4.orig	2016-09-13 07:23:52 UTC
+++ m4/efl.m4
@@ -219,7 +219,7 @@ AC_DEFUN([EFL_CRYPTO_DEPEND],
 [dnl
 m4_pushdef([DOWNEFL], m4_translit([$1], [-A-Z], [_a-z]))dnl
 requirements_pc_[]m4_defn([DOWNEFL])="${requirements_pc_crypto} ${requirements_pc_[][]m4_defn([DOWNEFL])}"
-requirements_pc_deps_[]m4_defn([DOWNEFL])="${requirements_pc_deps_crypto} ${requirements_pc_deps_[][]m4_defn([DOWNEFL])}"
+requirements_pc_deps_[]m4_defn([DOWNEFL])="${requirements_pc_deps_crypto}${requirements_pc_deps_crypto:+ }${requirements_pc_deps_[][]m4_defn([DOWNEFL])}"
 requirements_libs_[]m4_defn([DOWNEFL])="${requirements_libs_crypto} ${requirements_libs_[][]m4_defn([DOWNEFL])}"
 requirements_cflags_[]m4_defn([DOWNEFL])="${requirements_cflags_crypto} ${requirements_cflags_[][]m4_defn([DOWNEFL])}"
 m4_popdef([DOWNEFL])dnl
