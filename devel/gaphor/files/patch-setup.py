--- setup.py.orig	Sat Dec 24 01:34:18 2005
+++ setup.py	Sat Dec 24 01:34:48 2005
@@ -390,8 +390,7 @@
       scripts=['bin/gaphor'],
 
       distclass=Distribution,
-      cmdclass={'config': config_Gaphor,
-                'build_py': build_py_Gaphor,
+      cmdclass={'build_py': build_py_Gaphor,
                 #'install_schemas': install_schemas,
                 'build': build_Gaphor,
 #                'build_ext': BuildExt,
