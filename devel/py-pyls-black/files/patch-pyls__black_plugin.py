--- pyls_black/plugin.py.orig	2021-06-04 22:43:13 UTC
+++ pyls_black/plugin.py
@@ -2,18 +2,18 @@ import toml
 
 import black
 import toml
-from pyls import hookimpl
+from pylsp import hookimpl
 
 _PY36_VERSIONS = {black.TargetVersion[v] for v in ["PY36", "PY37", "PY38", "PY39"]}
 
 
 @hookimpl(tryfirst=True)
-def pyls_format_document(document):
+def pylsp_format_document(document):
     return format_document(document)
 
 
 @hookimpl(tryfirst=True)
-def pyls_format_range(document, range):
+def pylsp_format_range(document, range):
     range["start"]["character"] = 0
     range["end"]["line"] += 1
     range["end"]["character"] = 0
@@ -73,8 +73,14 @@ def load_config(filename: str) -> Dict:
 
     root = black.find_project_root((filename,))
 
-    pyproject_filename = root / "pyproject.toml"
-
+    # Note: find_project_root returns a tuple in 22.1.0+
+    try:
+        # Keeping this to not break backward compatibility.
+        pyproject_filename = root / "pyproject.toml"
+    except TypeError:
+        _root, _ = root
+        pyproject_filename = _root / "pyproject.toml"
+        
     if not pyproject_filename.is_file():
         return defaults
 
