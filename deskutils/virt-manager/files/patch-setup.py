--- setup.py.orig	2015-11-30 20:47:47 UTC
+++ setup.py
@@ -612,8 +612,8 @@ class VMMDistribution(distutils.dist.Dis
     ]
 
     def __init__(self, *args, **kwargs):
-        self.no_update_icon_cache = False
-        self.no_compile_schemas = False
+        self.no_update_icon_cache = True
+        self.no_compile_schemas = True
         distutils.dist.Distribution.__init__(self, *args, **kwargs)
 
 
@@ -641,13 +641,11 @@ distutils.core.setup(
             "virt-convert",
             "virt-xml",
         ]),
-        ("share/glib-2.0/schemas",
-         ["data/org.virt-manager.virt-manager.gschema.xml"]),
         ("share/GConf/gsettings",
          ["data/org.virt-manager.virt-manager.convert"]),
         ("share/virt-manager/ui", glob.glob("ui/*.ui")),
 
-        ("share/man/man1", [
+        ("man/man1", [
             "man/virt-manager.1",
             "man/virt-install.1",
             "man/virt-clone.1",
@@ -670,7 +668,6 @@ distutils.core.setup(
         'sdist': my_sdist,
         'install': my_install,
         'install_data': my_install_data,
-        'install_egg_info': my_egg_info,
 
         'configure': configure,
 
