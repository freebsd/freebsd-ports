--- sbin/spark-daemon.sh.orig	2026-07-11 15:25:14 UTC
+++ sbin/spark-daemon.sh
@@ -112,14 +112,6 @@
 if [ "$SPARK_LOG_DIR" = "" ]; then
   export SPARK_LOG_DIR="${SPARK_HOME}/logs"
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
@@ -166,8 +158,6 @@
   mode="$1"
   shift
 
-  mkdir -p "$SPARK_PID_DIR"
-
   if [ -f "$pid" ]; then
     TARGET_ID="$(cat "$pid")"
     if [[ $(ps -p "$TARGET_ID" -o comm=) =~ "java" ]]; then
