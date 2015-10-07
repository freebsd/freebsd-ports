--- setup.py.orig	2015-08-10 18:15:04 UTC
+++ setup.py
@@ -208,12 +208,6 @@ class my_build(build):
         build.run(self)
 
 
-class my_egg_info(install_egg_info):
-    """
-    Disable egg_info installation, seems pointless for a non-library
-    """
-    def run(self):
-        pass
 
 
 class my_install(install):
@@ -589,13 +583,11 @@ setup(
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
@@ -617,7 +609,6 @@ setup(
 
         'sdist': my_sdist,
         'install': my_install,
-        'install_egg_info': my_egg_info,
 
         'configure': configure,
 
