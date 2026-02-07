--- naval-robocode.sh.orig	2015-03-03 01:06:18 UTC
+++ naval-robocode.sh
@@ -9,5 +9,5 @@
 
 pwd=`pwd`
 cd "${0%/*}"
-java -Xmx512M -cp libs/robocode.jar robocode.Robocode $*
+java -Xmx512M -cp libs/robocode.jar robocode.NavalRobocode $*
 cd "${pwd}"
