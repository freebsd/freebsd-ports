--- ./ninja_ide/resources.py.orig	2012-08-23 01:57:46.000000000 +0200
+++ ./ninja_ide/resources.py	2012-09-11 10:44:09.000000000 +0200
@@ -40,6 +40,8 @@
     PRJ_PATH = os.path.abspath(os.path.dirname(sys.executable))
 
 HOME_NINJA_PATH = os.path.join(HOME_PATH, ".ninja_ide")
+if not os.path.isdir(HOME_NINJA_PATH):
+    os.mkdir(HOME_NINJA_PATH)
 
 ADDINS = os.path.join(HOME_NINJA_PATH, "addins")
 
