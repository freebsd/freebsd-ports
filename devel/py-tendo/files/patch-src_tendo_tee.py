Description: Use shlex.quote instead of pipes.quote (pipes was removed in
  Python 3.13).
Issue ID: none
Changeset: https://github.com/pycontribs/tendo/commit/938d220
TODO: Drop when updating to a release after 0.3.0.

--- src/tendo/tee.py.orig	2022-10-09 20:02:06 UTC
+++ src/tendo/tee.py
@@ -3,7 +3,7 @@ import os
 import codecs
 import logging
 import os
-import pipes
+import shlex
 from six import string_types
 import subprocess
 import sys
@@ -51,7 +51,7 @@ def system2(cmd, cwd=None, logger=_sentinel, stdout=_s
     # because collections.Iterable seems to be missing on Debian Python 2.5.5
     # (but not on OS X 10.8 with Python 2.5.6)
     if hasattr(cmd, '__iter__'):
-        cmd = " ".join(pipes.quote(s) for s in cmd)
+        cmd = " ".join(shlex.quote(s) for s in cmd)
 
     t = time.process_time()
     output = []
