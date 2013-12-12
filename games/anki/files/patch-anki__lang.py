--- ./anki/lang.py.orig	2013-10-11 06:12:53.000000000 +0200
+++ ./anki/lang.py	2013-12-12 21:03:11.000000000 +0100
@@ -76,7 +76,7 @@
     if not os.path.isdir(dir):
         dir = os.path.join(os.path.dirname(sys.argv[0]), "locale")
     if not os.path.isdir(dir):
-        dir = "/usr/share/anki/locale"
+        dir = "/usr/local/share/locale"
     return dir
 
 def setLang(lang, local=True):
