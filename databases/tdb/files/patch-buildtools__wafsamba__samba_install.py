--- buildtools/wafsamba/samba_install.py.orig	2010-12-21 02:00:02.000000000 +0100
+++ buildtools/wafsamba/samba_install.py	2011-06-21 11:46:28.000000000 +0200
@@ -109,7 +109,7 @@
             inst_name    = bld.make_libname(t.target)
     elif self.vnum:
         vnum_base    = self.vnum.split('.')[0]
-        install_name = bld.make_libname(target_name, version=self.vnum)
+        install_name = bld.make_libname(target_name, version=vnum_base)
         install_link = bld.make_libname(target_name, version=vnum_base)
         inst_name    = bld.make_libname(t.target)
         if not self.private_library:
