--- ./setup.py.orig	2013-02-18 20:32:09.721700908 +1100
+++ ./setup.py	2013-02-18 20:32:47.127424592 +1100
@@ -44,4 +44,5 @@
         "Topic :: Software Development",
         "Topic :: Utilities",
     ],
+    zip_safe=False,
     **extra)
