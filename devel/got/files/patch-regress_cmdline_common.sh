--- regress/cmdline/common.sh.orig	2022-10-24 22:00:47 UTC
+++ regress/cmdline/common.sh
@@ -27,6 +27,20 @@ export GOT_IGNORE_GITCONFIG=1
 
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
