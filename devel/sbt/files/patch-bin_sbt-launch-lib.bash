--- bin/sbt-launch-lib.bash.orig	2017-08-29 21:39:02 UTC
+++ bin/sbt-launch-lib.bash
@@ -26,7 +26,7 @@ while [ -h "$SCRIPT" ] ; do
   fi
 done
 declare -r sbt_bin_dir="$(dirname "$SCRIPT")"
-declare -r sbt_home="$(dirname "$sbt_bin_dir")"
+declare -r sbt_home="$sbt_bin_dir"
 
 echoerr () {
   echo 1>&2 "$@"
@@ -39,7 +39,7 @@ dlog () {
 }
 
 jar_file () {
-  echo "$(cygwinpath "${sbt_home}/bin/sbt-launch.jar")"
+  echo "$(cygwinpath "${sbt_home}/sbt-launch.jar")"
 }
 
 acquire_sbt_jar () {
@@ -172,14 +172,14 @@ process_args () {
 syncPreloaded() {
   if [[ "$init_sbt_version" == "" ]]; then
     # FIXME: better $init_sbt_version detection
-    init_sbt_version="$(ls -1 "$sbt_home/lib/local-preloaded/org.scala-sbt/sbt/")"
+    init_sbt_version="$(ls -1 "$sbt_home/local-preloaded/org.scala-sbt/sbt/")"
   fi
   [[ -f "$HOME/.sbt/preloaded/org.scala-sbt/sbt/$init_sbt_version/jars/sbt.jar" ]] || {
     # lib/local-preloaded exists (This is optional)
-    [[ -d "$sbt_home/lib/local-preloaded/" ]] && {
+    [[ -d "$sbt_home/local-preloaded/" ]] && {
       command -v rsync >/dev/null 2>&1 && {
         mkdir -p "$HOME/.sbt/preloaded"
-        rsync -a --ignore-existing "$sbt_home/lib/local-preloaded/" "$HOME/.sbt/preloaded"
+        rsync -a --ignore-existing "$sbt_home/local-preloaded/" "$HOME/.sbt/preloaded"
       }
     }
   }
