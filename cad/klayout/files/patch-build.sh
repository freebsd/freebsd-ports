--- build.sh.orig	2008-08-17 06:40:32.000000000 +0900
+++ build.sh	2008-08-23 09:47:35.000000000 +0900
@@ -136,11 +136,11 @@
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
@@ -238,7 +238,7 @@
   mkdir -p $BIN
   cp $BUILD/main/$EXEC_NAME $BIN
   for bin in $OTHER_BIN; do
-    cp $BUILD/$bin $BIN
+    cp $BUILD/main/$bin $BIN
   done
   for plugin in $PLUGINS; do
     cp $BUILD/$plugin/*.so $BIN
@@ -249,12 +249,12 @@
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
 
