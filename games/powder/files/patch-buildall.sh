--- buildall.sh.orig	2010-04-01 23:32:05 UTC
+++ buildall.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 
 if [ -z "$CXXFLAGS" ]; then
     export CXXFLAGS=-O3
@@ -7,7 +7,7 @@ fi
 PREFIX_DOC=$DESTDIR/usr/share/doc/powder
 PREFIX_BIN=$DESTDIR/opt/bin
 
-function usage {
+usage() {
     echo Usage: `basename $0` [options]
     echo -e "--install\t - install POWDER"
     echo -e "--uninstall\t - uninstall POWDER"
@@ -26,43 +26,43 @@ function usage {
     echo -e "--install does *NOT* rebuild if powder exists"
 }
 
-function compile {
+compile() {
     echo Run this from the root of the source tree.
 
     echo Rebuild all of POWDER
     echo Build support binaries
     cd support/bmp2c
-    make clean
-    make
+    gmake clean
+    gmake
     cd ../encyclopedia2c
-    make clean
-    make
+    gmake clean
+    gmake
     cd ../enummaker
-    make clean
-    make
+    gmake clean
+    gmake
     cd ../map2c
-    make clean
-    make
+    gmake clean
+    gmake
     cd ../txt2c
-    make clean
-    make
+    gmake clean
+    gmake
     cd ../tile2c
-    make clean
-    make
+    gmake clean
+    gmake
 
     echo Clean...
     cd ../../port/linux
-    make clean
+    gmake clean
     echo Premake
-    make premake
+    gmake premake
     echo Final install
-    make powder-static
+    gmake powder
     cp powder ../..
     cd ../..
     echo Run powder to play
 }
 
-function install {
+install() {
     if [ ! -f powder ]; then
 	compile
     fi
@@ -74,7 +74,7 @@ function install {
     echo "Installation complete"
 }
 
-function uninstall {
+uninstall() {
     rm $PREFIX_BIN/powder
     for file in README.TXT LICENSE.TXT CREDITS.TXT; do
 	rm $PREFIX_DOC/$file
@@ -101,7 +101,7 @@ do
     fi
 done
 
-if [ "$INSTALL" == "1" ]; then
+if [ "$INSTALL" = "1" ]; then
     install
 else
     compile
