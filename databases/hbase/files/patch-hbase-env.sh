--- conf/hbase-env.sh.bak	2014-07-15 05:23:39.000000000 +0400
+++ conf/hbase-env.sh	2014-07-28 23:05:05.000000000 +0400
@@ -19,6 +19,8 @@
 # * limitations under the License.
 # */
 
+. %%ETCDIR%%/hbase-env-dist.sh
+
 # Set environment variables here.
 
 # This script sets variables multiple times over the course of starting an hbase process,
@@ -26,7 +28,7 @@
 # into the startup scripts (bin/hbase, etc.)
 
 # The java implementation to use.  Java 1.6 required.
-# export JAVA_HOME=/usr/java/jdk1.6.0/
+# export JAVA_HOME=/usr/java/jdk1.6.0/  --> Defined in hbase-env-dist.sh
 
 # Extra Java CLASSPATH elements.  Optional.
 # export HBASE_CLASSPATH=
@@ -121,7 +123,7 @@
 # export HBASE_SLAVE_SLEEP=0.1
 
 # Tell HBase whether it should manage it's own instance of Zookeeper or not.
-# export HBASE_MANAGES_ZK=true
+export HBASE_MANAGES_ZK=false
 
 # The default log rolling policy is RFA, where the log file is rolled as per the size defined for the 
 # RFA appender. Please refer to the log4j.properties file to see more details on this appender.
