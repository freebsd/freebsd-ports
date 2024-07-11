--- m4/python.m4.orig	2021-10-04 02:51:12 UTC
+++ m4/python.m4
@@ -37,9 +37,12 @@ AC_DEFUN([AM_PATH_PYTHON],
   dnl Find a Python interpreter.  Python versions prior to 2.0 are not
   dnl supported. (2.0 was released on October 16, 2000).
   m4_define_default([_AM_PYTHON_INTERPRETER_LIST],
-[python python2 python3 dnl
+[python python3 dnl
+ python3.20 python3.19 python3.18 python3.17 python3.16 dnl
+ python3.15 python3.14 python3.13 python3.12 python3.11 python3.10 dnl
  python3.9 python3.8 python3.7 python3.6 python3.5 python3.4 python3.3 dnl
  python3.2 python3.1 python3.0 dnl
+ python2 dnl
  python2.7 python2.6 python2.5 python2.4 python2.3 python2.2 python2.1 dnl
  python2.0])
 
