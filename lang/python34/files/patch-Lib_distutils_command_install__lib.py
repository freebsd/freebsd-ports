From 9934ce31b8447667f71c211e559a8de71e8263db Mon Sep 17 00:00:00 2001
From: Brendan Molloy <brendan@bbqsrc.net>
Date: Mon, 4 Jan 2016 23:14:06 +1100
Subject: [PATCH] Check bytecode file actually exists and tests

Should solve issue 20397, where using the --record argument results
in files that failed to generate bytecode files are added to the
record file nonetheless.

--- Lib/distutils/command/install_lib.py.orig	2016-01-08 12:38:49 UTC
+++ Lib/distutils/command/install_lib.py
@@ -165,11 +165,19 @@ class install_lib(Command):
             if ext != PYTHON_SOURCE_EXTENSION:
                 continue
             if self.compile:
-                bytecode_files.append(importlib.util.cache_from_source(
-                    py_file, debug_override=True))
+                candidate = importlib.util.cache_from_source(
+                    py_file, debug_override=True)
+
+            if os.path.isfile(candidate):
+                bytecode_files.append(candidate)
+
             if self.optimize > 0:
-                bytecode_files.append(importlib.util.cache_from_source(
-                    py_file, debug_override=False))
+                candidate = importlib.util.cache_from_source(
+                    py_file, debug_override=False)
+
+            if os.path.isfile(candidate):
+                bytecode_files.append(candidate)
+
 
         return bytecode_files
 
