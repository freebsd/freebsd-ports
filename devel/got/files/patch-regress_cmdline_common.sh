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
@@ -168,7 +182,7 @@ test_init()
 		echo "No test name provided" >&2
 		return 1
 	fi
-	local testroot=`mktemp -p /tmp -d got-test-$testname-XXXXXXXX`
+	local testroot=`mktemp -d ${TMPDIR-/tmp}/got-test-$testname-XXXXXXXX`
 	mkdir $testroot/repo
 	git_init $testroot/repo
 	if [ -z "$no_tree" ]; then
