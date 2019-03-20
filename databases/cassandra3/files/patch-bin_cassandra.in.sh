--- bin/cassandra.in.sh.orig	2019-02-02 22:06:43 UTC
+++ bin/cassandra.in.sh
@@ -26,8 +26,8 @@ fi
 # This can be the path to a jar file, or a directory containing the 
 # compiled classes. NOTE: This isn't needed by the startup script,
 # it's just used here in constructing the classpath.
-cassandra_bin="$CASSANDRA_HOME/build/classes/main"
-cassandra_bin="$cassandra_bin:$CASSANDRA_HOME/build/classes/thrift"
+#cassandra_bin="$CASSANDRA_HOME/build/classes/main"
+#cassandra_bin="$cassandra_bin:$CASSANDRA_HOME/build/classes/thrift"
 #cassandra_bin="$CASSANDRA_HOME/build/cassandra.jar"
 
 # the default location for commitlogs, sstables, and saved caches
@@ -38,7 +38,7 @@ cassandra_storagedir="$CASSANDRA_HOME/data"
 #JAVA_HOME=/usr/local/jdk6
 
 # The java classpath (required)
-CLASSPATH="$CASSANDRA_CONF:$cassandra_bin"
+CLASSPATH="$CASSANDRA_CONF"
 
 for jar in "$CASSANDRA_HOME"/lib/*.jar; do
     CLASSPATH="$CLASSPATH:$jar"
