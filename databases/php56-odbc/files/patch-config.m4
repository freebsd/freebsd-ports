--- config.m4.orig	2015-03-19 00:19:30.000000000 +0000
+++ config.m4	2015-04-01 08:21:21.242902661 +0000
@@ -100,13 +100,17 @@
 dnl configure options
 dnl
 
+PHP_ARG_ENABLE(odbc,,
+[  --enable-odbc             Enable ODBC support with selected driver])
+
+
 PHP_ARG_WITH(odbcver,,
 [  --with-odbcver[=HEX]      Force support for the passed ODBC version. A hex number is expected, default 0x0300.
                              Use the special value of 0 to prevent an explicit ODBCVER to be defined. ], 0x0300)
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(adabas,,
-[  --with-adabas[=DIR]       Include Adabas D support [/usr/local]])
+[  --with-adabas[=DIR]       Include Adabas D support [/usr/local]], no, no)
 
   if test "$PHP_ADABAS" != "no"; then
     AC_MSG_CHECKING([for Adabas support])
@@ -133,7 +137,7 @@
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(sapdb,,
-[  --with-sapdb[=DIR]        Include SAP DB support [/usr/local]])
+[  --with-sapdb[=DIR]        Include SAP DB support [/usr/local]], no, no)
 
   if test "$PHP_SAPDB" != "no"; then
     AC_MSG_CHECKING([for SAP DB support])
@@ -151,7 +155,7 @@
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(solid,,
-[  --with-solid[=DIR]        Include Solid support [/usr/local/solid]])
+[  --with-solid[=DIR]        Include Solid support [/usr/local/solid]], no, no)
 
   if test "$PHP_SOLID" != "no"; then
     AC_MSG_CHECKING(for Solid support)
@@ -176,7 +180,7 @@
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(ibm-db2,,
-[  --with-ibm-db2[=DIR]      Include IBM DB2 support [/home/db2inst1/sqllib]])
+[  --with-ibm-db2[=DIR]      Include IBM DB2 support [/home/db2inst1/sqllib]], no, no)
 
   if test "$PHP_IBM_DB2" != "no"; then
     AC_MSG_CHECKING(for IBM DB2 support)
@@ -213,7 +217,7 @@
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(ODBCRouter,,
-[  --with-ODBCRouter[=DIR]   Include ODBCRouter.com support [/usr]])
+[  --with-ODBCRouter[=DIR]   Include ODBCRouter.com support [/usr]], no, no)
 
   if test "$PHP_ODBCROUTER" != "no"; then
     AC_MSG_CHECKING(for ODBCRouter.com support)
@@ -234,7 +238,7 @@
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(empress,,
 [  --with-empress[=DIR]      Include Empress support [\$EMPRESSPATH]
-                          (Empress Version >= 8.60 required)])
+                          (Empress Version >= 8.60 required)], no, no)
 
   if test "$PHP_EMPRESS" != "no"; then
     AC_MSG_CHECKING(for Empress support)
@@ -258,7 +262,7 @@
 PHP_ARG_WITH(empress-bcs,,
 [  --with-empress-bcs[=DIR]
                           Include Empress Local Access support [\$EMPRESSPATH]
-                          (Empress Version >= 8.60 required)])
+                          (Empress Version >= 8.60 required)], no, no)
 
   if test "$PHP_EMPRESS_BCS" != "no"; then
     AC_MSG_CHECKING(for Empress local access support)
@@ -296,7 +300,7 @@
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(birdstep,,
-[  --with-birdstep[=DIR]     Include Birdstep support [/usr/local/birdstep]])
+[  --with-birdstep[=DIR]     Include Birdstep support [/usr/local/birdstep]], no, no)
   
   if test "$PHP_BIRDSTEP" != "no"; then
     AC_MSG_CHECKING(for Birdstep support)
@@ -350,7 +354,7 @@
                           running this configure script:
                             CPPFLAGS=\"-DODBC_QNX -DSQLANY_BUG\"
                             LDFLAGS=-lunix
-                            CUSTOM_ODBC_LIBS=\"-ldblib -lodbc\"])
+                            CUSTOM_ODBC_LIBS=\"-ldblib -lodbc\"], no, no)
 
   if test "$PHP_CUSTOM_ODBC" != "no"; then
     AC_MSG_CHECKING(for a custom ODBC support)
@@ -370,7 +374,7 @@
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(iodbc,,
-[  --with-iodbc[=DIR]        Include iODBC support])
+[  --with-iodbc[=DIR]        Include iODBC support], no, no)
 
   if test "$PHP_IODBC" != "no"; then
     AC_MSG_CHECKING(for iODBC support)
@@ -406,7 +410,7 @@
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(esoob,,
-[  --with-esoob[=DIR]        Include Easysoft OOB support [/usr/local/easysoft/oob/client]])
+[  --with-esoob[=DIR]        Include Easysoft OOB support [/usr/local/easysoft/oob/client]], no, no)
 
   if test "$PHP_ESOOB" != "no"; then
     AC_MSG_CHECKING(for Easysoft ODBC-ODBC Bridge support)
@@ -426,7 +430,7 @@
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(unixODBC,,
-[  --with-unixODBC[=DIR]     Include unixODBC support [/usr/local]])
+[  --with-unixODBC[=DIR]     Include unixODBC support [/usr/local]], no, no)
 
   if test "$PHP_UNIXODBC" != "no"; then
     AC_MSG_CHECKING(for unixODBC support)
@@ -447,7 +451,7 @@
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(dbmaker,,
-[  --with-dbmaker[=DIR]      Include DBMaker support])
+[  --with-dbmaker[=DIR]      Include DBMaker support], no, no)
 
   if test "$PHP_DBMAKER" != "no"; then
     AC_MSG_CHECKING(for DBMaker support)
