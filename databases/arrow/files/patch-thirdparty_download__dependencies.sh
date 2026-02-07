--- thirdparty/download_dependencies.sh.orig	2023-08-17 08:05:04 UTC
+++ thirdparty/download_dependencies.sh
@@ -62,4 +62,6 @@ main() {
   done
 }
 
-main
+echo "Bundling isn't allowed!"
+return 1
+#main
