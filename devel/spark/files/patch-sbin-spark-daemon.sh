--- sbin/spark-daemon.sh.orig	2015-10-26 09:05:25.709519603 +0000
+++ sbin/spark-daemon.sh	2015-10-26 09:07:31.767513027 +0000
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
@@ -125,8 +117,6 @@
   mode="$1"
   shift
 
-  mkdir -p "$SPARK_PID_DIR"
-
   if [ -f "$pid" ]; then
     TARGET_ID="$(cat "$pid")"
     if [[ $(ps -p "$TARGET_ID" -o comm=) =~ "java" ]]; then
