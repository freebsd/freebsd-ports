--- setup.py.orig	2023-01-18 21:16:10 UTC
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
 
 
@@ -229,10 +228,10 @@ install_requires = [
     'pyls-spyder>=0.4.0',
     'pyqt5<5.16',
     'pyqtwebengine<5.16',
-    'python-lsp-server[all]>=1.7.1,<1.8.0',
+    'python-lsp-server[all]',
     'pyxdg>=0.26;platform_system=="Linux"',
     'pyzmq>=22.1.0',
-    'qdarkstyle>=3.0.2,<3.1.0',
+    'qdarkstyle>=3.0.2',
     'qstylizer>=0.2.2',
     'qtawesome>=1.2.1',
     'qtconsole>=5.4.0,<5.5.0',
