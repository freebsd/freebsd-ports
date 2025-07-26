--- regress/cmdline/revert.sh.orig	2025-07-22 08:18:04 UTC
+++ regress/cmdline/revert.sh
@@ -1884,9 +1884,12 @@ test_revert_staged_file() {
 		> /dev/null)
 	local commit_id=`git_show_head $testroot/repo`
 
-	sed -i -e 's/line 0/line 0a/' $testroot/wt/epsilon/zeta
-	sed -i -e 's/line 4/line 4a/' $testroot/wt/epsilon/zeta
-	sed -i -e 's/line 6/line 6a/' $testroot/wt/epsilon/zeta
+	ed -s $testroot/wt/epsilon/zeta <<-\EOF
+	,s/line 0/line 0a/
+	,s/line 4/line 4a/
+	,s/line 6/line 6a/
+	w
+	EOF
 
 	# stage line 0 and line 6
 	printf "y\n" > $testroot/patchscript
@@ -1991,9 +1994,12 @@ test_revert_partially_staged_file() {
 		> /dev/null)
 	local commit_id=`git_show_head $testroot/repo`
 
-	sed -i -e 's/line 0/line 0a/' $testroot/wt/epsilon/zeta
-	sed -i -e 's/line 4/line 4a/' $testroot/wt/epsilon/zeta
-	sed -i -e 's/line 6/line 6a/' $testroot/wt/epsilon/zeta
+	ed -s $testroot/wt/epsilon/zeta <<-\EOF
+	,s/line 0/line 0a/
+	,s/line 4/line 4a/
+	,s/line 6/line 6a/
+	w
+	EOF
 
 	# stage line 0 and line 6
 	printf "y\n" > $testroot/patchscript
