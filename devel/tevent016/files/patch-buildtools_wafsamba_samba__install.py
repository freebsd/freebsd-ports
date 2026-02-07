--- buildtools/wafsamba/samba_install.py.orig	2019-03-21 10:12:32 UTC
+++ buildtools/wafsamba/samba_install.py
@@ -115,7 +115,7 @@ def install_library(self):
                 inst_name    = bld.make_libname(t.target)
         elif self.vnum:
             vnum_base    = self.vnum.split('.')[0]
-            install_name = bld.make_libname(target_name, version=self.vnum)
+            install_name = bld.make_libname(target_name, version=vnum_base)
             install_link = bld.make_libname(target_name, version=vnum_base)
             inst_name    = bld.make_libname(t.target)
             if not self.private_library or not t.env.SONAME_ST:
