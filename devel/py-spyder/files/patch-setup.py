--- setup.py.orig	2022-08-29 23:48:19 UTC
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
 
 
@@ -229,12 +228,12 @@ install_requires = [
     'pyqt5<5.16',
     'pyqtwebengine<5.16',
     'python-lsp-server[all]>=1.5.0,<1.6.0',
-    'pyxdg>=0.26;platform_system=="Linux"',
+    'pyxdg>=0.26',
     'pyzmq>=22.1.0',
-    'qdarkstyle>=3.0.2,<3.1.0',
+    'qdarkstyle>=3.0.2',
     'qstylizer>=0.1.10',
     'qtawesome>=1.0.2',
-    'qtconsole>=5.3.2,<5.4.0',
+    'qtconsole',
     'qtpy>=2.1.0',
     'rtree>=0.9.7',
     'setuptools>=49.6.0',
