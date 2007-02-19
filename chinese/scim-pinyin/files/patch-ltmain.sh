--- ./ltmain.sh.orig	Thu Aug 11 21:04:29 2005
+++ ./ltmain.sh	Sun Feb 18 20:49:45 2007
@@ -2196,6 +2196,9 @@
 	  alldeplibs=yes
 	  continue
 	  ;;
+	-pthread)
+	  continue
+	  ;;
 	esac # case $deplib
 	if test "$found" = yes || test -f "$lib"; then :
 	else
