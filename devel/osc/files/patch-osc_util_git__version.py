--- osc/util/git_version.py.orig	2022-06-24 13:23:26 UTC
+++ osc/util/git_version.py
@@ -3,6 +3,7 @@ import subprocess
 
 
 def get_git_archive_version():
+    return None
     """
     Return version that is set by git during `git archive`.
     The returned format is equal to what `git describe --tags` returns.
@@ -17,6 +18,7 @@ def get_git_archive_version():
 
 
 def get_git_version():
+    return None
     """
     Determine version from git repo by calling `git describe --tags`.
     """
