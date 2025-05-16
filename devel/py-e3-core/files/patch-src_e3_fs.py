--- src/e3/fs.py.orig	2025-03-28 13:21:34 UTC
+++ src/e3/fs.py
@@ -58,7 +58,7 @@ def cp(
     if copy_attrs:
         switches += " -p"
     if recursive:
-        switches += " -r"
+        switches += " -R"
     logger.debug("cp %s %s->%s", switches, source, target)
 
     if recursive and not copy_attrs:
