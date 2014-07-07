--- hadoop-yarn-project/hadoop-yarn/bin/yarn-daemon.sh.orig	2014-06-21 09:41:15.000000000 +0400
+++ hadoop-yarn-project/hadoop-yarn/bin/yarn-daemon.sh	2014-07-04 15:48:29.000000000 +0400
@@ -79,10 +79,6 @@
   export YARN_LOG_DIR="$HADOOP_YARN_HOME/logs"
 fi
 
-if [ ! -w "$YARN_LOG_DIR" ] ; then
-  mkdir -p "$YARN_LOG_DIR"
-  chown $YARN_IDENT_STRING $YARN_LOG_DIR 
-fi
 
 if [ "$YARN_PID_DIR" = "" ]; then
   YARN_PID_DIR=/tmp
@@ -104,8 +100,6 @@
 
   (start)
 
-    [ -w "$YARN_PID_DIR" ] || mkdir -p "$YARN_PID_DIR"
-
     if [ -f $pid ]; then
       if kill -0 `cat $pid` > /dev/null 2>&1; then
         echo $command running as process `cat $pid`.  Stop it first.
