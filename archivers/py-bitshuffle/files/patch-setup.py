--- setup.py.orig	2022-11-26 00:17:16 UTC
+++ setup.py
@@ -371,7 +371,7 @@ class build_ext(build_ext_):
         else:
             openmpflag = "-fopenmp"
             archi = platform.machine()
-            if archi in ("i386", "x86_64"):
+            if archi in ("amd64", "i386", "x86_64"):
                 compileflags = COMPILE_FLAGS + ["-march=%s" % self.march]
             else:
                 compileflags = COMPILE_FLAGS + ["-mcpu=%s" % self.march]
