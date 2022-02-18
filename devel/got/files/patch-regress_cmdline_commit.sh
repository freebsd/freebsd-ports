--- regress/cmdline/commit.sh.orig	2022-02-08 10:47:01 UTC
+++ regress/cmdline/commit.sh
@@ -1376,7 +1376,7 @@ test_commit_prepared_logmsg() {
 
 	cat > $testroot/editor.sh <<EOF
 #!/bin/sh
-sed -i 's/foo/bar/' "\$1"
+sed -i '' 's/foo/bar/' "\$1"
 EOF
 	chmod +x $testroot/editor.sh
 
