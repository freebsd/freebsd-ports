--- config.m4.orig	2023-11-07 20:02:05 UTC
+++ config.m4
@@ -102,7 +102,7 @@ PHP_ARG_WITH([adabas],,
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH([adabas],,
   [AS_HELP_STRING([[--with-adabas[=DIR]]],
-    [Include Adabas D support [/usr/local]])])
+    [Include Adabas D support [/usr/local]])], [no], [no])
 
   AC_MSG_CHECKING([for Adabas support])
   if test "$PHP_ADABAS" != "no"; then
@@ -132,7 +132,7 @@ PHP_ARG_WITH([sapdb],,
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH([sapdb],,
   [AS_HELP_STRING([[--with-sapdb[=DIR]]],
-    [Include SAP DB support [/usr/local]])])
+    [Include SAP DB support [/usr/local]])], [no], [no])
 
   AC_MSG_CHECKING([for SAP DB support])
   if test "$PHP_SAPDB" != "no"; then
@@ -153,7 +153,7 @@ PHP_ARG_WITH([solid],,
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH([solid],,
   [AS_HELP_STRING([[--with-solid[=DIR]]],
-    [Include Solid support [/usr/local/solid]])])
+    [Include Solid support [/usr/local/solid]])], [no], [no])
 
   AC_MSG_CHECKING(for Solid support)
   if test "$PHP_SOLID" != "no"; then
@@ -181,7 +181,7 @@ PHP_ARG_WITH([ibm-db2],,
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH([ibm-db2],,
   [AS_HELP_STRING([[--with-ibm-db2[=DIR]]],
-    [Include IBM DB2 support [/home/db2inst1/sqllib]])])
+    [Include IBM DB2 support [/home/db2inst1/sqllib]])], [no], [no])
 
   AC_MSG_CHECKING(for IBM DB2 support)
   if test "$PHP_IBM_DB2" != "no"; then
@@ -222,7 +222,7 @@ PHP_ARG_WITH([empress],,
 PHP_ARG_WITH([empress],,
   [AS_HELP_STRING([[--with-empress[=DIR]]],
     [Include Empress support $EMPRESSPATH (Empress Version >= 8.60
-    required)])])
+    required)])], [no], [no])
 
   AC_MSG_CHECKING(for Empress support)
   if test "$PHP_EMPRESS" != "no"; then
@@ -248,7 +248,7 @@ PHP_ARG_WITH([empress-bcs],,
 PHP_ARG_WITH([empress-bcs],,
   [AS_HELP_STRING([[--with-empress-bcs[=DIR]]],
     [Include Empress Local Access support $EMPRESSPATH (Empress Version >=
-    8.60 required)])])
+    8.60 required)])], [no], [no])
 
   AC_MSG_CHECKING(for Empress local access support)
   if test "$PHP_EMPRESS_BCS" != "no"; then
@@ -294,7 +294,7 @@ PHP_ARG_WITH([custom-odbc],,
     your include dirs. For example, you should define following for Sybase SQL
     Anywhere 5.5.00 on QNX, prior to running this configure script:
     CPPFLAGS="-DODBC_QNX -DSQLANY_BUG" LDFLAGS=-lunix
-    CUSTOM_ODBC_LIBS="-ldblib -lodbc"])])
+    CUSTOM_ODBC_LIBS="-ldblib -lodbc"])], [no], [no])
 
   AC_MSG_CHECKING(for a custom ODBC support)
   if test "$PHP_CUSTOM_ODBC" != "no"; then
@@ -317,7 +317,7 @@ PHP_ARG_WITH([iodbc],,
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH([iodbc],,
   [AS_HELP_STRING([--with-iodbc],
-    [Include iODBC support])])
+    [Include iODBC support])], [no], [no])
 
   AC_MSG_CHECKING(whether to build with iODBC support)
   if test "$PHP_IODBC" != "no"; then
@@ -335,7 +335,7 @@ PHP_ARG_WITH([esoob],,
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH([esoob],,
   [AS_HELP_STRING([[--with-esoob[=DIR]]],
-    [Include Easysoft OOB support [/usr/local/easysoft/oob/client]])])
+    [Include Easysoft OOB support [/usr/local/easysoft/oob/client]])], [no], [no])
 
   AC_MSG_CHECKING(for Easysoft ODBC-ODBC Bridge support)
   if test "$PHP_ESOOB" != "no"; then
@@ -358,7 +358,7 @@ PHP_ARG_WITH([unixODBC],,
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH([unixODBC],,
   [AS_HELP_STRING([--with-unixODBC],
-    [Include unixODBC support])])
+    [Include unixODBC support])], [no], [no])
 
   AC_MSG_CHECKING(whether to build with unixODBC support)
   if test "$PHP_UNIXODBC" != "no"; then
@@ -386,7 +386,7 @@ PHP_ARG_WITH([dbmaker],,
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH([dbmaker],,
   [AS_HELP_STRING([[--with-dbmaker[=DIR]]],
-    [Include DBMaker support])])
+    [Include DBMaker support])], [no], [no])
 
   AC_MSG_CHECKING(for DBMaker support)
   if test "$PHP_DBMAKER" != "no"; then
