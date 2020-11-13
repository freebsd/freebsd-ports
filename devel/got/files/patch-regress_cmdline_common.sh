--- regress/cmdline/common.sh.orig	2020-10-13 22:33:10 UTC
+++ regress/cmdline/common.sh
@@ -25,6 +25,20 @@ export GOT_TEST_ROOT="/tmp"
 
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
