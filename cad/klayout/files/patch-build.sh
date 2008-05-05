--- build.sh.orig	Fri Nov  9 04:31:36 2007
+++ build.sh	Sun Jan  6 18:57:53 2008
@@ -126,11 +126,11 @@
   exit 1
 fi
 
-if [ ! -r $QTBIN/moc ]; then
+if [ ! -r $QTBIN/moc-qt4 ]; then
   echo "*** ERROR: unable to locate Qt MOC in $QTBIN"
   exit 1
 fi
-if [ ! -r $QTBIN/uic ]; then
+if [ ! -r $QTBIN/uic-qt4 ]; then
   echo "*** ERROR: unable to locate Qt UIC in $QTBIN"
   exit 1
 fi
@@ -231,12 +231,12 @@
   echo "Build done."
   echo ""
   echo "Final binary is ready in $BIN/$EXEC_NAME."
-  echo "To run it, you may need to add the following to your LD_LIBRARY_PATH:"
-  echo "$QTLIB"
+  #echo "To run it, you may need to add the following to your LD_LIBRARY_PATH:"
+  #echo "$QTLIB"
   
-  LD_LIBRARY_PATH=$QTLIB:$LD_LIBRARY_PATH
-  $BIN/$EXEC_NAME -v
-  $BIN/$EXEC_NAME -h
+  #LD_LIBRARY_PATH=$QTLIB:$LD_LIBRARY_PATH
+  #$BIN/$EXEC_NAME -v
+  #$BIN/$EXEC_NAME -h
 
 else 
 
