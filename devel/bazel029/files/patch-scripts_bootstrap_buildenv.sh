--- scripts/bootstrap/buildenv.sh.orig	1979-12-31 23:00:00 UTC
+++ scripts/bootstrap/buildenv.sh
@@ -215,7 +215,7 @@ function clear_log() {
   rm -f ${phasefile}
 }
 
-LEAVES="\xF0\x9F\x8D\x83"
+LEAVES="[LEAVES]"
 INFO="\033[32mINFO\033[0m:"
 WARNING="\033[31mWARN\033[0m:"
 
