--- setup.py.orig	Tue Oct  3 03:09:36 2006
+++ setup.py	Tue May  1 12:06:35 2007
@@ -142,7 +142,7 @@
     elif os.name=="nt":
         prefix=""
     else:
-        prefix="/"
+        prefix="%%PREFIX%%/"
 
     packages = []
     data_files = []
