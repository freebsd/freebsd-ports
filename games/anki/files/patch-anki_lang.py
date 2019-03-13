--- anki/lang.py.orig	2018-09-27 01:52:01 UTC
+++ anki/lang.py
@@ -84,7 +84,7 @@ def langDir():
     if isMac:
         dir = os.path.abspath(filedir + "/../../Resources/locale")
     else:
-        dir = os.path.join(filedir, "locale")
+        dir = os.path.join(filedir, "%%PREFIX%%/share/locale")
     if not os.path.isdir(dir):
         dir = os.path.join(os.path.dirname(sys.argv[0]), "locale")
     if not os.path.isdir(dir):
