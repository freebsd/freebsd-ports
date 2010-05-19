--- install.sh.orig	2007-08-25 14:53:40.000000000 +0700
+++ install.sh	2010-03-06 12:25:59.000000000 +0600
@@ -1,4 +1,4 @@
-#!/bin/bash 
+#!/bin/sh 
 # install childsplay.  
 # Be aware that childsplay probably won't work when you edit this file :-(
 # As of 11/2004 childsplay will be converted to follow the File System
@@ -20,14 +20,14 @@
 
 LOCALEDIR=$PREFIX/share/locale
 MTDIR=$PREFIX/bin
-ASSETMLDIR=/usr/share/assetml
+ASSETMLDIR=${PREFIX}/share/assetml
 PYTHON=`which python`
 SCOREDIR=/var/games
 DOCDIR=$PREFIX/share/doc/childsplay
 MANDIR=$PREFIX/man/man6
-CPDIR=$PREFIX/lib/games/childsplay
+CPDIR=$PREFIX/childsplay
 SHAREDIR=$PREFIX/share/childsplay
-BINDIR=$PREFIX/games
+BINDIR=$PREFIX/bin
 SHARELIBDATADIR=$SHAREDIR/lib
 SHAREDATADIR=$SHAREDIR/Data
 
@@ -76,21 +76,6 @@
 
 set -e
 
-echo -e "\n The path to install the plugins in is $CPDIR."
-echo " If you have installed childsplay in a other place, you can"
-echo " give the full path to childsplay, otherwise just hit enter"
-echo " Hit enter to install in $CPDIR, or give the full path"
-read path
-if [ $path ];then
-    if [ -e $path/install.py ];then
-        CPDIR=path
-    else
-        echo "*********** WARNING *************"
-        echo " $path does not exists or is not the childsplay directory"
-        echo " exit"
-        exit 1
-    fi
-fi
 echo " Installing in $CPDIR"
 
 echo "Compiling modules to bytecode..."
