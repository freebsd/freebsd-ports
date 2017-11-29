--- scripts/bootstrap/buildenv.sh.orig	2017-11-11 22:06:52.302048000 +0000
+++ scripts/bootstrap/buildenv.sh
@@ -215,7 +215,7 @@
   rm -f ${phasefile}
 }
 
-LEAVES="\xF0\x9F\x8D\x83"
+LEAVES="[LEAVES]"
 INFO="\033[32mINFO\033[0m:"
 WARNING="\033[31mWARN\033[0m:"
 
