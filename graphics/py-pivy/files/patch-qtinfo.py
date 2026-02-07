commit 9075d5a5fc7bd7f0144667e12e26e0aa8f7bb4c2
Author: Christoph Moench-Tegeder <cmt@burggraben.net>

    our qmake is qmake6

diff --git qtinfo.py qtinfo.py
index 49b03b4..986960a 100644
--- qtinfo.py
+++ qtinfo.py
@@ -7,7 +7,7 @@ class QtInfo(object):
         if qmake_command:
             self._qmake_command = qmake_command
         else:
-            self._qmake_command = [find_executable("qmake"),]
+            self._qmake_command = [find_executable("qmake6"),]
         self._dict = {}
         # bind all variables early at __init__ time.
         for thing in self.__class__.__dict__:
@@ -79,4 +79,4 @@ class QtInfo(object):
     translations_dir = property(getTranslationsPath)
     headers_dir = property(getHeadersPath)
     docs_dir = property(getDocsPath)
-    qml_dir = property(getQmlPath)
\ No newline at end of file
+    qml_dir = property(getQmlPath)
