XXX remove after 0.39
--- regress/cmdline/commit.sh.orig	2020-09-13 18:20:00 UTC
+++ regress/cmdline/commit.sh
@@ -248,7 +248,8 @@ test_commit_deleted_subdirs() {
 		return 1
 	fi
 
-	(cd $testroot/wt && got rm -R $testroot/wt/{epsilon,gamma} >/dev/null)
+	(cd $testroot/wt && \
+		got rm -R $testroot/wt/epsilon $testroot/wt/gamma >/dev/null)
 
 	(cd $testroot/wt && got commit -m 'test commit_deleted_subdirs' \
 		> $testroot/stdout 2> $testroot/stderr)
