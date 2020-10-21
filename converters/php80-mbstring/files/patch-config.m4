--- config.m4.orig	2019-08-06 06:54:10 UTC
+++ config.m4
@@ -37,6 +37,31 @@ AC_DEFUN([PHP_MBSTRING_EXTENSION], [
 
   out="php_config.h"
 
+  dnl This is PECL build, check if bundled PCRE library is used
+  old_CPPFLAGS=$CPPFLAGS
+  CPPFLAGS=$INCLUDES
+  AC_EGREP_CPP(yes,[
+#include <main/php_config.h>
+#if defined(HAVE_BUNDLED_PCRE) && !defined(COMPILE_DL_PCRE)
+yes
+#endif
+  ],[
+    PHP_PCRE_REGEX=yes
+  ],[
+    AC_EGREP_CPP(yes,[
+#include <main/php_config.h>
+#if defined(HAVE_PCRE) && !defined(COMPILE_DL_PCRE)
+yes
+#endif
+    ],[
+      PHP_PCRE_REGEX=pecl
+      PHP_ADD_INCLUDE($PHP_PCRE_DIR/include)
+    ],[
+      PHP_PCRE_REGEX=no
+    ])
+  ])
+
+
   if test "$ext_shared" != "no" && test -f "$ext_builddir/config.h.in"; then
     out="$abs_builddir/config.h"
   fi
@@ -200,6 +225,9 @@ PHP_ARG_ENABLE([mbregex],
   [yes],
   [no])
 
+PHP_ARG_WITH(pcre-dir, pcre install prefix,
+[  --with-pcre-dir           MBSTRING: pcre install prefix], no, no)
+
 if test "$PHP_MBSTRING" != "no"; then
   AC_DEFINE([HAVE_MBSTRING],1,[whether to have multibyte string support])
 
