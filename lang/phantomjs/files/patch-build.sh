--- build.sh.orig	2015-05-24 22:42:43.825783273 +0900
+++ build.sh	2015-05-27 15:04:32.203956214 +0900
@@ -152,12 +152,12 @@
 
 if [[ "$QTCORE" == "bundled" ]]; then
     export QMAKE=$PWD/src/qt/qtbase/bin/qmake
-    ( cd src/qt && ./preconfig.sh $QTDEPLIBS $QT_CFG )
+    ( cd src/qt && bash -x ./preconfig.sh $QTDEPLIBS $QT_CFG )
 
     echo
     echo "Building Qt..."
     echo
-    ( cd src/qt/qtbase && make -j$COMPILE_JOBS $MAKE_S )
+    ( cd src/qt/qtbase && ${GMAKE} -j$COMPILE_JOBS $MAKE_S )
 else
     export QMAKE=qmake
     # some Linux distros (e.g. Debian) allow you to parallel-install
@@ -189,7 +189,7 @@
 
     ( cd src/qt/qtwebkit &&
         $QMAKE "WEBKIT_CONFIG -= $WEBKIT_DISABLE" $QMAKE_ARGS &&
-        make -j$COMPILE_JOBS $MAKE_S )
+        ${GMAKE} -j$COMPILE_JOBS $MAKE_S )
 fi
 
 echo
