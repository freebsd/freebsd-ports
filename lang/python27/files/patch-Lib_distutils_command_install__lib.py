From 9934ce31b8447667f71c211e559a8de71e8263db Mon Sep 17 00:00:00 2001
From: Brendan Molloy <brendan@bbqsrc.net>
Date: Mon, 4 Jan 2016 23:14:06 +1100
Subject: [PATCH] Check bytecode file actually exists and tests

Should solve issue 20397, where using the --record argument results
in files that failed to generate bytecode files are added to the
record file nonetheless.
---
 Lib/distutils/command/install_lib.py    | 17 +++++++++++++----
 Lib/distutils/tests/test_install_lib.py |  8 ++++++--
 2 files changed, 19 insertions(+), 6 deletions(-)

--- Lib/distutils/command/install_lib.py.orig	2015-12-05 19:46:56 UTC
+++ Lib/distutils/command/install_lib.py
@@ -168,10 +168,14 @@ class install_lib(Command):
             ext = os.path.splitext(os.path.normcase(py_file))[1]
             if ext != PYTHON_SOURCE_EXTENSION:
                 continue
-            if self.compile:
-                bytecode_files.append(py_file + "c")
-            if self.optimize > 0:
-                bytecode_files.append(py_file + "o")
+
+            pyc_file = py_file + "c"
+            if self.compile and os.path.isfile(pyc_file):
+                bytecode_files.append(pyc_file)
+
+            pyo_file = py_file + "o"
+            if self.optimize > 0 and os.path.isfile(pyo_file):
+                bytecode_files.append(pyo_file)
 
         return bytecode_files
 
