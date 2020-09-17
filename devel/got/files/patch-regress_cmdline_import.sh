--- regress/cmdline/import.sh.orig	2020-09-13 18:20:00 UTC
+++ regress/cmdline/import.sh
@@ -18,7 +18,7 @@
 
 test_import_basic() {
 	local testname=import_basic
-	local testroot=`mktemp -p /tmp -d got-test-$testname-XXXXXXXX`
+	local testroot=`mktemp -d ${TMPDIR-/tmp}/got-test-$testname-XXXXXXXX`
 
 	got init $testroot/repo
 
@@ -170,7 +170,7 @@ test_import_requires_new_branch() {
 
 test_import_ignores() {
 	local testname=import_ignores
-	local testroot=`mktemp -p /tmp -d got-test-$testname-XXXXXXXX`
+	local testroot=`mktemp -d ${TMPDIR-/tmp}/got-test-$testname-XXXXXXXX`
 
 	got init $testroot/repo
 
@@ -200,7 +200,7 @@ test_import_ignores() {
 
 test_import_empty_dir() {
 	local testname=import_empty_dir
-	local testroot=`mktemp -p /tmp -d got-test-$testname-XXXXXXXX`
+	local testroot=`mktemp -d ${TMPDIR-/tmp}/got-test-$testname-XXXXXXXX`
 
 	got init $testroot/repo
 
@@ -243,7 +243,7 @@ test_import_empty_dir() {
 
 test_import_symlink() {
 	local testname=import_symlink
-	local testroot=`mktemp -p /tmp -d got-test-$testname-XXXXXXXX`
+	local testroot=`mktemp -d ${TMPDIR-/tmp}/got-test-$testname-XXXXXXXX`
 
 	got init $testroot/repo
 
