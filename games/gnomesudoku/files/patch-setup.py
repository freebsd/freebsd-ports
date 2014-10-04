--- setup.py.orig	2014-10-04 20:26:24 UTC
+++ setup.py
@@ -43,7 +43,7 @@
     except ImportError:
         sys.exit('Error: PyGTK-2.6 or newer is required.')
         raise
-    mod_list = ['Image','gnomeprint','Numeric']
+    mod_list = ['PIL','gnomeprint','Numeric']
     ok = 1
     for m in mod_list:
         try:
