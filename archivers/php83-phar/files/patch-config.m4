--- config.m4.orig	2023-06-06 15:54:29 UTC
+++ config.m4
@@ -4,8 +4,38 @@ PHP_ARG_ENABLE([phar],
     [Disable phar support])],
   [yes])
 
+PHP_ARG_WITH(pcre-dir, pcre install prefix,
+[  --with-pcre-dir           PHAR: pcre install prefix], no, no)
+
+
 if test "$PHP_PHAR" != "no"; then
+
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
   PHP_NEW_EXTENSION(phar, util.c tar.c zip.c stream.c func_interceptors.c dirstream.c phar.c phar_object.c phar_path_check.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
+  PHP_HASH=yes
   AC_MSG_CHECKING([for phar openssl support])
   if test "$PHP_OPENSSL_SHARED" = "yes"; then
     AC_MSG_RESULT([no (shared openssl)])
