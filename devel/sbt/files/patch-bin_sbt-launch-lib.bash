--- bin/sbt-launch-lib.bash.orig	2012-09-18 09:35:57.000000000 +0200
+++ bin/sbt-launch-lib.bash	2012-09-18 09:37:53.000000000 +0200
@@ -29,7 +29,7 @@
 }
 
 jar_file () {
-  echo "$(dirname $0)/sbt-launch.jar"
+  echo "%%PREFIX%%/share/sbt/sbt-launch.jar"
 }
 
 acquire_sbt_jar () {
