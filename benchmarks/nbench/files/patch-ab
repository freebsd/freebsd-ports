--- sysinfo.sh.orig	Mon Oct 18 00:03:53 2004
+++ sysinfo.sh	Mon Oct 18 00:04:35 2004
@@ -50,8 +50,8 @@
 
 # this bombs out on Ultrix which expect "cut -d"
 
-compsystem=`uname -a | cut -b 1-78`
-compdate=`date|cut -b1-55`
+compsystem=`uname -a | cut -f 1-78`
+compdate=`date | cut -f 1-55`
 
 # let's hope that ctrl-c is not part of any string here
 # this also will barf later if " is in any of the strings
