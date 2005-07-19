--- src/tuxpaint-import.sh.orig	Tue Jun 17 06:10:59 2003
+++ src/tuxpaint-import.sh	Thu Jul 14 16:17:58 2005
@@ -23,7 +23,7 @@
   exit
 fi
 
-if [[ $1 == "--help" ]]; then
+if [ $1 = "--help" ]; then
   # --help, show usage:
   echo
   echo "tuxpaint-import"
