--- bin/sbt-launch-lib.bash.orig	2018-12-30 07:45:19 UTC
+++ bin/sbt-launch-lib.bash
@@ -27,7 +27,7 @@ while [ -h "$SCRIPT" ] ; do
   fi
 done
 declare -r sbt_bin_dir="$(dirname "$SCRIPT")"
-declare -r sbt_home="$(dirname "$sbt_bin_dir")"
+declare -r sbt_home="$sbt_bin_dir"
 
 echoerr () {
   echo 1>&2 "$@"
@@ -40,7 +40,7 @@ dlog () {
 }
 
 jar_file () {
-  echo "$(cygwinpath "${sbt_home}/bin/sbt-launch.jar")"
+  echo "$(cygwinpath "${sbt_home}/sbt-launch.jar")"
 }
 
 acquire_sbt_jar () {
@@ -249,14 +249,14 @@ getPreloaded() {
 }
 
 syncPreloaded() {
-  local source_preloaded="$sbt_home/lib/local-preloaded/"
+  local source_preloaded="$sbt_home/local-preloaded/"
   local target_preloaded="$(getPreloaded)"
   if [[ "$init_sbt_version" == "" ]]; then
     # FIXME: better $init_sbt_version detection
     init_sbt_version="$(ls -1 "$source_preloaded/org.scala-sbt/sbt/")"
   fi
   [[ -f "$target_preloaded/org.scala-sbt/sbt/$init_sbt_version/jars/sbt.jar" ]] || {
-    # lib/local-preloaded exists (This is optional)
+    # local-preloaded exists (This is optional)
     [[ -d "$source_preloaded" ]] && {
       command -v rsync >/dev/null 2>&1 && {
         mkdir -p "$target_preloaded"
