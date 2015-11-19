--- bin/hbase-daemon.sh.orig	2015-11-11 22:19:14.786233000 -0700
+++ bin/hbase-daemon.sh	2015-11-11 22:19:45.137538000 -0700
@@ -93,7 +93,6 @@
 
 check_before_start(){
     #ckeck if the process is not running
-    mkdir -p "$HBASE_PID_DIR"
     if [ -f $HBASE_PID ]; then
       if kill -0 `cat $HBASE_PID` > /dev/null 2>&1; then
         echo $command running as process `cat $HBASE_PID`.  Stop it first.
@@ -124,7 +123,6 @@
 if [ "$HBASE_LOG_DIR" = "" ]; then
   export HBASE_LOG_DIR="$HBASE_HOME/logs"
 fi
-mkdir -p "$HBASE_LOG_DIR"
 
 if [ "$HBASE_PID_DIR" = "" ]; then
   HBASE_PID_DIR=/tmp
