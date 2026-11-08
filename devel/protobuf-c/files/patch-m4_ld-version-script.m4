--- m4/ld-version-script.m4.orig	2026-09-22 18:12:13 UTC
+++ m4/ld-version-script.m4
@@ -40,7 +40,7 @@ EOF
         global: sym;
 } VERS_1;
 EOF
-      AC_LINK_IFELSE([AC_LANG_PROGRAM([], [])],
+      AC_LINK_IFELSE([AC_LANG_PROGRAM([[int sym;]], [])],
                      [have_ld_version_script=yes], [have_ld_version_script=no])
     else
       have_ld_version_script=no
