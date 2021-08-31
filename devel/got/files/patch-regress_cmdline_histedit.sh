--- regress/cmdline/histedit.sh.orig	2021-08-30 22:15:20 UTC
+++ regress/cmdline/histedit.sh
@@ -1539,7 +1539,7 @@ test_histedit_fold_only() {
 
 	cat > $testroot/editor.sh <<EOF
 #!/bin/sh
-sed -i 's/.*/committing folded changes/' "\$1"
+sed -i '' 's/.*/committing folded changes/' "\$1"
 EOF
 	chmod +x $testroot/editor.sh
 
@@ -1655,7 +1655,7 @@ test_histedit_fold_only_empty_logmsg() {
 
 	cat > $testroot/editor.sh <<EOF
 #!/bin/sh
-sed -i 'd' "\$1"
+sed -i '' 'd' "\$1"
 EOF
 	chmod +x $testroot/editor.sh
 
