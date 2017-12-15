--- config.m4.orig	2016-10-25 15:23:21 UTC
+++ config.m4
@@ -100,13 +100,17 @@ dnl
 dnl configure options
 dnl
 
+PHP_ARG_ENABLE(odbc,,
+[  --enable-odbc             Enable ODBC support with selected driver])
+
+
 PHP_ARG_WITH(odbcver,,
 [  --with-odbcver[=HEX]      Force support for the passed ODBC version. A hex number is expected, default 0x0350.
                              Use the special value of 0 to prevent an explicit ODBCVER to be defined. ], 0x0350)
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(adabas,,
-[  --with-adabas[=DIR]       Include Adabas D support [/usr/local]])
+[  --with-adabas[=DIR]       Include Adabas D support [/usr/local]], no, no)
 
   AC_MSG_CHECKING([for Adabas support])
   if test "$PHP_ADABAS" != "no"; then
@@ -135,7 +139,7 @@ fi
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(sapdb,,
-[  --with-sapdb[=DIR]        Include SAP DB support [/usr/local]])
+[  --with-sapdb[=DIR]        Include SAP DB support [/usr/local]], no, no)
 
   AC_MSG_CHECKING([for SAP DB support])
   if test "$PHP_SAPDB" != "no"; then
@@ -155,7 +159,7 @@ fi
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(solid,,
-[  --with-solid[=DIR]        Include Solid support [/usr/local/solid]])
+[  --with-solid[=DIR]        Include Solid support [/usr/local/solid]], no, no)
 
   AC_MSG_CHECKING(for Solid support)
   if test "$PHP_SOLID" != "no"; then
@@ -182,7 +186,7 @@ fi
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(ibm-db2,,
-[  --with-ibm-db2[=DIR]      Include IBM DB2 support [/home/db2inst1/sqllib]])
+[  --with-ibm-db2[=DIR]      Include IBM DB2 support [/home/db2inst1/sqllib]], no, no)
 
   AC_MSG_CHECKING(for IBM DB2 support)
   if test "$PHP_IBM_DB2" != "no"; then
@@ -221,7 +225,7 @@ fi
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(ODBCRouter,,
-[  --with-ODBCRouter[=DIR]   Include ODBCRouter.com support [/usr]])
+[  --with-ODBCRouter[=DIR]   Include ODBCRouter.com support [/usr]], no, no)
 
   AC_MSG_CHECKING(for ODBCRouter.com support)
   if test "$PHP_ODBCROUTER" != "no"; then
@@ -244,7 +248,7 @@ fi
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(empress,,
 [  --with-empress[=DIR]      Include Empress support [\$EMPRESSPATH]
-                          (Empress Version >= 8.60 required)])
+                          (Empress Version >= 8.60 required)], no, no)
 
   AC_MSG_CHECKING(for Empress support)
   if test "$PHP_EMPRESS" != "no"; then
@@ -270,7 +274,7 @@ if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(empress-bcs,,
 [  --with-empress-bcs[=DIR]
                           Include Empress Local Access support [\$EMPRESSPATH]
-                          (Empress Version >= 8.60 required)])
+                          (Empress Version >= 8.60 required)], no, no)
 
   AC_MSG_CHECKING(for Empress local access support)
   if test "$PHP_EMPRESS_BCS" != "no"; then
@@ -310,7 +314,7 @@ fi
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(birdstep,,
-[  --with-birdstep[=DIR]     Include Birdstep support [/usr/local/birdstep]])
+[  --with-birdstep[=DIR]     Include Birdstep support [/usr/local/birdstep]], no, no)
   
   AC_MSG_CHECKING(for Birdstep support)
   if test "$PHP_BIRDSTEP" != "no"; then
@@ -366,7 +370,7 @@ PHP_ARG_WITH(custom-odbc,,
                           running this configure script:
                             CPPFLAGS=\"-DODBC_QNX -DSQLANY_BUG\"
                             LDFLAGS=-lunix
-                            CUSTOM_ODBC_LIBS=\"-ldblib -lodbc\"])
+                            CUSTOM_ODBC_LIBS=\"-ldblib -lodbc\"], no, no)
 
   AC_MSG_CHECKING(for a custom ODBC support)
   if test "$PHP_CUSTOM_ODBC" != "no"; then
@@ -388,7 +392,7 @@ fi
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(iodbc,,
-[  --with-iodbc[=DIR]        Include iODBC support [/usr/local]])
+[  --with-iodbc[=DIR]        Include iODBC support [/usr/local]], no, no)
 
   AC_MSG_CHECKING(for iODBC support)
   if test "$PHP_IODBC" != "no"; then
@@ -426,7 +430,7 @@ fi
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(esoob,,
-[  --with-esoob[=DIR]        Include Easysoft OOB support [/usr/local/easysoft/oob/client]])
+[  --with-esoob[=DIR]        Include Easysoft OOB support [/usr/local/easysoft/oob/client]], no, no)
 
   AC_MSG_CHECKING(for Easysoft ODBC-ODBC Bridge support)
   if test "$PHP_ESOOB" != "no"; then
@@ -448,7 +452,7 @@ fi
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(unixODBC,,
-[  --with-unixODBC[=DIR]     Include unixODBC support [/usr/local]])
+[  --with-unixODBC[=DIR]     Include unixODBC support [/usr/local]], no, no)
 
   AC_MSG_CHECKING(for unixODBC support)
   if test "$PHP_UNIXODBC" != "no"; then
@@ -471,7 +475,7 @@ fi
 
 if test -z "$ODBC_TYPE"; then
 PHP_ARG_WITH(dbmaker,,
-[  --with-dbmaker[=DIR]      Include DBMaker support])
+[  --with-dbmaker[=DIR]      Include DBMaker support], no, no)
 
   AC_MSG_CHECKING(for DBMaker support)
   if test "$PHP_DBMAKER" != "no"; then
