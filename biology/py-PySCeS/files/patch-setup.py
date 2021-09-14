--- setup.py.orig	2021-09-14 08:51:28 UTC
+++ setup.py
@@ -284,9 +284,9 @@ mydata_files.append((os.path.join('pysces'), [os.path.
 mydata_files.append(('', [os.path.join('pysces', 'pysces.pth')]))
 
 # JR 2021-08 userguide.pdf included as a symlink to built docs in submodule
-mydata_files.append(
-    (os.path.join("pysces", "docs"), [os.path.join("pysces", "docs", "userguide.pdf")])
-)
+#mydata_files.append(
+#    (os.path.join("pysces", "docs"), [os.path.join("pysces", "docs", "userguide.pdf")])
+#)
 mydata_files.append(
     (
         os.path.join('pysces', 'examples'),
