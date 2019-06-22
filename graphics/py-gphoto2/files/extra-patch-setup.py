--- setup.py.orig	2018-01-02 11:44:51 UTC
+++ setup.py
@@ -83,7 +83,7 @@ mod_src_dir = os.path.join(
     'src', mod_src_dir + '-gp' + '.'.join(map(str, best_match)))
 
 extra_compile_args = [
-    '-O3', '-Wno-unused-variable', '-Wno-unused-but-set-variable',
+    '-O3', '-Wno-unused-variable',
     '-Wno-unused-label', '-Wno-strict-prototypes',
     '-DGPHOTO2_VERSION=' + '0x{:02x}{:02x}{:02x}'.format(*gphoto2_version)]
 if 'PYTHON_GPHOTO2_STRICT' in os.environ:
