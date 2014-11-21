--- setup.py.orig	2014-09-06 22:26:12 UTC
+++ setup.py
@@ -209,14 +209,6 @@ class my_build(build):
         build.run(self)
 
 
-class my_egg_info(install_egg_info):
-    """
-    Disable egg_info installation, seems pointless for a non-library
-    """
-    def run(self):
-        pass
-
-
 class my_install(install):
     """
     Error if we weren't 'configure'd with the correct install prefix
@@ -605,7 +597,7 @@ setup(
          ["data/org.virt-manager.virt-manager.gschema.xml"]),
         ("share/virt-manager/ui", glob.glob("ui/*.ui")),
 
-        ("share/man/man1", [
+        ("man/man1", [
             "man/virt-manager.1",
             "man/virt-install.1",
             "man/virt-clone.1",
@@ -627,7 +619,6 @@ setup(
 
         'sdist': my_sdist,
         'install': my_install,
-        'install_egg_info': my_egg_info,
 
         'configure': configure,
 
