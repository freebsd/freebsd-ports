--- setup.py.orig	2022-11-04 20:45:25 UTC
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
 
 
@@ -229,13 +228,13 @@ install_requires = [
     'pyls-spyder>=0.4.0',
     'pyqt5<5.16',
     'pyqtwebengine<5.16',
-    'python-lsp-server[all]>=1.6.0,<1.7.0',
-    'pyxdg>=0.26;platform_system=="Linux"',
+    'python-lsp-server[all]>0', # maybe dangerous to ignore >=1.6.0,<1.7.0
+    'pyxdg>=0.26',
     'pyzmq>=22.1.0',
-    'qdarkstyle>=3.0.2,<3.1.0',
+    'qdarkstyle>=3.0.2',
     'qstylizer>=0.2.2',
-    'qtawesome>=1.2.1',
-    'qtconsole>=5.4.0,<5.5.0',
+    'qtawesome', # maybe dangerous to ignore >=1.2.1
+    'qtconsole',
     'qtpy>=2.1.0',
     'rtree>=0.9.7',
     'setuptools>=49.6.0',
