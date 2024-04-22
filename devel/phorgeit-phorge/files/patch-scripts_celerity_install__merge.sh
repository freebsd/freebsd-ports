--- scripts/celerity/install_merge.sh.orig	2020-05-19 10:53:29 UTC
+++ scripts/celerity/install_merge.sh
@@ -6,4 +6,4 @@ echo "resources/celerity/map.php merge=celerity" \
 git config merge.celerity.name "Celerity Mapper"
 
 git config merge.celerity.driver \
-  'php $GIT_DIR/../bin/celerity map'
+  '%%PHP_CMD%% $GIT_DIR/../bin/celerity map'
