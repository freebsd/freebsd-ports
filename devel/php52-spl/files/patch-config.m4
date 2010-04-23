--- config.m4.orig	Mon Dec  4 19:01:53 2006
+++ config.m4	Wed Feb  7 12:21:20 2007
@@ -4,6 +4,11 @@
 PHP_ARG_ENABLE(spl, enable SPL suppport,
 [  --disable-spl           Disable Standard PHP Library], yes)
 
+if test -z "$PHP_LIBXML_DIR"; then
+  PHP_ARG_WITH(libxml-dir, libxml2 install dir,
+  [  --with-libxml-dir=DIR     SPL: libxml2 install prefix], no, no)
+fi
+
 if test "$PHP_SPL" != "no"; then
   AC_MSG_CHECKING(whether zend_object_value is packed)
   old_CPPFLAGS=$CPPFLAGS
@@ -25,8 +30,12 @@
   ])
   CPPFLAGS=$old_CPPFLAGS
   AC_DEFINE_UNQUOTED(HAVE_PACKED_OBJECT_VALUE, $ac_result, [Whether struct _zend_object_value is packed])
+  PHP_SETUP_LIBXML(DOM_SHARED_LIBADD, [
   AC_DEFINE(HAVE_SPL, 1, [Whether you want SPL (Standard PHP Library) support]) 
-  PHP_NEW_EXTENSION(spl, php_spl.c spl_functions.c spl_engine.c spl_iterators.c spl_array.c spl_directory.c spl_sxe.c spl_exceptions.c spl_observer.c, no)
+  PHP_NEW_EXTENSION(spl, php_spl.c spl_functions.c spl_engine.c spl_iterators.c spl_array.c spl_directory.c spl_sxe.c spl_exceptions.c spl_observer.c, yes)
   PHP_INSTALL_HEADERS([ext/spl], [php_spl.h spl_array.h spl_directory.h spl_engine.h spl_exceptions.h spl_functions.h spl_iterators.h spl_observer.h spl_sxe.h])
   PHP_ADD_EXTENSION_DEP(spl, pcre, true)
+  ], [
+    AC_MSG_ERROR([xml2-config not found. Please check your libxml2 installation.])
+  ])
 fi
