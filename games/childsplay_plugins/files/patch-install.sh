diff -U 4 -r -N ./install.sh.orig ./install.sh
--- ./install.sh.orig	Fri Mar 18 09:51:09 2005
+++ ./install.sh	Tue Mar 22 18:33:38 2005
@@ -1,5 +1,5 @@
-#!/bin/bash 
+#!/bin/sh 
 # install childsplay.  
 # Be aware that childsplay probably won't work when you edit this file :-(
 # As of 11/2004 childsplay will be converted to follow the File System
 # Hierarchy (FSH).
@@ -18,16 +18,16 @@
 then PREFIX=$1
 fi
 
 LOCALEDIR=$PREFIX/share/locale
-ASSETMLDIR=/usr/share/assetml
+ASSETMLDIR=$PREFIX/share/gnome/assetml
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
 
 ##################################################
@@ -66,23 +66,8 @@
 fi
 
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
 
 if [ `expr $VERSION \< $DEPEN` -eq 1 ]
 then
@@ -91,11 +76,8 @@
     echo "exit";
     exit 1
 fi
 
-
-echo "Compiling modules to bytecode..."
-$PYTHON $CPDIR/install.py --compile $CWD/lib
 
 echo " Copy libraries"
 for DIR in `ls $CWD/lib`
 do 
