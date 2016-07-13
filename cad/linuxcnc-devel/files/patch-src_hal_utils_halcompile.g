--- src/hal/utils/halcompile.g.orig	2016-06-25 02:19:12 UTC
+++ src/hal/utils/halcompile.g
@@ -709,7 +709,7 @@ def build_usr(tempdir, filename, mode, o
         options.get("extra_link_args", ""))
     print >>f, "include %s" % find_modinc()
     f.close()
-    result = os.system("cd %s && make -S %s" % (tempdir, binname))
+    result = os.system("cd %s && gmake -S %s" % (tempdir, binname))
     if result != 0:
         raise SystemExit, os.WEXITSTATUS(result) or 1
     output = os.path.join(tempdir, binname)
@@ -731,7 +731,7 @@ def build_rt(tempdir, filename, mode, or
         target = "modules install"
     else:
         target = "modules"
-    result = os.system("cd %s && make -S %s" % (tempdir, target))
+    result = os.system("cd %s && gmake -S %s" % (tempdir, target))
     if result != 0:
         raise SystemExit, os.WEXITSTATUS(result) or 1
     if mode == COMPILE:
