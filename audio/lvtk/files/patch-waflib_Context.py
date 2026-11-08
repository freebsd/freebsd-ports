-- Replace the 'imp' module with 'types', because 'imp' was removed in
-- Python 3.12, causing waf to fail with "No module named 'imp'" and
-- breaking configure.
-- See https://github.com/lvtk/lvtk/issues/60

--- waflib/Context.py.orig	2026-09-16 00:55:15 UTC
+++ waflib/Context.py
@@ -6,7 +6,7 @@ Classes and functions enabling the command system
 Classes and functions enabling the command system
 """
 
-import os, re, imp, sys
+import os, re, sys, types
 from waflib import Utils, Errors, Logs
 import waflib.Node
 
@@ -660,7 +660,7 @@ def load_module(path, encoding=None):
 	except KeyError:
 		pass
 
-	module = imp.new_module(WSCRIPT_FILE)
+	module = types.ModuleType(WSCRIPT_FILE)
 	try:
 		code = Utils.readf(path, m='r', encoding=encoding)
 	except EnvironmentError:
