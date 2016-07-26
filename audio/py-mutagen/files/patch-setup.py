--- setup.py.orig	2016-06-07 11:07:56 UTC
+++ setup.py
@@ -214,7 +214,7 @@ class coverage_cmd(Command):
 
 
 if os.name == "posix":
-    data_files = [('share/man/man1', glob.glob("man/*.1"))]
+    data_files = [('man/man1', glob.glob("man/*.1"))]
 else:
     data_files = []
 
