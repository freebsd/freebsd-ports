--- regress/cmdline/commit.sh.orig	2022-07-02 13:23:44 UTC
+++ regress/cmdline/commit.sh
@@ -1380,7 +1380,7 @@ test_commit_prepared_logmsg() {
 
 	cat > $testroot/editor.sh <<EOF
 #!/bin/sh
-sed -i 's/foo/bar/' "\$1"
+sed -i '' 's/foo/bar/' "\$1"
 EOF
 	chmod +x $testroot/editor.sh
 
