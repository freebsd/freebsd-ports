--- tools/bin/cassandra.in.sh.orig	2018-03-01 14:02:52 UTC
+++ tools/bin/cassandra.in.sh
@@ -26,9 +26,9 @@ fi
 # This can be the path to a jar file, or a directory containing the
 # compiled classes. NOTE: This isn't needed by the startup script,
 # it's just used here in constructing the classpath.
-cassandra_bin="$CASSANDRA_HOME/build/classes/main"
-cassandra_bin="$cassandra_bin:$CASSANDRA_HOME/build/classes/stress"
-cassandra_bin="$cassandra_bin:$CASSANDRA_HOME/build/classes/thrift"
+#cassandra_bin="$CASSANDRA_HOME/build/classes/main"
+#cassandra_bin="$cassandra_bin:$CASSANDRA_HOME/build/classes/stress"
+#cassandra_bin="$cassandra_bin:$CASSANDRA_HOME/build/classes/thrift"
 #cassandra_bin="$cassandra_home/build/cassandra.jar"
 
 # the default location for commitlogs, sstables, and saved caches
@@ -39,7 +39,7 @@ cassandra_storagedir="$CASSANDRA_HOME/da
 #JAVA_HOME=/usr/local/jdk6
 
 # The java classpath (required)
-CLASSPATH="$CASSANDRA_CONF:$cassandra_bin"
+CLASSPATH="$CASSANDRA_CONF"
 
 for jar in "$CASSANDRA_HOME"/tools/lib/*.jar; do
     CLASSPATH="$CLASSPATH:$jar"
