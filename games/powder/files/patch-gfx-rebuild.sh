--- gfx/rebuild.sh.orig	2010-01-20 04:59:47.000000000 +0300
+++ gfx/rebuild.sh	2010-04-25 08:06:33.000000000 +0400
@@ -1,12 +1,12 @@
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
 
 pushd akoi3x
