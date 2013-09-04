--- extconf.rb.orig	2008-09-10 14:37:10.000000000 +1000
+++ extconf.rb	2008-09-10 14:38:20.000000000 +1000
@@ -59,10 +59,10 @@
 ###########################################################
 
 ### Linux + Free TDS (freetds-0.64 or above) ################
-# sybase = "/usr/local/freetds"
-# $CFLAGS = "-g -Wall -DFREETDS -I#{sybase}/include"
-# $LDFLAGS = " -L#{sybase}/lib " 
-# $LOCAL_LIBS = "-lct  -lsybdb -ltds -rdynamic -ldl -lnsl -lm"
+ sybase = "%%LOCALBASE%%"
+ $CFLAGS = "-g -Wall -DFREETDS -I#{sybase}/include"
+ $LDFLAGS = " -L#{sybase}/lib " 
+ $LOCAL_LIBS = "-lct  -lsybdb -ltds -rdynamic -lm %%ICONV_LIB%%"
 
 ### mac-osx-tiger + Free TDS (freetds-0.64 ) ################
 # sybase = "/usr/local/freetds"
