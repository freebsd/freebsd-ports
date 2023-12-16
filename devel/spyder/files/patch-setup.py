--- setup.py.orig	2023-08-29 21:53:14 UTC
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
 
 
@@ -210,7 +209,7 @@ install_requires = [
     'diff-match-patch>=20181111',
     'intervaltree>=3.0.2',
     'ipython>=7.31.1,<9.0.0,!=8.8.0,!=8.9.0,!=8.10.0,!=8.11.0,!=8.12.0,!=8.12.1',
-    'jedi>=0.17.2,<0.19.0',
+    'jedi>=0.17.2',
     'jellyfish>=0.7',
     'jsonschema>=3.2.0',
     'keyring>=17.0.0',
@@ -229,18 +228,18 @@ install_requires = [
     'pyls-spyder>=0.4.0',
     'pyqt5<5.16',
     'pyqtwebengine<5.16',
-    'python-lsp-server[all]>=1.7.4,<1.8.0',
+    'python-lsp-server[all]>=1.7.4',
     'pyxdg>=0.26;platform_system=="Linux"',
     'pyzmq>=22.1.0',
-    'qdarkstyle>=3.0.2,<3.2.0',
+    'qdarkstyle>=3.0.2',
     'qstylizer>=0.2.2',
     'qtawesome>=1.2.1',
-    'qtconsole>=5.4.2,<5.5.0',
+    'qtconsole>=5.4.2',
     'qtpy>=2.1.0',
     'rtree>=0.9.7',
     'setuptools>=49.6.0',
     'sphinx>=0.6.6',
-    'spyder-kernels>=2.4.4,<2.5.0',
+    'spyder-kernels>=2.4.4',
     'textdistance>=4.2.0',
     'three-merge>=0.1.1',
     'watchdog>=0.10.3'
@@ -253,7 +252,7 @@ if 'dev' in __version__:
                         if req.split(">")[0] not in reqs_to_loosen]
     install_requires.append('python-lsp-server[all]>=1.7.4,<1.9.0')
     install_requires.append('qtconsole>=5.4.2,<5.6.0')
-    install_requires.append('spyder-kernels>=2.4.4,<2.6.0')
+    install_requires.append('spyder-kernels>=2.4.4')
 
 extras_require = {
     'test:platform_system == "Windows"': ['pywin32'],
