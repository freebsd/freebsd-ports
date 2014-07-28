--- bin/hbase-daemon.sh.orig	2014-07-14 09:50:03.000000000 +0400
+++ bin/hbase-daemon.sh	2014-07-23 18:49:15.000000000 +0400
@@ -89,7 +89,6 @@
 
 check_before_start(){
     #ckeck if the process is not running
-    mkdir -p "$HBASE_PID_DIR"
     if [ -f $pid ]; then
       if kill -0 `cat $pid` > /dev/null 2>&1; then
         echo $command running as process `cat $pid`.  Stop it first.
@@ -120,7 +119,6 @@
 if [ "$HBASE_LOG_DIR" = "" ]; then
   export HBASE_LOG_DIR="$HBASE_HOME/logs"
 fi
-mkdir -p "$HBASE_LOG_DIR"
 
 if [ "$HBASE_PID_DIR" = "" ]; then
   HBASE_PID_DIR=/tmp
