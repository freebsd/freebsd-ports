https://github.com/mesonbuild/meson/issues/9592

--- mesonbuild/minstall.py.orig	2021-11-02 19:58:13 UTC
+++ mesonbuild/minstall.py
@@ -247,6 +247,11 @@ def apply_ldconfig(dm: DirMaker) -> None:
     '''
     Apply ldconfig to update the ld.so.cache.
     '''
+    from .mesonlib import is_linux
+    if not is_linux():
+        # Don't blindly assume GNU semantics on other systems
+        return
+
     if not shutil.which('ldconfig'):
         # If we don't have ldconfig, failure is ignored quietly.
         return
