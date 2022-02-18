--- regress/cmdline/histedit.sh.orig	2022-01-19 10:29:31 UTC
+++ regress/cmdline/histedit.sh
@@ -1565,7 +1565,7 @@ test_histedit_fold_only() {
 
 	cat > $testroot/editor.sh <<EOF
 #!/bin/sh
-sed -i 's/.*/committing folded changes/' "\$1"
+sed -i '' 's/.*/committing folded changes/' "\$1"
 EOF
 	chmod +x $testroot/editor.sh
 
@@ -1681,7 +1681,7 @@ test_histedit_fold_only_empty_logmsg() {
 
 	cat > $testroot/editor.sh <<EOF
 #!/bin/sh
-sed -i 'd' "\$1"
+sed -i '' 'd' "\$1"
 EOF
 	chmod +x $testroot/editor.sh
 
@@ -1815,7 +1815,7 @@ test_histedit_edit_only() {
 
 	cat > $testroot/editor.sh <<EOF
 #!/bin/sh
-sed -i 's/.*/committing edited changes 1/' "\$1"
+sed -i '' 's/.*/committing edited changes 1/' "\$1"
 EOF
 	chmod +x $testroot/editor.sh
 
@@ -1844,7 +1844,7 @@ EOF
 
 	cat > $testroot/editor.sh <<EOF
 #!/bin/sh
-sed -i 's/.*/committing edited changes 2/' "\$1"
+sed -i '' 's/.*/committing edited changes 2/' "\$1"
 EOF
 	chmod +x $testroot/editor.sh
 
