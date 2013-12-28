--- configure.qt.inc.orig	2013-01-06 09:53:52.000000000 -0500
+++ configure.qt.inc	2013-07-16 21:39:12.000000000 -0500
@@ -51,10 +51,19 @@
 QT4MOC=""  # full path to Qt4 moc
 # QT4DIR="" # for testing purposes
 
-
+AC_ARG_WITH([qt-includes],
+AC_HELP_STRING([--with-qt-includes=<path>],
+    [path to qt4 include files]),
+    [QT4INC=$with_qt_includes])
+
+AC_ARG_WITH([qt-libraries],
+AC_HELP_STRING([--with-qt-libraries=<path>],
+    [path to qt4 libraries]),
+    [QT4LIBS=$with_qt_libraries])
 
 
 # Task 1: find Qt4 include directory, and for QT4 library
+
 PKG_CHECK_MODULES([QT4], [ "QtCore QtGui"],
 			 [ AC_SUBST(QT4INC, $QT4_CFLAGS) AC_SUBST(QT4LIBS) ],
 			 [ AC_MSG_ERROR([Qt4 libs not found])
@@ -66,8 +75,12 @@
 # Task 2: find Qt4 moc
 QT4MOC=""
 QT4MOC_PATH=""
-
-if [[[ $QT4DIR = "" ]]] ; then
+QT4MOC_PATH=${MOC}
+if [[ $MOC ]] ; then
+  QT4MOC_PATH=${MOC}
+  ac_cv_path_QT4MOC_PATH=$MOC
+  echo ac_cv_path_QT4MOC_PATH $ac_cv_path_QT4MOC_PATH
+elif [[ -z $QT4DIR ]] ; then
 
     # we should guess where Qt4 moc binary is;
     # first we see if we are lucky and Qt4 moc installed on build machine
@@ -93,17 +106,15 @@
 
 
 
-
-
 # Task 3: make sure that major version of the moc is >= MOC_MAJOR_EARLIEST
-if [[[ "$QT4MOC_PATH" != "" ]]] ; then
+if [[ "$QT4MOC_PATH" ]] ; then
     MOC_VERSION="`$QT4MOC_PATH -v 2>&1 | sed -e 's;.*(Qt ;;' -e 's;).*;;'`"
-    if [[[ "$MOC_VERSION" != "" ]]] ; then
+    if [[ "$MOC_VERSION" ]] ; then
 	MOC_MAJOR="`echo $MOC_VERSION | sed -e 's;\..*;;'`"
 	expr "$MOC_MAJOR" + 0 >/dev/null 2>/dev/null
 	status=$?
-	if [[[ "$MOC_MAJOR" != "" && $status = 0 ]]] ; then
-	    if [[[ "$MOC_MAJOR" < "$MOC_MAJOR_EARLIEST" ]]] ; then
+	if [[ "$MOC_MAJOR" -a $status = "0" ]] ; then
+	    if [[ "$MOC_MAJOR" -lt "$MOC_MAJOR_EARLIEST" ]] ; then
 		AC_MSG_WARN("Found moc $MOC_VERSION - unable to build xcwcp")
 		AC_MSG_WARN(["xcwcp requires moc version >= $MOC_MAJOR_EARLIEST"])
 	    else
@@ -126,16 +137,16 @@
 
 
 # Task 4: on success set up some build system variables (AC_SUBST)
-if [[[ $QT4INC != "" && $QT4MOC != "" ]]] ; then
+if [[ "$QT4INC" -a "$QT4MOC" ]] ; then
     echo "Qt4 headers dir is $QT4INC"
     echo "Qt4 moc is $QT4MOC"
 
 else
-    if [[[ $QT4INC = "" ]]] ; then
+    if [[ "$QT4INC" ]] ; then
 	AC_MSG_WARN(["Can't find directory with Qt4 header files - unable to build xcwcp"])
     fi
 
-    if [[[ $QT4MOC = "" ]]] ; then
+    if [[ "$QT4MOC" ]] ; then
 	AC_MSG_WARN(["Can't find Qt moc version >= $MOC_MAJOR_EARLIEST - unable to build xcwcp"])
 	AC_MSG_WARN(["Hint: to build xcwcp make sure that moc is in QT4DIR/bin on your PATH"])
     fi
