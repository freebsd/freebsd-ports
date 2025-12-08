--- 3rd/luamake/compile/build.sh.orig	2025-10-29 08:38:58 UTC
+++ 3rd/luamake/compile/build.sh
@@ -33,4 +33,4 @@ DIR=$(cd `dirname $0`/..; pwd)
 esac
 
 DIR=$(cd `dirname $0`/..; pwd)
-exec ninja -f "$DIR/compile/ninja/$OS.ninja" $*
+exec %NINJA_CMD% -f "$DIR/compile/ninja/$OS.ninja" $*
