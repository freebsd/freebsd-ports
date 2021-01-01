--- atom.sh.orig	2019-05-22 03:44:37 UTC
+++ atom.sh
@@ -2,6 +2,8 @@
 
 if [ "$(uname)" == 'Darwin' ]; then
   OS='Mac'
+elif [ "$(uname)" == 'FreeBSD' ]; then
+  OS='FreeBSD'
 elif [ "$(expr substr $(uname -s) 1 5)" == 'Linux' ]; then
   OS='Linux'
 else
@@ -149,7 +151,7 @@ if [ $OS == 'Mac' ]; then
   else
     open -a "$ATOM_PATH/$ATOM_APP_NAME" -n --args --executed-from="$(pwd)" --pid=$$ --path-environment="$PATH" "$@"
   fi
-elif [ $OS == 'Linux' ]; then
+elif [ $OS == 'Linux' ] || [ $OS == 'FreeBSD' ]; then
   SCRIPT=$(readlink -f "$0")
   USR_DIRECTORY=$(readlink -f $(dirname $SCRIPT)/..)
 
