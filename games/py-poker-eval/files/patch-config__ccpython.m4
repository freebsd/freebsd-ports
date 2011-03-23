--- config/ccpython.m4.orig	2008-12-26 05:49:24.000000000 +0900
+++ config/ccpython.m4	2011-03-19 04:41:14.000000000 +0900
@@ -110,7 +110,7 @@
 
 AC_DEFUN([ALL_CC_PYTHON],
 [ 
-m4_define([_AM_PYTHON_INTERPRETER_LIST], [python2.6 python2.5 python2.4 python2.3])
+m4_define([_AM_PYTHON_INTERPRETER_LIST], [python2.7 python2.6 python2.5 python2.4 python2.3])
 PYTHONS=''
 found_one=''
 _ONE_CC_PYTHON([=2.3], [2_3])
@@ -124,6 +124,9 @@
 unset PYTHON
 _ONE_CC_PYTHON([=2.6], [2_6])
 if test -f "$PYTHON" ; then found_one=$PYTHON ; PYTHONS="$PYTHON $PYTHONS" ; fi
+unset PYTHON
+_ONE_CC_PYTHON([=2.7], [2_7])
+if test -f "$PYTHON" ; then found_one=$PYTHON ; PYTHONS="$PYTHON $PYTHONS" ; fi
 PYTHON=$found_one
 if ! test "$found_one" ; then
    AC_MSG_ERROR([No python development environments found])
