--- config/ltmain.sh.orig	Sun Jul 14 08:53:50 2002
+++ config/ltmain.sh	Tue Jul 16 00:38:55 2002
@@ -967,6 +967,7 @@
 	;;
 
       -avoid-version)
+	build_old_libs=no
 	avoid_version=yes
 	continue
 	;;
