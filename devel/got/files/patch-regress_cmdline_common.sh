--- regress/cmdline/common.sh.orig	2022-08-23 09:11:50 UTC
+++ regress/cmdline/common.sh
@@ -27,6 +27,29 @@ export GOT_IGNORE_GITCONFIG=1
 
 export MALLOC_OPTIONS=S
 
+# work around the fix for CVE-2022-39253 in Git 2.38.1
+git()
+(
+	if [ "$1" = submodule ]; then
+		set - -c protocol.file.allow=always "$@"
+	fi
+	exec git "$@"
+)
+
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
