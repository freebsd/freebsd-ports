FreeBSD's base ld(1) does not currently support plugins and is not compatible
with clang's link-time optimisation.
--- rpython/translator/platform/posix.py.orig	2017-03-19 19:55:48 UTC
+++ rpython/translator/platform/posix.py
@@ -132,7 +132,7 @@ class BasePosix(Platform):
 
         # xxx check which compilers accept this option or not
         if not config or config.translation.gcrootfinder != 'asmgcc':
-            cflags = ('-flto',) + cflags
+            pass
 
         m = GnuMakefile(path)
         m.exe_name = path.join(exe_name.basename)
