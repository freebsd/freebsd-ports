--- astropy/io/fits/setup_package.py.orig	2016-07-02 18:54:36 UTC
+++ astropy/io/fits/setup_package.py
@@ -39,7 +39,7 @@ def _get_compression_extension():
                     '-Wno-uninitialized', '-Wno-format',
                     '-Wno-strict-prototypes', '-Wno-unused', '-Wno-comments',
                     '-Wno-switch', '-Wno-strict-aliasing', '-Wno-return-type',
-                    '-Wno-address', '-Wno-unused-result'
+                    '-Wno-address'
                 ])
 
         cfitsio_path = os.path.join('cextern', 'cfitsio')
