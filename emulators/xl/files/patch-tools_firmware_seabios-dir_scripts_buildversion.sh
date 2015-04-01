--- tools/firmware/seabios-dir/scripts/buildversion.sh.orig	2015-03-13 09:02:17 UTC
+++ tools/firmware/seabios-dir/scripts/buildversion.sh
@@ -11,7 +11,7 @@ elif [ -f .version ]; then
 else
     VERSION="?"
 fi
-VERSION="${VERSION}-`date +"%Y%m%d_%H%M%S"`-`hostname`"
+VERSION="${VERSION}"
 echo "Version: ${VERSION}"
 
 # Build header file
