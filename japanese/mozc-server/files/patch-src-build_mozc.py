--- src/build_mozc.py.orig	2017-01-01 14:29:01.398407000 +0900
+++ src/build_mozc.py	2017-01-01 14:30:17.894029000 +0900
@@ -864,7 +864,7 @@
   ninja = GetNinjaPath()
 
   ninja_targets = [GetNinjaTargetName(target) for target in targets]
-  RunOrDie([ninja, '-C', build_arg] + ninja_targets)
+  RunOrDie([ninja, '-v', '-C', build_arg] + ninja_targets)
 
 
 def BuildOnWindows(targets):
