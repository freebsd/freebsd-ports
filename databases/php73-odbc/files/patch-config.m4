--- config.m4.orig	2018-09-25 09:07:57 UTC
+++ config.m4
@@ -97,6 +97,9 @@ AC_DEFUN([PHP_ODBC_FIND_EMPRESS_BCS_LIBS
 dnl
 dnl configure options
 dnl
+PHP_ARG_ENABLE(odbc,,
+[  --enable-odbc             Enable ODBC support with selected driver])
+
 
 PHP_ARG_WITH(odbcver,,
 [  --with-odbcver[=HEX]      Force support for the passed ODBC version. A hex number is expected, default 0x0350.
@@ -104,7 +107,7 @@ PHP_ARG_WITH(odbcver,,
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(adabas,,
-[  --with-adabas[=DIR]       Include Adabas D support [/usr/local]])
+[  --with-adabas[=DIR]       Include Adabas D support [/usr/local]], no, no)
 
   AC_MSG_CHECKING([for Adabas support])
   if test "$PHP_ADABAS" != "no"; then
@@ -133,7 +136,7 @@ fi
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(sapdb,,
-[  --with-sapdb[=DIR]        Include SAP DB support [/usr/local]])
+[  --with-sapdb[=DIR]        Include SAP DB support [/usr/local]], no, no)
 
   AC_MSG_CHECKING([for SAP DB support])
   if test "$PHP_SAPDB" != "no"; then
@@ -153,7 +156,7 @@ fi
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(solid,,
-[  --with-solid[=DIR]        Include Solid support [/usr/local/solid]])
+[  --with-solid[=DIR]        Include Solid support [/usr/local/solid]], no, no)
 
   AC_MSG_CHECKING(for Solid support)
   if test "$PHP_SOLID" != "no"; then
@@ -180,7 +183,7 @@ fi
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(ibm-db2,,
-[  --with-ibm-db2[=DIR]      Include IBM DB2 support [/home/db2inst1/sqllib]])
+[  --with-ibm-db2[=DIR]      Include IBM DB2 support [/home/db2inst1/sqllib]], no, no)
 
   AC_MSG_CHECKING(for IBM DB2 support)
   if test "$PHP_IBM_DB2" != "no"; then
@@ -220,7 +223,7 @@ fi
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(empress,,
 [  --with-empress[=DIR]      Include Empress support [\$EMPRESSPATH]
-                          (Empress Version >= 8.60 required)])
+                          (Empress Version >= 8.60 required)], no, no)
 
   AC_MSG_CHECKING(for Empress support)
   if test "$PHP_EMPRESS" != "no"; then
@@ -245,7 +248,7 @@ fi
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(empress-bcs,,
 [  --with-empress-bcs[=DIR]  Include Empress Local Access support [\$EMPRESSPATH]
-                          (Empress Version >= 8.60 required)])
+                          (Empress Version >= 8.60 required)], no, no)
 
   AC_MSG_CHECKING(for Empress local access support)
   if test "$PHP_EMPRESS_BCS" != "no"; then
@@ -292,7 +295,7 @@ PHP_ARG_WITH(custom-odbc,,
                           running this configure script:
                             CPPFLAGS=\"-DODBC_QNX -DSQLANY_BUG\"
                             LDFLAGS=-lunix
-                            CUSTOM_ODBC_LIBS=\"-ldblib -lodbc\"])
+                            CUSTOM_ODBC_LIBS=\"-ldblib -lodbc\"], no, no)
 
   AC_MSG_CHECKING(for a custom ODBC support)
   if test "$PHP_CUSTOM_ODBC" != "no"; then
@@ -314,7 +317,7 @@ fi
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(iodbc,,
-[  --with-iodbc[=DIR]        Include iODBC support [/usr/local]])
+[  --with-iodbc[=DIR]        Include iODBC support [/usr/local]], no, no)
 
   AC_MSG_CHECKING(for iODBC support)
   if test "$PHP_IODBC" != "no"; then
@@ -352,7 +355,7 @@ fi
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(esoob,,
-[  --with-esoob[=DIR]        Include Easysoft OOB support [/usr/local/easysoft/oob/client]])
+[  --with-esoob[=DIR]        Include Easysoft OOB support [/usr/local/easysoft/oob/client]], no, no)
 
   AC_MSG_CHECKING(for Easysoft ODBC-ODBC Bridge support)
   if test "$PHP_ESOOB" != "no"; then
@@ -374,7 +377,7 @@ fi
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(unixODBC,,
-[  --with-unixODBC[=DIR]     Include unixODBC support [/usr/local]])
+[  --with-unixODBC[=DIR]     Include unixODBC support [/usr/local]], no, no)
 
   AC_MSG_CHECKING(for unixODBC support)
   if test "$PHP_UNIXODBC" != "no"; then
@@ -397,7 +400,7 @@ fi
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(dbmaker,,
-[  --with-dbmaker[=DIR]      Include DBMaker support])
+[  --with-dbmaker[=DIR]      Include DBMaker support], no, no)
 
   AC_MSG_CHECKING(for DBMaker support)
   if test "$PHP_DBMAKER" != "no"; then
