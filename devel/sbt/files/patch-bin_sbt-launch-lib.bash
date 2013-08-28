--- bin/sbt-launch-lib.bash.orig	2013-08-28 10:14:44.000000000 +0200
+++ bin/sbt-launch-lib.bash	2013-08-28 10:20:01.000000000 +0200
@@ -31,7 +31,7 @@
 }
 
 jar_file () {
-  echo "$(cygwinpath "${sbt_home}/bin/sbt-launch.jar")"
+  echo "$(cygwinpath "${sbt_bin_dir}/sbt-launch.jar")"
 }
 
 acquire_sbt_jar () {
