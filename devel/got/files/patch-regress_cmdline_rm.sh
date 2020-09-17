--- regress/cmdline/rm.sh.orig	2020-09-15 22:43:33 UTC
+++ regress/cmdline/rm.sh
@@ -239,7 +239,7 @@ test_rm_directory() {
 		return 1
 	fi
 
-	(cd $testroot/wt && ls -l > $testroot/stdout)
+	(cd $testroot/wt && ls -l | sed '/^total/d' > $testroot/stdout)
 
 	echo -n '' > $testroot/stdout.expected
 
@@ -251,7 +251,7 @@ test_rm_directory() {
 		return 1
 	fi
 
-	(cd $testroot/wt && ls -l > $testroot/stdout)
+	(cd $testroot/wt && ls -l | sed '/^total/d' > $testroot/stdout)
 
 	echo -n '' > $testroot/stdout.expected
 
