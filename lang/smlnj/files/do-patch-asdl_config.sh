--- asdl/config.sh.orig	2024-10-25 16:47:17 UTC
+++ asdl/config.sh
@@ -40,4 +40,10 @@ export SMLNJ_CMD
 SMLNJ_CMD=$INSTALLDIR/bin/sml
 export SMLNJ_CMD
 
+# "convert" gmake -> bmake
+find . -name Makefile.in | \
+xargs sed -E -i "" \
+	-e 's/^include[[:space:]]+(.+)/.include "\1"/' \
+	-e 's@\$\(patsubst %,%/([^,]+),\$\(([^)]+)\)\)@${\2:C/(.+)\/\\1\\\/\1/}@' \
+	-e 's@\$\(patsubst %([^,]+),%([^,]+),\$\(([^)]+)\)\)@${\3:C/\1/\2/}@'
 ./configure $SIZE_OPT --prefix=$INSTALLDIR
