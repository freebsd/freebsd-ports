--- setup.py.orig	2019-01-30 21:54:31 UTC
+++ setup.py
@@ -154,7 +154,7 @@ setup(name='pygit2',
       packages=['pygit2'],
       package_data={'pygit2': ['decl.h']},
       setup_requires=['cffi'],
-      install_requires=['cffi', 'six', 'pycparser<2.18'],
+      install_requires=['cffi', 'six', 'pycparser<2.19'],
       zip_safe=False,
       cmdclass=cmdclass,
       **extra_args)
