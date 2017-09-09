--- setup_helpers.py.orig	2015-06-21 09:00:45 UTC
+++ setup_helpers.py
@@ -28,7 +28,7 @@ def build_scripts_gnatpython(root_dir=''
                 os.system('gcc -o %sscripts/rlimit %ssrc/rlimit/rlimit-NT.c' %
                           (root_dir, root_dir))
             else:
-                os.system('gcc -o %sscripts/rlimit %ssrc/rlimit/rlimit.c' %
+                os.system('cc -o %sscripts/rlimit %ssrc/rlimit/rlimit.c' %
                           (root_dir, root_dir))
 
             # Update the scripts list
