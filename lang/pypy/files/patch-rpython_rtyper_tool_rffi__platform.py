--- rpython/rtyper/tool/rffi_platform.py.orig	2015-05-31 07:19:51 UTC
+++ rpython/rtyper/tool/rffi_platform.py
@@ -854,7 +854,9 @@ def configure_boehm(platform=None):
         platform = None
     else:
         library_dir = ''
-        libraries = ['gc', 'dl']
+        libraries = ['gc']
+        if platform.name != "freebsd":
+            libraries += ['dl']
         includes=['gc/gc.h']
     eci = ExternalCompilationInfo(
         platform=platform,
