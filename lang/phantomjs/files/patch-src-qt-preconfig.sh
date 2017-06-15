--- src/qt/preconfig.sh.orig	2016-01-24 18:24:05 UTC
+++ src/qt/preconfig.sh
@@ -187,5 +187,6 @@ if [[ -n "$SILENT" ]]; then
     exec >& /dev/null
 fi
 
+export CXX=${CXX}
 cd qtbase
-exec ./configure -prefix $PWD $QT_CFG "$@"
+exec bash -x ./configure -prefix $PWD $QT_CFG "$@"
