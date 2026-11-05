--- waftools/ext_aster.py.orig	2026-09-11 16:05:37 UTC
+++ waftools/ext_aster.py
@@ -361,7 +361,7 @@ class ldd_run(Task):
     def post_run(self):
         ret = Task.post_run(self)
         libname = self.generator.lib
-        re_libpath = re.compile("lib%s.*\s+=>\s+(\S+%s\S+)\s+" % (libname, libname), re.M)
+        re_libpath = re.compile(r"lib%s.*\s+=>\s+(\S+%s\S+)\s+" % (libname, libname), re.M)
         m = re_libpath.search(self.outputs[0].read())
         if m:
             self.generator.tmp.append(m.group(1))
