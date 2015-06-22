--- sysinfo.sh.orig	2008-05-12 20:35:23 UTC
+++ sysinfo.sh
@@ -65,8 +65,8 @@ rm -f sysinfo.crm sysinfoc.c hello
 
 # this bombs out on Ultrix which expect "cut -d"
 
-compsystem=`uname -a | cut -b 1-78`
-compdate=`date|cut -b1-55`
+compsystem=`uname -a | cut -f 1-78`
+compdate=`date | cut -f 1-55`
 
 # let's hope that ctrl-c is not part of any string here
 # this also will barf later if " is in any of the strings
