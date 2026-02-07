--- setup.py.orig	2018-07-01 01:42:25 UTC
+++ setup.py
@@ -8,7 +8,7 @@ try:
 os.chdir(os.path.dirname(sys.argv[0]) or ".")
 
 try:
-    long_description = open("README.rst", "U").read()
+    long_description = open("README.rst", "r", encoding="UTF-8").read()
 except IOError:
     long_description = "See https://github.com/wolever/pprintpp"
 
