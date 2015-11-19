--- conf/hbase-env.sh.orig	2015-11-11 22:32:08.539865000 -0700
+++ conf/hbase-env.sh	2015-11-11 22:34:34.423285000 -0700
@@ -17,6 +17,8 @@
 # * limitations under the License.
 # */
 
+. %%ETCDIR%%/hbase-env-dist.sh
+
 # Set environment variables here.
 
 # This script sets variables multiple times over the course of starting an hbase process,
@@ -24,7 +26,7 @@
 # into the startup scripts (bin/hbase, etc.)
 
 # The java implementation to use.  Java 1.7+ required.
-# export JAVA_HOME=/usr/java/jdk1.6.0/
+# export JAVA_HOME=/usr/java/jdk1.6.0/ --> Defined in hbase-env-dist.sh
 
 # Extra Java CLASSPATH elements.  Optional.
 # export HBASE_CLASSPATH=
@@ -125,7 +127,7 @@
 # export HBASE_SLAVE_SLEEP=0.1
 
 # Tell HBase whether it should manage it's own instance of Zookeeper or not.
-# export HBASE_MANAGES_ZK=true
+export HBASE_MANAGES_ZK=false
 
 # The default log rolling policy is RFA, where the log file is rolled as per the size defined for the 
 # RFA appender. Please refer to the log4j.properties file to see more details on this appender.
