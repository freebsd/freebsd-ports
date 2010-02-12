--- adm_local/unix/config_files/check_pyqt.m4.orig	2009-07-06 18:46:14.000000000 +0700
+++ adm_local/unix/config_files/check_pyqt.m4	2009-10-18 21:16:14.000000000 +0700
@@ -85,7 +85,7 @@
         else
             if test -d $d ; then
                 AC_CHECK_FILE(${d}/pyuic4,pyqt_ok=yes,pyqt_ok=no)
-      	        if test "x$pyqt_ok" == "xyes" ; then
+      	        if test "x$pyqt_ok" = "xyes" ; then
                     PYUIC=${d}/pyuic4
                     break
                 fi
@@ -95,7 +95,7 @@
 fi
 
 dnl check PyQt version
-if test "x$pyqt_ok" == "xyes" ; then
+if test "x$pyqt_ok" = "xyes" ; then
     AC_MSG_CHECKING(whether PyQt version >= 4.2)
     PYQT_VERSION=`${PYUIC} --version 2>&1 | grep "Python User Interface Compiler"`
     if test "$?" != "0" ; then
@@ -120,7 +120,7 @@
     AC_MSG_RESULT(Warning! pyuic4 is not found!)
 fi
 
-if test "x$pyqt_ok" == "xyes" ; then
+if test "x$pyqt_ok" = "xyes" ; then
     TESTLIBFILE=QtCore.so
     TESTSIPFILE=QtCore/QtCoremod.sip
     TEST_LIB_DIRS=""
@@ -156,7 +156,7 @@
     for d in ${TEST_LIB_DIRS} ; do
         if test -d $d ; then
             AC_CHECK_FILE(${d}/${TESTLIBFILE},pyqt_ok=yes,pyqt_ok=no)
-            if test "x$pyqt_ok" == "xyes" ; then
+            if test "x$pyqt_ok" = "xyes" ; then
                 if test "x${d}" = "x/usr/lib${LIB_LOCATION_SUFFIX}" ; then
                     PYQT_LIBS=""
                 else
@@ -168,12 +168,12 @@
     done
 
     dnl check PyQt sips
-    if test "x$pyqt_ok" == "xyes" ; then
+    if test "x$pyqt_ok" = "xyes" ; then
         pyqt_ok=no
         for d in ${TEST_SIPS_DIRS} ; do
             if test -d $d ; then
                 AC_CHECK_FILE(${d}/${TESTSIPFILE},pyqt_ok=yes,pyqt_ok=no)
-                if test "x$pyqt_ok" == "xyes" ; then
+                if test "x$pyqt_ok" = "xyes" ; then
                     PYQT_SIPS=${d}
                     PYQT_INCLUDES="-I ${d}"
                     PYQT_INCLUDES="${PYQT_INCLUDES} -I ${d}/QtCore -I ${d}/QtGui"
@@ -183,7 +183,7 @@
                     PYQT_INCLUDES="${PYQT_INCLUDES} -I ${d}/QtSvg -I ${d}/QtTest"
 
                     # check compatibility with Qt
-                    SUPPORTED=`grep -e "[[[:space:]]]*Qt_[[[:digit:]_]]\+}" ${PYQT_SIPS}/QtCore/QtCoremod.sip | sed -e "s/\(.*\)[[[:space:]]]*\(Qt_[[[:digit:]_]]\+\)}/\2/g"`
+                    SUPPORTED=`grep -e "[[[:space:]]]*Qt_[[[:digit:]_]]\+}" ${PYQT_SIPS}/QtCore/QtCoremod.sip | sed -e "s/\(.*\)[[[:space:]]]*\(Qt_[[[:digit:]_]]\+\)}/\2/g" | nawk '{res=$(NF); sub(/\}/,"",res); print res; }'`
                     SUPPORTED=`echo $SUPPORTED | sed -e "s/Qt_//g" -e "s/_/./g"`
                     SUPPORTED_ID=`echo $SUPPORTED | awk -F. '{v=$[1]*10000+$[2]*100+$[3];print v}'`
                     if test $SUPPORTED_ID -lt $QT_VERSION_ID ; then 
