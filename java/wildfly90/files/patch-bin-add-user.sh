--- bin/add-user.sh	2014-02-12 05:43:24.000000000 +0100
+++ /usr/local/wildfly-9.0.0/bin/add-user.sh	2014-05-11 10:53:59.000000000 +0200
@@ -7,6 +7,8 @@
 #
 
 DIRNAME=`dirname "$0"`
+JAVA_VERSION="1.7+"
+export JAVA_VERSION
 
 # OS specific support (must be 'true' or 'false').
 cygwin=false;
