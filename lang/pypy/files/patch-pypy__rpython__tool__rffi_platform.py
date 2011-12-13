--- pypy/rpython/tool/rffi_platform.py~	2011-11-19 09:44:54.000000000 +0200
+++ pypy/rpython/tool/rffi_platform.py	2011-11-23 20:17:30.000000000 +0200
@@ -789,7 +789,9 @@
         includes=['gc.h']
     else:
         library_dir = ''
-        libraries = ['gc', 'dl']
+        libraries = ['gc']
+        if platform.name != "freebsd":
+            libraries += ['dl']
         includes=['gc/gc.h']
     eci = ExternalCompilationInfo(
         platform=platform,
