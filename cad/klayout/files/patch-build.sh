--- build.sh.orig	Sat Apr 28 23:13:29 2007
+++ build.sh	Sat Apr 28 23:13:40 2007
@@ -61,12 +61,12 @@
   exit 1
 fi
 
-if [ ! -r $QTDIR/bin/moc ]; then
+if [ ! -r $QTDIR/bin/moc-qt4 ]; then
   echo "*** ERROR: unable to locate Qt MOC in $QTDIR/bin"
   exit 1
 fi
 
-if [ ! -r $QTDIR/bin/uic ]; then
+if [ ! -r $QTDIR/bin/uic-qt4 ]; then
   echo "*** ERROR: unable to locate Qt UIC in $QTDIR/bin"
   exit 1
 fi
