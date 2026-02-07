--- m4/glib-gettext.m4.orig	2020-01-23 10:12:04 UTC
+++ m4/glib-gettext.m4
@@ -36,8 +36,8 @@ dnl We go to great lengths to make sure that aclocal w
 dnl try to pull in the installed version of these macros
 dnl when running aclocal in the glib directory.
 dnl
-m4_copy([AC_DEFUN],[glib_DEFUN])
-m4_copy([AC_REQUIRE],[glib_REQUIRE])
+m4_copy_force([AC_DEFUN],[glib_DEFUN])
+m4_copy_force([AC_REQUIRE],[glib_REQUIRE])
 dnl
 dnl At the end, if we're not within glib, we'll define the public
 dnl definitions in terms of our private definitions.
