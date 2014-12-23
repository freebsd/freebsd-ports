--- sbin/spark-daemon.sh.orig	2014-12-20 14:07:28.000000000 +0300
+++ sbin/spark-daemon.sh	2014-12-20 14:07:31.000000000 +0300
@@ -99,14 +99,6 @@
 if [ "$SPARK_LOG_DIR" = "" ]; then
   export SPARK_LOG_DIR="$SPARK_HOME/logs"
 fi
-mkdir -p "$SPARK_LOG_DIR"
-touch "$SPARK_LOG_DIR"/.spark_test > /dev/null 2>&1
-TEST_LOG_DIR=$?
-if [ "${TEST_LOG_DIR}" = "0" ]; then
-  rm -f "$SPARK_LOG_DIR"/.spark_test
-else
-  chown "$SPARK_IDENT_STRING" "$SPARK_LOG_DIR"
-fi
 
 if [ "$SPARK_PID_DIR" = "" ]; then
   SPARK_PID_DIR=/tmp
@@ -126,8 +118,6 @@
 
   (start|spark-submit)
 
-    mkdir -p "$SPARK_PID_DIR"
-
     if [ -f $pid ]; then
       if kill -0 `cat $pid` > /dev/null 2>&1; then
         echo $command running as process `cat $pid`.  Stop it first.
