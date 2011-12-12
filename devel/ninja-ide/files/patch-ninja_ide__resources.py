$FreeBSD$
--- ./ninja_ide/resources.py.orig	2011-10-25 02:41:30.000000000 +0200
+++ ./ninja_ide/resources.py	2011-12-12 00:42:45.000000000 +0100
@@ -39,6 +39,8 @@
     PRJ_PATH = os.path.abspath(os.path.dirname(sys.executable))
 
 HOME_NINJA_PATH = os.path.join(HOME_PATH, ".ninja_ide")
+if not os.path.isdir(HOME_NINJA_PATH):
+    os.mkdir(HOME_NINJA_PATH)
 
 ADDINS = os.path.join(HOME_NINJA_PATH, "addins")
 
@@ -53,7 +55,7 @@
 
 EDITOR_SKINS = os.path.join(HOME_NINJA_PATH, "addins", "schemes")
 
-START_PAGE_URL = os.path.join(PRJ_PATH, "doc", "startPage.html")
+START_PAGE_URL = os.path.join("%%DOCSDIR%%", "startPage.html")
 
 LOG_FILE_PATH = os.path.join(HOME_NINJA_PATH, 'ninja_ide.log')
 
