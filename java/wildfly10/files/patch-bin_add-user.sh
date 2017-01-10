--- bin/add-user.sh.orig	2015-10-23 18:57:02 UTC
+++ bin/add-user.sh
@@ -7,6 +7,8 @@
 #
 
 DIRNAME=`dirname "$0"`
+JAVA_VERSION="1.7+"
+export JAVA_VERSION
 
 # OS specific support (must be 'true' or 'false').
 cygwin=false;
