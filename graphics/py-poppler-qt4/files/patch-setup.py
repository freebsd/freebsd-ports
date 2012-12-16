--- ./setup.py.orig	2012-11-09 13:58:09.000000000 -0500
+++ ./setup.py	2012-12-12 07:47:48.000000000 -0500
@@ -21,6 +21,7 @@
         'Programming Language :: Python',
         'Topic :: Multimedia :: Graphics :: Viewers',
     ],
+    zip_safe = False,
    cmdclass={}
 )
 
