--- setup_helpers.py.orig	2014-02-14 10:41:26.000000000 +0000
+++ setup_helpers.py
@@ -28,7 +28,7 @@ def build_scripts_gnatpython(root_dir=''
                 os.system('gcc -o %sscripts/rlimit %ssrc/rlimit/rlimit-NT.c' %
                           (root_dir, root_dir))
             else:
-                os.system('gcc -o %sscripts/rlimit %ssrc/rlimit/rlimit.c' %
+                os.system('cc -o %sscripts/rlimit %ssrc/rlimit/rlimit.c' %
                           (root_dir, root_dir))
 
             # Update the scripts list
