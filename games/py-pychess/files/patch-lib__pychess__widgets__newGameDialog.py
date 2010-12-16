--- ./lib/pychess/widgets/newGameDialog.py.orig	2010-07-20 10:32:05.000000000 +0200
+++ ./lib/pychess/widgets/newGameDialog.py	2010-12-16 11:41:52.000000000 +0100
@@ -454,7 +454,7 @@
             cls.sourcebuffer.set_highlight_syntax(True)
         # Init old version
         else:
-            os.environ["XDG_DATA_DIRS"] = getDataPrefix()+":/usr/share/"
+            os.environ["XDG_DATA_DIRS"] = getDataPrefix()+":%%PREFIX%%/share/"
             man = LanguageManager()
             for lang in man.get_available_languages():
                 if lang.get_name() == "PGN":
