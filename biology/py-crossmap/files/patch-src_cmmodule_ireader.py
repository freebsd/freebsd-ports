Description: Open http, https and ftp inputs with urllib.request.urlopen();
  urllib.urlopen() is Python 2 only, so remote chain and input files failed
  with AttributeError.
Issue ID: none
Changeset: none
TODO: Submit upstream; drop once a release includes the fix.

--- src/cmmodule/ireader.py.orig	2023-07-19 20:45:52 UTC
+++ src/cmmodule/ireader.py
@@ -4,7 +4,7 @@
 import sys
 import bz2
 import gzip
-import urllib
+import urllib.request
 from subprocess import Popen, PIPE
 
 
@@ -19,7 +19,7 @@ def nopen(f, mode="rb"):
     return {"r": sys.stdin, "w": sys.stdout}[mode[0]] if f == "-" \
         else gzip.open(f, mode) if f.endswith((".gz", ".Z", ".z")) \
         else bz2.BZ2File(f, mode) if f.endswith((".bz", ".bz2", ".bzip2")) \
-        else urllib.urlopen(f) if f.startswith(("http://", "https://", "ftp://")) \
+        else urllib.request.urlopen(f) if f.startswith(("http://", "https://", "ftp://")) \
         else open(f, mode)
 
 
