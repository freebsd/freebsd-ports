--- install.sh.orig	Sun Mar 20 06:29:18 2005
+++ install.sh	Mon May 30 20:58:56 2005
@@ -1,5 +1,5 @@
-#!/bin/bash 
+#!/bin/sh 
 # install plugin in the standard childsplay path  
 
 PREFIX=/usr/local
 DESTDIR=$PREFIX/share/childsplay
@@ -34,24 +34,8 @@
     echo "exit"
     exit 1
 fi
    
-echo -e "\n The path to install the soundfiles in is "
-echo " $DESTDIR."
-echo " If you have installed childsplay in a other place, you can"
-echo " give the full path to childsplay, otherwise just hit enter"
-echo " Hit enter to install in $DESTDIR, or give the full path"
-read path
-if [ $path ];then
-    if [ -e $path/install.py ];then
-        DESTDIR=path
-    else
-        echo "*********** WARNING *************"
-        echo " $path does not exists or is not the childsplay directory"
-        echo " exit"
-        exit 1
-    fi
-fi
 echo " Installing in $DESTDIR/Data/AlphabetSounds"
 
 echo " Copy sound files"
 cp -rf $CWD/AlphabetSounds $DESTDIR/Data/
