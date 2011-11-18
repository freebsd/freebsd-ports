--- sapi/fpm/config.m4.orig	2011-06-26 17:48:11.000000000 +0200
+++ sapi/fpm/config.m4	2011-11-18 11:05:21.000000000 +0100
@@ -312,7 +312,7 @@
 
   AC_MSG_CHECKING([for TCP_INFO])
 
-  AC_TRY_COMPILE([ #include <netinet/tcp.h> ], [struct tcp_info ti; int x = TCP_INFO;], [
+  AC_TRY_COMPILE([ #include <netinet/tcp.h> ], [struct tcp_info ti; ti.tcpi_sacked = 0; int x = TCP_INFO;], [
     have_lq=tcp_info
     AC_MSG_RESULT([yes])
   ], [
@@ -333,7 +333,7 @@
       AC_MSG_RESULT([no])
     ])
 
-    if test "$have_lq" = "tcp_info"; then
+    if test "$have_lq" = "so_listenq"; then
       AC_DEFINE([HAVE_LQ_SO_LISTENQ], 1, [do we have SO_LISTENQxxx?])
     fi
   fi
@@ -423,7 +423,9 @@
   
   PHP_FPM_CFLAGS="-I$abs_srcdir/sapi/fpm"
  
-  INSTALL_IT=":"
+  if test "$PHP_SAPI" = "default"; then
+    PHP_SAPI="fpm"
+  fi 
   PHP_FPM_FILES="fpm/fastcgi.c \
     fpm/fpm.c \
     fpm/fpm_children.c \
@@ -449,7 +451,8 @@
     fpm/zlog.c \
   "
 
-  PHP_SELECT_SAPI(fpm, program, $PHP_FPM_FILES $PHP_FPM_TRACE_FILES, $PHP_FPM_CFLAGS, '$(SAPI_FPM_PATH)')
+  PHP_ADD_SOURCES(sapi/fpm, $PHP_FPM_FILES $PHP_FPM_TRACE_FILES, $PHP_FPM_CFLAGS, fpm)
+  PHP_ADD_SOURCES(/main, internal_functions.c,,fpm)
 
   case $host_alias in
       *aix*)
@@ -459,11 +462,19 @@
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
