--- conf/cassandra-env.sh.orig	2020-02-10 22:55:14 UTC
+++ conf/cassandra-env.sh
@@ -123,7 +123,7 @@ esac
 
 # Sets the path where logback and GC logs are written.
 if [ "x$CASSANDRA_LOG_DIR" = "x" ] ; then
-    CASSANDRA_LOG_DIR="$CASSANDRA_HOME/logs"
+    CASSANDRA_LOG_DIR="/var/log/cassandra"
 fi
 
 #GC log path has to be defined here because it needs to access CASSANDRA_HOME
