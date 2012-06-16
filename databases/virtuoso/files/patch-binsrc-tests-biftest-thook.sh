--- binsrc/tests/biftest/thook.sh.orig	2012-06-15 17:48:39.000000000 +0700
+++ binsrc/tests/biftest/thook.sh	2012-06-15 17:52:34.000000000 +0700
@@ -22,7 +22,8 @@
 #
 
 OUTPUT=thook.output
-ISQL=../isql
+ISQL=${ISQL-isql}
+ISQL=../$ISQL
 TIMEOUT=1000
 HOST_OS=`uname -s | grep WIN`
 SERVER=./virtuoso-iodbc-sample-t
