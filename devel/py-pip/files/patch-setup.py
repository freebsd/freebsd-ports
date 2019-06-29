--- setup.py.orig	2018-11-13 02:28:08 UTC
+++ setup.py
@@ -73,8 +73,8 @@ setup(
     entry_points={
         "console_scripts": [
             "pip=pip._internal:main",
-            "pip%s=pip._internal:main" % sys.version_info[:1],
-            "pip%s.%s=pip._internal:main" % sys.version_info[:2],
+#            "pip%s=pip._internal:main" % sys.version_info[:1],
+#            "pip%s.%s=pip._internal:main" % sys.version_info[:2],
         ],
     },
 
