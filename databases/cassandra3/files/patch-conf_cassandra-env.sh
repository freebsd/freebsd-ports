--- conf/cassandra-env.sh.orig	2018-09-07 21:30:15 UTC
+++ conf/cassandra-env.sh
@@ -122,7 +122,7 @@ case "$jvm" in
 esac
 
 #GC log path has to be defined here because it needs to access CASSANDRA_HOME
-JVM_OPTS="$JVM_OPTS -Xloggc:${CASSANDRA_HOME}/logs/gc.log"
+JVM_OPTS="$JVM_OPTS -Xloggc:/var/log/cassandra/gc.log"
 
 # Here we create the arguments that will get passed to the jvm when
 # starting cassandra.
