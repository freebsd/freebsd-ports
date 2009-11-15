--- ./gl/m4/strndup.m4.orig	2009-11-02 14:09:57.000000000 -0500
+++ ./gl/m4/strndup.m4	2009-11-15 15:34:14.000000000 -0500
@@ -9,7 +9,7 @@
   dnl Persuade glibc <string.h> to declare strndup().
   AC_REQUIRE([AC_USE_SYSTEM_EXTENSIONS])
 
-  AC_REQUIRE([gl_HEADER_STRING_H_DEFAULTS])
+  dnl AC_REQUIRE([gl_HEADER_STRING_H_DEFAULTS])
   AC_CHECK_DECLS_ONCE([strndup])
   if test $ac_cv_have_decl_strndup = no; then
     HAVE_DECL_STRNDUP=0
