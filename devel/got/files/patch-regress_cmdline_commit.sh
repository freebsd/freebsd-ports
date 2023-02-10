--- regress/cmdline/commit.sh.orig	2023-01-30 08:56:03 UTC
+++ regress/cmdline/commit.sh
@@ -1492,7 +1492,7 @@ test_commit_prepared_logmsg() {
 
 	cat > $testroot/editor.sh <<EOF
 #!/bin/sh
-sed -i 's/foo/bar/' "\$1"
+sed -i '' 's/foo/bar/' "\$1"
 EOF
 	chmod +x $testroot/editor.sh
 
@@ -1755,7 +1755,7 @@ test_commit_logmsg_ref() {
 
 	cat > $testroot/editor.sh <<EOF
 #!/bin/sh
-sed -i 's/# l/l/' "\$1"
+sed -i '' 's/# l/l/' "\$1"
 EOF
 	chmod +x $testroot/editor.sh
 
