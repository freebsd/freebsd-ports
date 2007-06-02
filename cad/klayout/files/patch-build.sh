--- build.sh.orig	Tue May  8 04:41:18 2007
+++ build.sh	Sat Jun  2 16:43:04 2007
@@ -77,12 +77,12 @@
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
@@ -153,12 +153,12 @@
   echo "Build done."
   echo ""
   echo "Final binary is ready in $BIN/$EXEC_NAME."
-  echo "To run it, you may need to add the following to your LD_LIBRARY_PATH:"
-  echo "$QTDIR/lib"
+  #echo "To run it, you may need to add the following to your LD_LIBRARY_PATH:"
+  #echo "$QTDIR/lib"
   
-  LD_LIBRARY_PATH=$QTDIR/lib:$LD_LIBRARY_PATH
-  $BIN/$EXEC_NAME -v
-  $BIN/$EXEC_NAME -h
+  #LD_LIBRARY_PATH=$QTDIR/lib:$LD_LIBRARY_PATH
+  #$BIN/$EXEC_NAME -v
+  #$BIN/$EXEC_NAME -h
 
 else 
 
