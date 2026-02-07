--- config.m4.orig	2025-09-09 11:09:59 UTC
+++ config.m4
@@ -15,7 +15,7 @@ PHP_ARG_WITH([ibm-db2],
 PHP_ARG_WITH([ibm-db2],
   [for IBM DB2 support],
   [AS_HELP_STRING([[--with-ibm-db2[=DIR]]],
-    [Include IBM DB2 support [/home/db2inst1/sqllib]])])
+    [Include IBM DB2 support [/home/db2inst1/sqllib]])], [no], [no])
 
   AS_VAR_IF([PHP_IBM_DB2], [no], [], [
     AS_VAR_IF([PHP_IBM_DB2], [yes], [
@@ -57,7 +57,7 @@ PHP_ARG_WITH([custom-odbc],
     your include dirs. For example, you should define following for Sybase SQL
     Anywhere 5.5.00 on QNX, prior to running this configure script:
     CPPFLAGS="-DODBC_QNX -DSQLANY_BUG" LDFLAGS=-lunix
-    CUSTOM_ODBC_LIBS="-ldblib -lodbc"])])
+    CUSTOM_ODBC_LIBS="-ldblib -lodbc"])], [no], [no])
 
   AS_VAR_IF([PHP_CUSTOM_ODBC], [no], [], [
     AS_VAR_IF([PHP_CUSTOM_ODBC], [yes], [PHP_CUSTOM_ODBC=/usr/local])
@@ -76,7 +76,7 @@ PHP_ARG_WITH([iodbc],
 PHP_ARG_WITH([iodbc],
   [whether to build with iODBC support],
   [AS_HELP_STRING([--with-iodbc],
-    [Include iODBC support])])
+    [Include iODBC support])], [no], [no])
 
   AS_VAR_IF([PHP_IODBC], [no], [], [
     PKG_CHECK_MODULES([ODBC], [libiodbc])
