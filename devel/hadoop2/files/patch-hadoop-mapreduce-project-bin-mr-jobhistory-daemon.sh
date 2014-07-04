--- hadoop-mapreduce-project/bin/mr-jobhistory-daemon.sh.orig	2014-06-21 09:40:38.000000000 +0400
+++ hadoop-mapreduce-project/bin/mr-jobhistory-daemon.sh	2014-07-04 23:15:55.000000000 +0400
@@ -78,9 +78,6 @@
   . "${HADOOP_CONF_DIR}/mapred-env.sh"
 fi
 
-mkdir -p "$HADOOP_MAPRED_LOG_DIR"
-chown $HADOOP_MAPRED_IDENT_STRING $HADOOP_MAPRED_LOG_DIR
-
 if [ "$HADOOP_MAPRED_PID_DIR" = "" ]; then
   HADOOP_MAPRED_PID_DIR=/tmp
 fi
@@ -101,8 +98,6 @@
 
   (start)
 
-    mkdir -p "$HADOOP_MAPRED_PID_DIR"
-
     if [ -f $pid ]; then
       if kill -0 `cat $pid` > /dev/null 2>&1; then
         echo $command running as process `cat $pid`.  Stop it first.
