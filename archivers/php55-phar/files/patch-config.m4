--- config.m4.orig	2011-11-25 15:31:20.000000000 +0100
+++ config.m4	2011-11-25 15:47:45.000000000 +0100
@@ -4,8 +4,38 @@
 PHP_ARG_ENABLE(phar, for phar archive support,
 [  --disable-phar          Disable phar support], yes)
 
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
   PHP_NEW_EXTENSION(phar, util.c tar.c zip.c stream.c func_interceptors.c dirstream.c phar.c phar_object.c phar_path_check.c, $ext_shared)
+  PHP_HASH=yes
   AC_MSG_CHECKING([for phar openssl support])
   if test "$PHP_HASH_SHARED" != "yes"; then
     if test "$PHP_HASH" != "no"; then
