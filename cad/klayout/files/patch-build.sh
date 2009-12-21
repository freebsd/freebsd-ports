--- build.sh.orig	2009-12-18 07:52:08.000000000 +0900
+++ build.sh	2009-12-21 01:30:05.000000000 +0900
@@ -158,11 +158,11 @@
   ;;
 esac
 
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
@@ -268,21 +268,21 @@
 
 # -- Installing binaries  --
 
-echo "Installing binaries .."
-cd $BUILD
-$MAKE_PRG install
-cd $CURR_DIR
+#echo "Installing binaries .."
+#cd $BUILD
+#$MAKE_PRG install
+#cd $CURR_DIR
 echo "Build done."
 
 if [ $WIN_CYGWIN = 0 ]; then
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
 fi
 
 exit 0
