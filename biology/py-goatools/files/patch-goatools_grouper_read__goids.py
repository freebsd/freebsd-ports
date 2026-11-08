Description: Use importlib.util.find_spec() instead of pkgutil.find_loader(),
  removed in Python 3.14.
Issue ID: none (not yet reported)
Changeset: none
TODO: Report upstream (upstream is alive); drop once a release no longer uses
  pkgutil.find_loader().

--- goatools/grouper/read_goids.py.orig	2026-03-13 07:44:27 UTC
+++ goatools/grouper/read_goids.py
@@ -5,8 +5,8 @@ import re
 import os
 import sys
 import re
-import pkgutil
 import importlib
+import importlib.util
 from goatools.gosubdag.go_tasks import chk_goids
 from goatools.grouper.hdrgos import HdrgosSections
 from goatools.grouper.grprobj import Grouper
@@ -26,7 +26,7 @@ def read_sections(sections_file, exclude_ungrouped=Fal
         return ReadGoids().read_sections(sections_file, False, exclude_ungrouped)
     # Is 'sections_file' a module string?
     if '/' not in sections_file and r'\\' not in sections_file and \
-            pkgutil.find_loader(sections_file) is not None:
+            getattr(importlib.util.find_spec(sections_file), 'loader', None) is not None:
         mod = importlib.import_module(sections_file)
         var = getattr(mod, 'SECTIONS', None)
         if var is not None:
