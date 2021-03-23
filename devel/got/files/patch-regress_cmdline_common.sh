--- regress/cmdline/common.sh.orig	2021-03-22 10:05:11 UTC
+++ regress/cmdline/common.sh
@@ -26,6 +26,20 @@ export GOT_TEST_ROOT="/tmp"
 
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
