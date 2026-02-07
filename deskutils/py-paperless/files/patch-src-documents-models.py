--- src/documents/models.py.orig	2019-01-27 13:48:05 UTC
+++ src/documents/models.py
@@ -483,8 +483,14 @@ class FileInfo:
           "<title>.<suffix>"
         """
 
+        filename = os.path.basename(path)
+        for (pattern, repl) in settings.FILENAME_PARSE_TRANSFORMS:
+            (filename, count) = pattern.subn(repl, filename)
+            if count:
+                break
+
         for regex in cls.REGEXES.values():
-            m = regex.match(os.path.basename(path))
+            m = regex.match(filename)
             if m:
                 properties = m.groupdict()
                 cls._mangle_property(properties, "created")
