--- src/build_mozc.py.orig	2017-01-02 01:13:46.394876000 +0900
+++ src/build_mozc.py	2017-01-02 01:20:39.314369000 +0900
@@ -637,9 +637,6 @@
   else:
     gyp_options.extend(['-D', 'use_wix=NO'])
 
-  if target_platform == 'Linux':
-    gyp_options.extend(['-D', 'enable_gtk_renderer=1'])
-
   # Android
   if target_platform == 'Android':
     android_home = GetAndroidHome(options)
@@ -864,7 +861,7 @@
   ninja = GetNinjaPath()
 
   ninja_targets = [GetNinjaTargetName(target) for target in targets]
-  RunOrDie([ninja, '-C', build_arg] + ninja_targets)
+  RunOrDie([ninja, '-v', '-C', build_arg] + ninja_targets)
 
 
 def BuildOnWindows(targets):
