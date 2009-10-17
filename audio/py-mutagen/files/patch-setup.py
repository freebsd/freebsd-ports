--- setup.py.orig	2009-06-16 07:04:23.000000000 +0200
+++ setup.py	2009-09-11 09:45:41.000000000 +0200
@@ -185,7 +185,7 @@
             100.0 * (total_lines - bad_lines) / float(total_lines))
 
 if os.name == "posix":
-    data_files = [('share/man/man1', glob.glob("man/*.1"))]
+    data_files = [('man/man1', glob.glob("man/*.1"))]
 else:
     data_files = []
 
