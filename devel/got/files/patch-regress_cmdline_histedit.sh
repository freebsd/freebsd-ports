--- regress/cmdline/histedit.sh.orig	2021-10-04 10:11:31 UTC
+++ regress/cmdline/histedit.sh
@@ -1561,7 +1561,7 @@ test_histedit_fold_only() {
 
 	cat > $testroot/editor.sh <<EOF
 #!/bin/sh
-sed -i 's/.*/committing folded changes/' "\$1"
+sed -i '' 's/.*/committing folded changes/' "\$1"
 EOF
 	chmod +x $testroot/editor.sh
 
@@ -1677,7 +1677,7 @@ test_histedit_fold_only_empty_logmsg() {
 
 	cat > $testroot/editor.sh <<EOF
 #!/bin/sh
-sed -i 'd' "\$1"
+sed -i '' 'd' "\$1"
 EOF
 	chmod +x $testroot/editor.sh
 
@@ -1811,7 +1811,7 @@ test_histedit_edit_only() {
 
 	cat > $testroot/editor.sh <<EOF
 #!/bin/sh
-sed -i 's/.*/committing edited changes 1/' "\$1"
+sed -i '' 's/.*/committing edited changes 1/' "\$1"
 EOF
 	chmod +x $testroot/editor.sh
 
@@ -1840,7 +1840,7 @@ EOF
 
 	cat > $testroot/editor.sh <<EOF
 #!/bin/sh
-sed -i 's/.*/committing edited changes 2/' "\$1"
+sed -i '' 's/.*/committing edited changes 2/' "\$1"
 EOF
 	chmod +x $testroot/editor.sh
 
