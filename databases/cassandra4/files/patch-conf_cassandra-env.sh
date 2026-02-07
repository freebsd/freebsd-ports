--- conf/cassandra-env.sh.orig	2020-01-30 17:34:31 UTC
+++ conf/cassandra-env.sh
@@ -88,7 +88,7 @@ calculate_heap_sizes()
 
 # Sets the path where logback and GC logs are written.
 if [ "x$CASSANDRA_LOG_DIR" = "x" ] ; then
-    CASSANDRA_LOG_DIR="$CASSANDRA_HOME/logs"
+    CASSANDRA_LOG_DIR="/var/log/cassandra"
 fi
 
 #GC log path has to be defined here because it needs to access CASSANDRA_HOME
