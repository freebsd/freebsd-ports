--- install.sh.orig	Mon Jun 28 13:44:23 2004
+++ install.sh	Sun Aug 22 17:16:36 2004
@@ -1,8 +1,8 @@
-#!/bin/bash 
-# install plugin in the standard childsplay path  
+#!/bin/sh
+# install plugin in the standard childsplay path
 
 PREFIX=/usr/local
-DESTDIR=$PREFIX/games/childsplay
+DESTDIR=$PREFIX/share/childsplay
 
 ###########################################################
 #    DO NOT EDIT BEHIND THIS POINT
@@ -11,7 +11,7 @@
 
 # Dependency, which version of childsplay at least
 DEPEN=0.71
- 
+
 set -e
 CWD=`pwd`
 
@@ -34,23 +34,23 @@
     echo "exit"
     exit 1
 fi
-   
+
 echo -e "\n The path to install the soundfiles in is "
 echo " $DESTDIR."
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
+#echo " If you have installed childsplay in a other place, you can"
+#echo " give the full path to childsplay, otherwise just hit enter"
+#echo " Hit enter to install in $DESTDIR, or give the full path"
+#read path
+#if [ $path ];then
+#    if [ -e $path/install.py ];then
+#        DESTDIR=path
+#    else
+#        echo "*********** WARNING *************"
+#        echo " $path does not exists or is not the childsplay directory"
+#        echo " exit"
+#        exit 1
+#    fi
+#fi
 echo " Installing in $DESTDIR/Data/AlphabetSounds"
 
 echo " Copy sound files"
