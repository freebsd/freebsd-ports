--- docs/build.sh.orig	2015-10-17 23:21:49 UTC
+++ docs/build.sh
@@ -11,7 +11,7 @@ for ARG in $*; do
 done
 
 # use with --clean if you change anything in support
-if [[ $1 = "--clean" ]]; then
+if [ "$1" = "--clean" ]; then
     rm -rf _build
 fi
 
