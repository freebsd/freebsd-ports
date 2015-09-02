--- src/qt/preconfig.sh.orig	2015-05-24 22:51:56.181745985 +0900
+++ src/qt/preconfig.sh	2015-05-25 07:48:59.018524838 +0900
@@ -182,5 +182,6 @@
     exec >& /dev/null
 fi
 
+export CXX=${CXX}
 cd qtbase
-exec ./configure -prefix $PWD $QT_CFG "$@"
+exec bash -x ./configure -prefix $PWD $QT_CFG "$@"
