--- setup.py.orig	2018-09-17 11:22:42 UTC
+++ setup.py
@@ -195,7 +195,7 @@ setup(name='pygit2',
       long_description=long_description,
       packages=['pygit2'],
       package_data={'pygit2': ['decl.h']},
-      setup_requires=['cffi', 'pycparser<2.18'],
+      setup_requires=['cffi', 'pycparser<2.19'],
       install_requires=['cffi', 'six'],
       zip_safe=False,
       cmdclass=cmdclass,
