--- install.sh.orig	2005-03-20 14:29:18.000000000 +0000
+++ install.sh
@@ -1,8 +1,7 @@
-#!/bin/bash 
+#!/bin/sh 
 # install plugin in the standard childsplay path  
 
-PREFIX=/usr/local
-DESTDIR=$PREFIX/share/childsplay
+INSTDIR=${DESTDIR}${PREFIX}/share/childsplay
 
 ###########################################################
 #    DO NOT EDIT BEHIND THIS POINT
@@ -13,47 +12,21 @@ DESTDIR=$PREFIX/share/childsplay
 DEPEN=0.71
  
 set -e
-CWD=`pwd`
 
-USERID=`id | sed -e 's/).*//; s/^.*(//;'`
-if [ "$USERID" != "root" ]; then
-    echo " You must be root to install the plugins"
-    echo " exit"
-    exit 1
-fi
-
-echo -e "\n>>>>>>>>>>> Install childsplay plugins >>>>>>>>>>>>>>>>>>>>"
-echo -e "\n This release depends on childsplay version $DEPEN"
-echo -n " Cheking version = "
-VERSION=$(childsplay --version)
-echo $VERSION
-
-if [ `expr $VERSION \< $DEPEN` -eq 1 ];then
-    echo " Childsplay version incorrect, please upgrade to at least"
-    echo " version $DEPEN"
-    echo "exit"
-    exit 1
-fi
+# We can't run childsplay because it tries to write to $HOME/.schoolsplay.rc
+# Which is not permitted in strict build environements.  It is not necessary
+# anyway beecause the version is much higher than 0.71 already!
+
+#echo -e "\n>>>>>>>>>>> Install childsplay plugins >>>>>>>>>>>>>>>>>>>>"
+#echo -e "\n This release depends on childsplay version $DEPEN"
+#echo -n " Cheking version = "
+#VERSION=$(childsplay --version)
+#echo $VERSION
    
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
-cp -rf $CWD/AlphabetSounds $DESTDIR/Data/
+mkdir -p ${INSTDIR}/Data
+cp -rf AlphabetSounds ${INSTDIR}/Data/
 
 echo -e "\n Everything installed, enjoy\n"
