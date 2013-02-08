--- ./buildtools/wafsamba/samba_install.py.orig	2012-04-11 12:36:11.000000000 +0000
+++ ./buildtools/wafsamba/samba_install.py	2013-01-29 20:54:59.749863922 +0000
@@ -109,7 +109,7 @@
             inst_name    = bld.make_libname(t.target)
     elif self.vnum:
         vnum_base    = self.vnum.split('.')[0]
-        install_name = bld.make_libname(target_name, version=self.vnum)
+        install_name = bld.make_libname(target_name, version=vnum_base)
         install_link = bld.make_libname(target_name, version=vnum_base)
         inst_name    = bld.make_libname(t.target)
         if not self.private_library:
