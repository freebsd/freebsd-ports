--- build.sh.orig	2026-05-27 21:47:09 UTC
+++ build.sh
@@ -612,7 +612,6 @@ if [ "$IS_MAC" = "no" ]; then
 #   OSX does not have `readlink -f` command. Use equivalent Perl script.
 if [ "$IS_MAC" = "no" ]; then
   BUILD=`readlink -f $BUILD`
-  BIN=`readlink -f $BIN`
 else
   BUILD=`perl -MCwd -le 'print Cwd::abs_path(shift)' $BUILD`
   BIN=`perl -MCwd -le 'print Cwd::abs_path(shift)' $BIN`
