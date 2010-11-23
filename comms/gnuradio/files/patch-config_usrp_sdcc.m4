--- config/usrp_sdcc.m4.orig	2010-11-19 20:32:17.000000000 -0500
+++ config/usrp_sdcc.m4	2010-11-19 20:33:49.000000000 -0500
@@ -21,7 +21,7 @@
 [
 	sdccok=yes
 	AC_CHECK_PROG(XCC, sdcc, sdcc -mmcs51 --no-xinit-opt,no)
-	AC_CHECK_PROG(XAS, asx8051, asx8051 -plosgff,no)
+	AC_CHECK_PROG(XAS,sdas8051 , sdas8051 -plosgff,no)
 
 	if test "$XCC" = "no" -o "$XAS" = "no" ; then
 		AC_MSG_RESULT([USRP requires sdcc. sdcc not found. See http://sdcc.sf.net])
