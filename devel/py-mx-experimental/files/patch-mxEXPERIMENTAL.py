--- mxEXPERIMENTAL.py.orig	Mon Nov 26 12:44:48 2001
+++ mxEXPERIMENTAL.py	Mon Nov 26 12:45:52 2001
@@ -140,7 +140,7 @@
 
             mx_Extension('mx.Number.mxNumber.mxNumber',
                          ['mx/Number/mxNumber/mxNumber.c'],
-                         include_dirs=['mx/Number/mxNumber']),
+                         include_dirs=['mx/Number/mxNumber', 'LIBGMPH']),
 
             ]
 else:
@@ -160,7 +160,6 @@
     'mx/Number/README',
     'mx/Number/mxNumber/mxNumber.h',
     'mx/Number/mxNumber/mxh.h',
-    'mx/Number/mxNumber/gmp.h',
 
     # mxTidy
     'mx/Tidy/Doc/mxTidy.html',
