--- INSTALL.sh.orig	Wed Apr 20 10:57:03 2005
+++ INSTALL.sh	Wed Apr 20 11:02:16 2005
@@ -1,5 +1,5 @@
-#!/bin/bash
+#!/bin/sh
 # install childsplay.  
 # Be aware that childsplay probably won't work when you edit this file :-(
 # As of 11/2004 childsplay will be converted to follow the File System
 # Hierarchy (FSH).
@@ -21,16 +21,15 @@
 PYTHON=`which python`
 
 EXECDIR=$PREFIX/bin
 LOCALEDIR=$PREFIX/share/locale
-ASSETMLDIR=/usr/share/assetml
+ASSETMLDIR=$PREFIX/share/gnome/assetml
 SCOREDIR=/var/games
 SCOREFILE=$SCOREDIR/childsplay.score
 DOCDIR=$PREFIX/share/doc/childsplay
 MANDIR=$PREFIX/man/man6
-CPDIR=$PREFIX/lib/games/childsplay
+CPDIR=$PREFIX/childsplay
 SHAREDIR=$PREFIX/share/childsplay
-BINDIR=$PREFIX/games
 LIBDIR=$CPDIR/lib
 MODULESDIR=$LIBDIR
 SHARELIBDATADIR=$SHAREDIR/lib
 SHAREDATADIR=$SHAREDIR/Data
@@ -38,10 +37,8 @@
 
 HOME_DIR_NAME=.childsplay
 CHILDSPLAYRC=childsplayrc
 
-OLDCPDIR=$PREFIX/games/childsplay
-
 echo "Making directorys"
 mkdir -vp $CPDIR
 mkdir -vp $CPDIR/lib
 mkdir -vp $DOCDIR
@@ -51,9 +48,8 @@
 mkdir -vp $MANDIR
 mkdir -vp $SHAREDIR
 mkdir -vp $SHAREDATADIR
 mkdir -vp $SHARELIBDATADIR
-mkdir -vp $BINDIR
 mkdir -vp $EXECDIR
 
 set -e
 
@@ -63,13 +59,8 @@
     echo " You must be root to install the plugins"
     echo " exit"
     exit 1
 fi
-echo " Looking for obsolete childsplay files in $OLDCPDIR"
-if [ -e $OLDCPDIR ] && [ -d $OLDCPDIR ]
-then rm -fr $OLDCPDIR
-     echo " Old files removed"
-fi
 
 echo -e "\n>>>>>>>>>>> Install childsplay >>>>>>>>>>>>>>>>>>>>"
 echo " Installing in $PREFIX"
 
@@ -113,22 +105,14 @@
 echo " Copy docs"
 cp -rf $CWD/doc/* $DOCDIR/
 
 echo " Copy executable and setting permissions."
-cp -f $CWD/childsplay.sh $BINDIR/childsplay
 cp -f $CWD/childsplay.sh $EXECDIR/childsplay
-chmod +x $BINDIR/childsplay
 chmod +x $EXECDIR/childsplay
 
 chmod +x $CPDIR/childsplay.py
 chmod +x $CPDIR/letters-trans.py
 
-#echo " Looking for the old executable, if any"
-#if [ -e /usr/local/bin/childsplay ]
-#then rm -f /usr/local/bin/childsplay
-#    echo "found and removed"
-#fi
-
 echo " Setting the base path in childsplay to $PREFIX"
 echo "## Automated file please do not edit" > $CPDIR/BASEPATH.py
 echo "BASEPATH=\"$PREFIX\"" >> $CPDIR/BASEPATH.py
 echo "EXECDIR=\"$EXECDIR\"" >> $CPDIR/BASEPATH.py
@@ -157,9 +141,9 @@
 echo ""
 echo ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
 echo " One thing left todo..."
 echo " Translating words"
-$PYTHON $CPDIR/letters-trans.py $ASSETMLDIR
+echo " to translate words run: $PYTHON $CPDIR/letters-trans.py $ASSETMLDIR"
 echo ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
 echo " Be sure to read the README-MEMORY file on how you can"
 echo " use your own pictures in the memory game."
 echo ""
