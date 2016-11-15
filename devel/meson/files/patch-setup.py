--- setup.py.orig	2016-11-13 20:01:34 UTC
+++ setup.py
@@ -73,7 +73,7 @@ setup(name='meson',
                'mesonintrospect.py',
                'wraptool.py'],
       cmdclass={'install_scripts': install_scripts},
-      data_files=[('share/man/man1', ['man/meson.1',
+      data_files=[('man/man1'      , ['man/meson.1',
                                       'man/mesonconf.1',
                                       'man/mesonintrospect.1',
                                       'man/wraptool.1'])],
