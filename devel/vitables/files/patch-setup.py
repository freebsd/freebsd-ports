--- setup.py.orig	2019-12-27 04:39:05 UTC
+++ setup.py
@@ -31,8 +31,8 @@ def read(fname):
 
 install_requires = ['qtpy (>=1.2.1)', 'numpy (>=1.4.1)', 'numexpr (>=2.0)',
                     'tables (>=3.0)']
-if 'CONDA_PREFIX' not in os.environ:
-    install_requires.append('PyQt5 (>=5.5.1)')
+#if 'CONDA_PREFIX' not in os.environ:
+#    install_requires.append('PyQt5 (>=5.5.1)')
 
 setup(name='ViTables',
       version=read('VERSION'),
