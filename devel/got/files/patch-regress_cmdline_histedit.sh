--- regress/cmdline/histedit.sh.orig	2023-01-29 10:30:53 UTC
+++ regress/cmdline/histedit.sh
@@ -1564,7 +1564,7 @@ test_histedit_fold_only() {
 
 	cat > $testroot/editor.sh <<EOF
 #!/bin/sh
-sed -i 's/.*/committing folded changes/' "\$1"
+sed -i '' 's/.*/committing folded changes/' "\$1"
 EOF
 	chmod +x $testroot/editor.sh
 
@@ -1680,7 +1680,7 @@ test_histedit_fold_only_empty_logmsg() {
 
 	cat > $testroot/editor.sh <<EOF
 #!/bin/sh
-sed -i 'd' "\$1"
+sed -i '' 'd' "\$1"
 EOF
 	chmod +x $testroot/editor.sh
 
@@ -1814,7 +1814,7 @@ test_histedit_edit_only() {
 
 	cat > $testroot/editor.sh <<EOF
 #!/bin/sh
-sed -i 's/.*/committing edited changes 1/' "\$1"
+sed -i '' 's/.*/committing edited changes 1/' "\$1"
 EOF
 	chmod +x $testroot/editor.sh
 
@@ -1843,7 +1843,7 @@ EOF
 
 	cat > $testroot/editor.sh <<EOF
 #!/bin/sh
-sed -i 's/.*/committing edited changes 2/' "\$1"
+sed -i '' 's/.*/committing edited changes 2/' "\$1"
 EOF
 	chmod +x $testroot/editor.sh
 
@@ -2239,7 +2239,7 @@ test_histedit_mesg_filemode_change() {
 
 	cat > $testroot/editor.sh <<EOF
 #!/bin/sh
-sed -i 's/ x bit / executable bit /' "\$1"
+sed -i '' 's/ x bit / executable bit /' "\$1"
 EOF
 
 	chmod +x $testroot/editor.sh
