XXX remove second hunk after 0.39
--- regress/cmdline/common.sh.orig	2020-09-13 18:20:00 UTC
+++ regress/cmdline/common.sh
@@ -24,6 +24,20 @@ export GOT_LOG_DEFAULT_LIMIT=0
 
 export MALLOC_OPTIONS=S
 
+# compat wrapper
+sed()
+(
+	for i; do
+		arg=$1
+		shift
+		case $arg in
+		-i)	set - "$@" "$arg" '' ;;
+		*)	set - "$@" "$arg" ;;
+		esac
+	done
+	exec sed "$@"
+)
+
 git_init()
 {
 	git init -q "$1"
@@ -96,13 +110,13 @@ git_show_tree()
 
 trim_obj_id()
 {
-	let trimcount=$1
-	id=$2
+	local trimcount=$1
+	local id=$2
 
-	pat=""
-	while [ trimcount -gt 0 ]; do
+	local pat=""
+	while [ "$trimcount" -gt 0 ]; do
 		pat="[0-9a-f]$pat"
-		let trimcount--
+		trimcount=$((trimcount - 1))
 	done
 
 	echo ${id%$pat}
@@ -168,7 +182,7 @@ test_init()
 		echo "No test name provided" >&2
 		return 1
 	fi
-	local testroot=`mktemp -p /tmp -d got-test-$testname-XXXXXXXX`
+	local testroot=`mktemp -d ${TMPDIR-/tmp}/got-test-$testname-XXXXXXXX`
 	mkdir $testroot/repo
 	git_init $testroot/repo
 	if [ -z "$no_tree" ]; then
