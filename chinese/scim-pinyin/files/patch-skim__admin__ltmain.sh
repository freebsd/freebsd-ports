--- ./skim/admin/ltmain.sh.orig	Sun Jun 19 11:43:45 2005
+++ ./skim/admin/ltmain.sh	Sun Feb 18 20:50:18 2007
@@ -2007,6 +2007,9 @@
 	  alldeplibs=yes
 	  continue
 	  ;;
+	-pthread)
+	  continue
+	  ;;
 	esac # case $deplib
 	if test "$found" = yes || test -f "$lib"; then :
 	else
