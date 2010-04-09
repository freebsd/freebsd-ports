--- sapi/cgi/config9.m4.orig	2007-10-01 14:40:54.000000000 +0200
+++ sapi/cgi/config9.m4	2008-09-25 23:07:13.000000000 +0200
@@ -8,7 +8,6 @@
 dnl
 dnl CGI setup
 dnl
-if test "$PHP_SAPI" = "default"; then
   AC_MSG_CHECKING(whether to build CGI binary)
   if test "$PHP_CGI" != "no"; then
     AC_MSG_RESULT(yes)
@@ -53,8 +52,9 @@
     PHP_SUBST(SAPI_CGI_PATH)
 
     dnl Set install target and select SAPI
-    INSTALL_IT="@echo \"Installing PHP CGI binary: \$(INSTALL_ROOT)\$(bindir)/\"; \$(INSTALL) -m 0755 \$(SAPI_CGI_PATH) \$(INSTALL_ROOT)\$(bindir)/\$(program_prefix)php-cgi\$(program_suffix)\$(EXEEXT)"
-    PHP_SELECT_SAPI(cgi, program, cgi_main.c fastcgi.c,, '$(SAPI_CGI_PATH)')
+    INSTALL_CGI="@echo \"Installing PHP CGI binary: \$(INSTALL_ROOT)\$(bindir)/\"; \$(INSTALL) -m 0755 \$(SAPI_CGI_PATH) \$(INSTALL_ROOT)\$(bindir)/\$(program_prefix)php-cgi\$(program_suffix)\$(EXEEXT)"
+    PHP_ADD_SOURCES(sapi/cgi, cgi_main.c fastcgi.c,, cgi)
+    PHP_ADD_SOURCES(/main, internal_functions.c,,cgi)
 
     case $host_alias in
       *aix*)
@@ -64,17 +64,29 @@
         BUILD_CGI="\$(CC) \$(CFLAGS_CLEAN) \$(EXTRA_CFLAGS) \$(EXTRA_LDFLAGS_PROGRAM) \$(LDFLAGS) \$(NATIVE_RPATHS) \$(PHP_GLOBAL_OBJS:.lo=.o) \$(PHP_SAPI_OBJS:.lo=.o) \$(PHP_FRAMEWORKS) \$(EXTRA_LIBS) \$(ZEND_EXTRA_LIBS) -o \$(SAPI_CGI_PATH)"
       ;;
       *)
-        BUILD_CGI="\$(LIBTOOL) --mode=link \$(CC) -export-dynamic \$(CFLAGS_CLEAN) \$(EXTRA_CFLAGS) \$(EXTRA_LDFLAGS_PROGRAM) \$(LDFLAGS) \$(PHP_RPATHS) \$(PHP_GLOBAL_OBJS) \$(PHP_SAPI_OBJS) \$(EXTRA_LIBS) \$(ZEND_EXTRA_LIBS) -o \$(SAPI_CGI_PATH)"
+        BUILD_CGI="\$(LIBTOOL) --mode=link \$(CC) -export-dynamic \$(CFLAGS_CLEAN) \$(EXTRA_CFLAGS) \$(EXTRA_LDFLAGS_PROGRAM) \$(LDFLAGS) \$(PHP_RPATHS) \$(PHP_GLOBAL_OBJS) \$(PHP_CGI_OBJS) \$(EXTRA_LIBS) \$(ZEND_EXTRA_LIBS) -o \$(SAPI_CGI_PATH)"
       ;;
     esac
 
+    PHP_CGI_TARGET="\$(SAPI_CGI_PATH)"
+    PHP_INSTALL_CGI_TARGET="install-cgi"
     PHP_SUBST(BUILD_CGI)
-
-  elif test "$PHP_CLI" != "no"; then
-    AC_MSG_RESULT(no)
+    PHP_SUBST(INSTALL_CGI)
+    PHP_SUBST(PHP_CGI_OBJS)
+    PHP_SUBST(PHP_CGI_TARGET)
+    PHP_SUBST(PHP_INSTALL_CGI_TARGET)
+
+    if test "$PHP_SAPI" = "default" ; then
+      PHP_BUILD_PROGRAM($SAPI_CGI_PATH)
+    fi
+ else
+  AC_MSG_RESULT(no)
+  if test "$PHP_SAPI" = "default" ; then
+    if test "$PHP_CLI" != "no" ; then
     OVERALL_TARGET=
     PHP_SAPI=cli   
   else
     AC_MSG_ERROR([No SAPIs selected.])  
   fi
+ fi
 fi
