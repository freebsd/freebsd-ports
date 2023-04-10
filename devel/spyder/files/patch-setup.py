--- setup.py.orig	2023-04-05 02:35:28 UTC
+++ setup.py
@@ -91,7 +91,7 @@ def get_data_files():
     """
     Return data_files in a platform dependent manner.
     """
-    if sys.platform.startswith('linux'):
+    if sys.platform.startswith('linux') or sys.platform.startswith('freebsd'):
         data_files = [('share/applications', ['scripts/spyder.desktop']),
                       ('share/icons', ['img_src/spyder.png']),
                       ('share/metainfo',
@@ -197,7 +197,6 @@ setup_args = dict(
         'Topic :: Scientific/Engineering',
         'Topic :: Software Development :: Widget Sets',
     ],
-    cmdclass=CMDCLASS,
 )
 
 
@@ -232,10 +231,10 @@ install_requires = [
     'python-lsp-server[all]>=1.7.2,<1.8.0',
     'pyxdg>=0.26;platform_system=="Linux"',
     'pyzmq>=22.1.0',
-    'qdarkstyle>=3.0.2,<3.2.0',
+    'qdarkstyle>0',
     'qstylizer>=0.2.2',
     'qtawesome>=1.2.1',
-    'qtconsole>=5.4.2,<5.5.0',
+    'qtconsole>0',
     'qtpy>=2.1.0',
     'rtree>=0.9.7',
     'setuptools>=49.6.0',
