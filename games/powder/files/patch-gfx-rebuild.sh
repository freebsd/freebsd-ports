--- gfx/rebuild.sh.orig	2009-02-06 04:42:17.000000000 +0300
+++ gfx/rebuild.sh	2009-06-08 00:18:29.000000000 +0400
@@ -3,10 +3,10 @@
 echo Rebuilding Graphics Files
 
 for tileset in classic adambolt nethack ascii ibsongrey akoimeexx; do
-	pushd $tileset
+	cd $tileset
 	echo Building tiles...
 	../../support/tile2c/tile2c
-	popd
+	cd -
 done
 
 echo Building Background images..
