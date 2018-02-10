--- build.sh.orig	2017-12-13 09:54:28.459920000 -0500
+++ build.sh	2017-12-13 09:55:25.463123000 -0500
@@ -1,4 +1,4 @@
-#!/usr/bin/env bash
+#!/bin/sh
 set -e
 
 if [ "$DMD" = "" ]; then
@@ -56,7 +56,7 @@
 MACOSX_DEPLOYMENT_TARGET=10.7
 
 echo Running $DMD...
-$DMD -ofbin/dub -g -O -w -version=DubUseCurl -Isource $* $LIBS @build-files.txt
+$DMD -ofbin/dub -O -w -version=DubUseCurl -Isource $* $LIBS @build-files.txt
 bin/dub --version
 echo DUB has been built as bin/dub.
 echo
