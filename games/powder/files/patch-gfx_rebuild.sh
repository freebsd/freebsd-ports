--- gfx/rebuild.sh.orig	2010-01-20 01:59:47 UTC
+++ gfx/rebuild.sh
@@ -1,19 +1,19 @@
-#!/bin/bash
+#!/bin/sh
 
 echo Rebuilding Graphics Files
 
 for tileset in classic distorted adambolt nethack ascii ibsongrey akoimeexx akoi12 akoi10 lomaka ; do
-	pushd $tileset
+	cd $tileset
 	echo Building tiles...
 	../../support/tile2c/tile2c
-	popd
+	cd -
 done
 
-pushd akoi3x
+cd akoi3x
     echo Building Akoi3x
     gzip -d -c sprite16_3x.bmp.gz > sprite16_3x.bmp
     ../../support/bmp2c/bmp2c sprite16_3x.bmp
-popd
+cd -
 
 echo Building Background images..
 ../support/bmp2c/bmp2c tridude_goodbye.bmp
