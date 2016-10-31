--- bin/sbt-launch-lib.bash.orig	2016-10-28 17:46:00 UTC
+++ bin/sbt-launch-lib.bash
@@ -26,7 +26,7 @@ dlog () {
 }
 
 jar_file () {
-  echo "$(cygwinpath "${sbt_home}/bin/sbt-launch.jar")"
+  echo "$(cygwinpath "${sbt_bin_dir}/sbt-launch.jar")"
 }
 
 acquire_sbt_jar () {
