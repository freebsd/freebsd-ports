--- ../setup2/script/setup.sh.orig Thu Jul 17 02:59:43 2003
+++ ../setup2/script/setup.sh	Thu Sep  4 07:27:59 2003
@@ -118,6 +118,10 @@
 	 LD_LIBRARY_PATH=${sd_archive_path}:.
 	 export LD_LIBRARY_PATH
 	 ;;
+  FreeBSD)
+	 LD_LIBRARYN32_PATH=${sd_archive_path}:.
+	 export LD_LIBRARYN32_PATH
+	 ;;
   Darwin)
 	 DYLD_LIBRARY_PATH=${sd_archive_path}:.
 	 export DYLD_LIBRARY_PATH
