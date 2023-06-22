--- setuptools/package_index.py.orig	2022-07-04 02:25:25 UTC
+++ setuptools/package_index.py
@@ -197,7 +197,7 @@ def unique_values(func):
     return wrapper
 
 
-REL = re.compile(r"""<([^>]*\srel\s*=\s*['"]?([^'">]+)[^>]*)>""", re.I)
+REL = re.compile(r"""<([^>]*\srel\s{0,10}=\s{0,10}['"]?([^'" >]+)[^>]*)>""", re.I)
 # this line is here to fix emacs' cruddy broken syntax highlighting
 
 
