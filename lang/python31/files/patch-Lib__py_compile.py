# Description: python3 py_compile does not ignore UTF-8 BOM characters 
# Issue:  http://bugs.python.org/issue8168
# Commit: http://hg.python.org/cpython/rev/e15a8a476494/
# PR:     ports/186034

--- ./Lib/py_compile.py.orig	2014-02-21 23:28:42.491208180 +1100
+++ ./Lib/py_compile.py	2014-02-21 23:29:22.052513709 +1100
@@ -7,8 +7,8 @@
 import imp
 import marshal
 import os
-import re
 import sys
+import tokenize
 import traceback
 
 MAGIC = imp.get_magic()
@@ -78,21 +78,6 @@
                    (x >> 16) & 0xff,
                    (x >> 24) & 0xff]))
 
-def read_encoding(file, default):
-    """Read the first two lines of the file looking for coding: xyzzy."""
-    f = open(file, "rb")
-    try:
-        for i in range(2):
-            line = f.readline()
-            if not line:
-                break
-            m = re.match(br".*\bcoding:\s*(\S+)\b", line)
-            if m:
-                return m.group(1).decode("ascii")
-        return default
-    finally:
-        f.close()
-
 def compile(file, cfile=None, dfile=None, doraise=False):
     """Byte-compile one Python source file to Python bytecode.
 
@@ -128,7 +113,8 @@
     directories).
 
     """
-    encoding = read_encoding(file, "utf-8")
+    with open(file, "rb") as f:
+        encoding = tokenize.detect_encoding(f.readline)[0]
     f = open(file, 'U', encoding=encoding)
     try:
         timestamp = int(os.fstat(f.fileno()).st_mtime)
