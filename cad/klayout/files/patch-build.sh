--- build.sh.orig	2016-06-19 16:35:28 UTC
+++ build.sh
@@ -3,7 +3,7 @@
 EXEC_NAME=klayout
 IS_MAC="no"
 EXEC_HOLDER=""
-OTHER_BIN=""
+OTHER_BIN="strm2gds strm2oas strm2txt strm2cif strm2dxf strmcmp strmclip strmxor"
 
 CURR_DIR=`pwd`
 PLATFORM="linux-32-gcc-release"
@@ -39,6 +39,9 @@ Darwin*)
   PLATFORM="mac-yosemite-gcc-release"
   EXEC_HOLDER="klayout.app/Contents/MacOS"
   ;;
+FreeBSD)
+  PLATFORM="freebsd-32-gcc-release"
+  ;;
 *)
   # Assume Linux for the remaining variants
   case `arch` in
@@ -374,7 +377,7 @@ if [ $HAVE_64BIT_COORD != 0 ]; then
   echo "    64 bit coordinates enabled"
 fi
 
-gcc_path=`type gcc 2>/dev/null`
+gcc_path=`type $CC 2>/dev/null`
 if [ "$gcc_path" = "" ]; then
   echo "*** ERROR: unable to locate gcc in path"
   exit 1
@@ -398,11 +401,11 @@ mac-*)
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
@@ -463,11 +466,7 @@ else
   cd $CURR_DIR
 fi
 
-if ( gmake -v >/dev/null 2>/dev/null ); then
-  MAKE_PRG=gmake
-else
-  MAKE_PRG=make
-fi
+MAKE_PRG="gmake ${_MAKE_JOBS}"
 
 mkdir -p $BUILD
 echo "WIN_CYGWIN=$WIN_CYGWIN"  >$BUILD/Makefile
@@ -515,6 +514,9 @@ echo "PYTHONINCLUDE=$PYTHONINCLUDE" >>$B
 echo "HAVE_PYTHON=$HAVE_PYTHON" >>$BUILD/Makefile.env
 echo "HAVE_QTBINDINGS=$HAVE_QTBINDINGS" >>$BUILD/Makefile.env
 echo "HAVE_64BIT_COORD=$HAVE_64BIT_COORD" >>$BUILD/Makefile.env
+echo "CFLAGS=$CFLAGS" >>$BUILD/Makefile.env
+echo "CXXFLAGS=$CXXFLAGS" >>$BUILD/Makefile.env
+echo "LDLAGS=$LDFLAGS" >>$BUILD/Makefile.env
 
 echo "Building plugins: $PLUGINS"
 echo ""
@@ -549,12 +551,12 @@ if [ $WIN_CYGWIN = 0 ]; then
   fi
   echo ""
   echo "Final binary is ready in $EXEC_FULL_PATH."
-  echo "To run it, you may need to add the following to your LD_LIBRARY_PATH:"
-  echo "$QTLIB"
+#  echo "To run it, you may need to add the following to your LD_LIBRARY_PATH:"
+#  echo "$QTLIB"
 
-  LD_LIBRARY_PATH=$QTLIB:$LD_LIBRARY_PATH
-  $EXEC_FULL_PATH -v
-  $EXEC_FULL_PATH -h
+#  LD_LIBRARY_PATH=$QTLIB:$LD_LIBRARY_PATH
+#  $EXEC_FULL_PATH -v
+#  $EXEC_FULL_PATH -h
 fi
 
 exit 0
