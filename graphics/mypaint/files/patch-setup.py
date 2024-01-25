--- setup.py.orig	2020-05-29 15:18:55 UTC
+++ setup.py
@@ -632,7 +632,7 @@ class InstallScripts (install_scripts):
         self.announce("installing %s as %s" % (src, targ_basename), level=2)
         if self.dry_run:
             return []
-        with open(src, "rU") as in_fp:
+        with open(src, "r") as in_fp:
             with open(targ, "w") as out_fp:
                 line = in_fp.readline().rstrip()
                 if line.startswith("#!"):
@@ -867,7 +867,6 @@ def get_ext_modules():
         '-Wall',
         '-Wno-sign-compare',
         '-Wno-write-strings',
-        '-D_POSIX_C_SOURCE=200809L',
         "-DNO_TESTS",  # FIXME: we're building against shared libmypaint now
         '-g',  # always include symbols, for profiling
     ]
