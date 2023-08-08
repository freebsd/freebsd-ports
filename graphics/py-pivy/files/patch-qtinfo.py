--- qtinfo.py.orig	2023-03-13 20:25:16.070089000 +0100
+++ qtinfo.py	2023-03-13 20:26:18.492969000 +0100
@@ -7,7 +7,7 @@
         if qmake_command:
             self._qmake_command = qmake_command
         else:
-            self._qmake_command = [find_executable("qmake"),]
+            self._qmake_command = [find_executable("qmake-qt5"),]
         self._dict = {}
         # bind all variables early at __init__ time.
         for thing in self.__class__.__dict__:
@@ -79,4 +79,4 @@
     translations_dir = property(getTranslationsPath)
     headers_dir = property(getHeadersPath)
     docs_dir = property(getDocsPath)
-    qml_dir = property(getQmlPath)
\ No newline at end of file
+    qml_dir = property(getQmlPath)
