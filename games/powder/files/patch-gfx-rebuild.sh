--- gfx/rebuild.sh.orig	2009-09-24 06:33:55.000000000 +0400
+++ gfx/rebuild.sh	2009-11-05 18:35:53.000000000 +0300
@@ -3,10 +3,10 @@
 echo Rebuilding Graphics Files
 
 for tileset in classic distorted adambolt nethack ascii ibsongrey akoimeexx lomaka ; do
-	pushd $tileset
+	cd $tileset
 	echo Building tiles...
 	../../support/tile2c/tile2c
-	popd
+	cd -
 done
 
 echo Building Background images..
