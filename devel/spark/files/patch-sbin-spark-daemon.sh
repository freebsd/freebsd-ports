--- sbin/spark-daemon.sh.orig	2022-06-09 18:11:30 UTC
+++ sbin/spark-daemon.sh
@@ -108,14 +108,6 @@ fi
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
@@ -161,8 +153,6 @@ run_command() {
 run_command() {
   mode="$1"
   shift
-
-  mkdir -p "$SPARK_PID_DIR"
 
   if [ -f "$pid" ]; then
     TARGET_ID="$(cat "$pid")"
