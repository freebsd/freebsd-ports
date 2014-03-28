--- build.sh.orig	2014-02-24 05:44:13.000000000 +0900
+++ build.sh	2014-03-14 21:49:48.000000000 +0900
@@ -1,7 +1,7 @@
 #!/bin/sh 
 
 EXEC_NAME=klayout
-OTHER_BIN=""
+OTHER_BIN="strm2gds strm2oas strm2txt strm2cif strm2dxf strmcmp strmclip strmxor"
 
 CURR_DIR=`pwd`
 PLATFORM="linux-32-gcc-release"
@@ -33,6 +33,9 @@
     exit 1
   fi
   ;;
+FreeBSD)
+  PLATFORM="freebsd-32-gcc-release"
+  ;;
 *)
   # Assume Linux for the remaining variants
   case `arch` in
@@ -284,11 +287,11 @@
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
@@ -409,12 +412,12 @@
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
