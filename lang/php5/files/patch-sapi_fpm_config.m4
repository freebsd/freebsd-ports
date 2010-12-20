--- sapi/fpm/config.m4.orig	2010-11-26 14:46:15.000000000 +0100
+++ sapi/fpm/config.m4	2010-12-17 15:22:19.000000000 +0100
@@ -394,7 +394,9 @@
   
   PHP_FPM_CFLAGS="-I$abs_srcdir/sapi/fpm"
  
-  INSTALL_IT=":"
+  if test "$PHP_SAPI" = "default"; then
+    PHP_SAPI="fpm"
+  fi 
   PHP_FPM_FILES="fpm/fastcgi.c \
     fpm/fpm.c \
     fpm/fpm_children.c \
@@ -419,7 +421,8 @@
     fpm/zlog.c \
   "
 
-  PHP_SELECT_SAPI(fpm, program, $PHP_FPM_FILES $PHP_FPM_TRACE_FILES, $PHP_FPM_CFLAGS, '$(SAPI_FPM_PATH)')
+  PHP_ADD_SOURCES(sapi/fpm, $PHP_FPM_FILES $PHP_FPM_TRACE_FILES, $PHP_FPM_CFLAGS, fpm)
+  PHP_ADD_SOURCES(/main, internal_functions.c,,fpm)
 
   case $host_alias in
       *aix*)
@@ -429,11 +432,19 @@
         BUILD_FPM="\$(CC) \$(CFLAGS_CLEAN) \$(EXTRA_CFLAGS) \$(EXTRA_LDFLAGS_PROGRAM) \$(LDFLAGS) \$(NATIVE_RPATHS) \$(PHP_GLOBAL_OBJS:.lo=.o) \$(PHP_SAPI_OBJS:.lo=.o) \$(PHP_FRAMEWORKS) \$(EXTRA_LIBS) \$(SAPI_EXTRA_LIBS) \$(ZEND_EXTRA_LIBS) -o \$(SAPI_FPM_PATH)"
       ;;
       *)
-        BUILD_FPM="\$(LIBTOOL) --mode=link \$(CC) -export-dynamic \$(CFLAGS_CLEAN) \$(EXTRA_CFLAGS) \$(EXTRA_LDFLAGS_PROGRAM) \$(LDFLAGS) \$(PHP_RPATHS) \$(PHP_GLOBAL_OBJS) \$(PHP_SAPI_OBJS) \$(EXTRA_LIBS) \$(SAPI_EXTRA_LIBS) \$(ZEND_EXTRA_LIBS) -o \$(SAPI_FPM_PATH)"
+        BUILD_FPM="\$(LIBTOOL) --mode=link \$(CC) -export-dynamic \$(CFLAGS_CLEAN) \$(EXTRA_CFLAGS) \$(EXTRA_LDFLAGS_PROGRAM) \$(LDFLAGS) \$(PHP_RPATHS) \$(PHP_GLOBAL_OBJS) \$(PHP_FPM_OBJS) \$(EXTRA_LIBS) \$(ZEND_EXTRA_LIBS) -o \$(SAPI_FPM_PATH)"
       ;;
   esac
 
+  PHP_FPM_TARGET="\$(SAPI_FPM_PATH)"
+  PHP_INSTALL_FPM_TARGET="install-fpm"
   PHP_SUBST(BUILD_FPM)
+  PHP_SUBST(PHP_FPM_OBJS)
+  PHP_SUBST(PHP_FPM_TARGET)
+  PHP_SUBST(PHP_INSTALL_FPM_TARGET)
+  if test "$PHP_SAPI" = "fpm" ; then
+    PHP_BUILD_PROGRAM($SAPI_FPM_PATH)
+  fi
 else
   AC_MSG_RESULT(no)
 fi
