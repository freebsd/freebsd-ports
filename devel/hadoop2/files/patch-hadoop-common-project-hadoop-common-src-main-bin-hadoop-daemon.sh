--- hadoop-common-project/hadoop-common/src/main/bin/hadoop-daemon.sh.orig	2014-06-21 09:40:05.000000000 +0400
+++ hadoop-common-project/hadoop-common/src/main/bin/hadoop-daemon.sh	2014-07-03 21:37:24.000000000 +0400
@@ -97,11 +97,6 @@
   export HADOOP_LOG_DIR="$HADOOP_PREFIX/logs"
 fi
 
-if [ ! -w "$HADOOP_LOG_DIR" ] ; then
-  mkdir -p "$HADOOP_LOG_DIR"
-  chown $HADOOP_IDENT_STRING $HADOOP_LOG_DIR
-fi
-
 if [ "$HADOOP_PID_DIR" = "" ]; then
   HADOOP_PID_DIR=/tmp
 fi
