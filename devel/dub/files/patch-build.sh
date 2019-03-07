--- build.sh.orig	2019-03-01 15:41:12.000000000 +0000
+++ build.sh	2019-03-06 05:49:55.312072000 +0000
@@ -1,4 +1,4 @@
-#!/usr/bin/env bash
+#!/bin/sh
 set -e
 
 if [ "$DMD" = "" ]; then
@@ -41,9 +41,6 @@
 	LIBS=`echo "$LIBS" | sed 's/^-L/-L-L/; s/ -L/ -L-L/g; s/^-l/-L-l/; s/ -l/ -L-l/g'`
 fi
 
-if [ "$GITVER" = "" ]; then
-  GITVER=$(git describe) || echo "Could not determine a version with git."
-fi
 if [ "$GITVER" != "" ]; then
 	echo Generating version file...
 	echo "module dub.version_;" > source/dub/version_.d
@@ -56,7 +53,7 @@
 MACOSX_DEPLOYMENT_TARGET=10.8
 
 echo Running $DMD...
-$DMD -ofbin/dub -g -O -w -version=DubUseCurl -version=DubApplication -Isource $* $LIBS @build-files.txt
+$DMD -ofbin/dub -O -w -version=DubUseCurl -version=DubApplication -Isource $* $LIBS @build-files.txt
 bin/dub --version
 echo DUB has been built as bin/dub.
 echo
