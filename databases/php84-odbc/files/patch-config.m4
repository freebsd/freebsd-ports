--- config.m4.orig	2024-09-10 16:10:06 UTC
+++ config.m4
@@ -117,7 +117,7 @@ PHP_ARG_WITH([adabas],
 PHP_ARG_WITH([adabas],
   [for Adabas support],
   [AS_HELP_STRING([[--with-adabas[=DIR]]],
-    [Include Adabas D support [/usr/local]])])
+    [Include Adabas D support [/usr/local]])], [no], [no])
 
   AS_VAR_IF([PHP_ADABAS], [no], [], [
     AS_VAR_IF([PHP_ADABAS], [yes], [PHP_ADABAS=/usr/local])
@@ -143,7 +143,7 @@ PHP_ARG_WITH([sapdb],
 PHP_ARG_WITH([sapdb],
   [for SAP DB support],
   [AS_HELP_STRING([[--with-sapdb[=DIR]]],
-    [Include SAP DB support [/usr/local]])])
+    [Include SAP DB support [/usr/local]])], [no], [no])
 
   AS_VAR_IF([PHP_SAPDB], [no], [], [
     AS_VAR_IF([PHP_SAPDB], [yes], [PHP_SAPDB=/usr/local])
@@ -160,7 +160,7 @@ PHP_ARG_WITH([solid],
 PHP_ARG_WITH([solid],
   [for Solid support],
   [AS_HELP_STRING([[--with-solid[=DIR]]],
-    [Include Solid support [/usr/local/solid]])])
+    [Include Solid support [/usr/local/solid]])], [no], [no])
 
   AS_VAR_IF([PHP_SOLID], [no], [], [
     AS_VAR_IF([PHP_SOLID], [yes], [PHP_SOLID=/usr/local/solid])
@@ -184,7 +184,7 @@ PHP_ARG_WITH([ibm-db2],
 PHP_ARG_WITH([ibm-db2],
   [for IBM DB2 support],
   [AS_HELP_STRING([[--with-ibm-db2[=DIR]]],
-    [Include IBM DB2 support [/home/db2inst1/sqllib]])])
+    [Include IBM DB2 support [/home/db2inst1/sqllib]])], [no], [no])
 
   AS_VAR_IF([PHP_IBM_DB2], [no], [], [
     AS_VAR_IF([PHP_IBM_DB2], [yes], [
@@ -222,7 +222,7 @@ PHP_ARG_WITH([empress],
   [for Empress support],
   [AS_HELP_STRING([[--with-empress[=DIR]]],
     [Include Empress support $EMPRESSPATH (Empress Version >= 8.60
-    required)])])
+    required)])], [no], [no])
 
   AS_VAR_IF([PHP_EMPRESS], [no], [], [
     AS_VAR_IF([PHP_EMPRESS], [yes], [
@@ -246,7 +246,7 @@ PHP_ARG_WITH([empress-bcs],
   [for Empress local access support],
   [AS_HELP_STRING([[--with-empress-bcs[=DIR]]],
     [Include Empress Local Access support $EMPRESSPATH (Empress Version >=
-    8.60 required)])])
+    8.60 required)])], [no], [no])
 
   AS_VAR_IF([PHP_EMPRESS_BCS], [no], [], [
     AS_VAR_IF([PHP_EMPRESS_BCS], [yes], [
@@ -290,7 +290,7 @@ PHP_ARG_WITH([custom-odbc],
     your include dirs. For example, you should define following for Sybase SQL
     Anywhere 5.5.00 on QNX, prior to running this configure script:
     CPPFLAGS="-DODBC_QNX -DSQLANY_BUG" LDFLAGS=-lunix
-    CUSTOM_ODBC_LIBS="-ldblib -lodbc"])])
+    CUSTOM_ODBC_LIBS="-ldblib -lodbc"])], [no], [no])
 
   AS_VAR_IF([PHP_CUSTOM_ODBC], [no], [], [
     AS_VAR_IF([PHP_CUSTOM_ODBC], [yes], [PHP_CUSTOM_ODBC=/usr/local])
@@ -309,7 +309,7 @@ PHP_ARG_WITH([iodbc],
 PHP_ARG_WITH([iodbc],
   [whether to build with iODBC support],
   [AS_HELP_STRING([--with-iodbc],
-    [Include iODBC support])])
+    [Include iODBC support])], [no], [no])
 
   AS_VAR_IF([PHP_IODBC], [no], [], [
     PKG_CHECK_MODULES([ODBC], [libiodbc])
@@ -324,7 +324,7 @@ PHP_ARG_WITH([esoob],
 PHP_ARG_WITH([esoob],
   [for Easysoft ODBC-ODBC Bridge support],
   [AS_HELP_STRING([[--with-esoob[=DIR]]],
-    [Include Easysoft OOB support [/usr/local/easysoft/oob/client]])])
+    [Include Easysoft OOB support [/usr/local/easysoft/oob/client]])], [no], [no])
 
   AS_VAR_IF([PHP_ESOOB], [no], [], [
     AS_VAR_IF([PHP_ESOOB], [yes], [PHP_ESOOB=/usr/local/easysoft/oob/client])
@@ -371,7 +371,7 @@ PHP_ARG_WITH([dbmaker],
 PHP_ARG_WITH([dbmaker],
   [for DBMaker support],
   [AS_HELP_STRING([[--with-dbmaker[=DIR]]],
-    [Include DBMaker support])])
+    [Include DBMaker support])], [no], [no])
 
   AS_VAR_IF([PHP_DBMAKER], [no], [], [
     AS_VAR_IF([PHP_DBMAKER], [yes], [
