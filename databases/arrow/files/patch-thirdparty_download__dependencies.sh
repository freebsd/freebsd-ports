--- thirdparty/download_dependencies.sh.orig	2019-02-16 22:21:34 UTC
+++ thirdparty/download_dependencies.sh
@@ -61,4 +61,6 @@ main() {
   done
 }
 
-main
+echo "Bundling isn't allowed!"
+return 1
+#main
