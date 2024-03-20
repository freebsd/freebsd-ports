--- setup.py.orig	2022-08-04 19:07:49 UTC
+++ setup.py
@@ -427,8 +427,8 @@ class VMMDistribution(setuptools.dist.Distribution):
     ]
 
     def __init__(self, *args, **kwargs):
-        self.no_update_icon_cache = False
-        self.no_compile_schemas = False
+        self.no_update_icon_cache = True
+        self.no_compile_schemas = True
         setuptools.dist.Distribution.__init__(self, *args, **kwargs)
 
 
@@ -500,8 +500,6 @@ setuptools.setup(
         "build/virt-xml"]),
 
     data_files=[
-        ("share/glib-2.0/schemas",
-         ["data/org.virt-manager.virt-manager.gschema.xml"]),
         ("share/virt-manager/ui", glob.glob("ui/*.ui")),
 
         ("share/man/man1", [
@@ -538,7 +536,6 @@ setuptools.setup(
         'build_i18n': my_build_i18n,
 
         'install': my_install,
-        'install_egg_info': my_egg_info,
 
         'configure': configure,
 
