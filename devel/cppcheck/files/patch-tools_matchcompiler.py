commit 9d64e9a5577877dd9608823fb42fbef8d13af085
Author: Dmitry Marakasov <amdmi3@amdmi3.ru>
Date:   Fri May 19 21:36:54 2017 +0300

    Fix matchcompiler failure in case of parallel build
    
    During parallel build, multiple processes will try to create build_dir
    in parallel, so the build will fail. Fix that by calling makedirs
    unconditionally and ignoring errors from it. If there's actual
    problem with directory creation, it'll be caught later by isdir()
    check.

diff --git tools/matchcompiler.py tools/matchcompiler.py
index 71f176d59..2ba36b29f 100755
--- tools/matchcompiler.py
+++ tools/matchcompiler.py
@@ -22,6 +22,7 @@ import sys
 import re
 import glob
 import argparse
+import errno
 
 
 class MatchCompiler:
@@ -667,8 +668,16 @@ def main():
         sys.exit(-1)
 
     # Create build directory if needed
-    if not os.path.exists(build_dir):
+    try:
         os.makedirs(build_dir)
+    except OSError as e:
+        # due to race condition in case of parallel build,
+        # makedirs may fail. Ignore that; if there's actual
+        # problem with directory creation, it'll be caught
+        # by the following isdir check
+        if e.errno != errno.EEXIST:
+            raise
+
     if not os.path.isdir(build_dir):
         raise Exception(build_dir + ' is not a directory')
 
