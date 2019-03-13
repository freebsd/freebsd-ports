--- sys/unix/setup.sh.orig	2019-03-12 15:54:29.880771000 -0700
+++ sys/unix/setup.sh	2019-03-12 15:55:10.991928000 -0700
@@ -26,7 +26,7 @@
         ;;
 esac
 
-if [ ! -f "$hints" ]; then
+if [ ! -f "$hints" -a "$hints" != "/dev/null" ]; then
     echo "Cannot find hints file $hfile"
     exit 1
 fi
