--- scripts/bootstrap/buildenv.sh.orig	2020-10-07 21:26:37 UTC
+++ scripts/bootstrap/buildenv.sh
@@ -230,7 +230,7 @@ function clear_log() {
   rm -f ${phasefile}
 }
 
-LEAVES="\xF0\x9F\x8D\x83"
+LEAVES="[LEAVES]"
 INFO="\033[32mINFO\033[0m:"
 WARNING="\033[31mWARN\033[0m:"
 
