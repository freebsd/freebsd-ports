--- config/ltmain.sh.orig	Mon Jun  9 16:36:06 2003
+++ config/ltmain.sh	Sat Nov 22 22:09:24 2003
@@ -990,6 +990,7 @@
 	;;
 
       -avoid-version)
+	build_old_libs=no
 	avoid_version=yes
 	continue
 	;;
