--- setup.py.orig	2023-11-08 03:05:24 UTC
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
@@ -199,7 +199,6 @@ setup_args = dict(
         'Topic :: Scientific/Engineering',
         'Topic :: Software Development :: Widget Sets',
     ],
-    cmdclass=CMDCLASS,
 )
 
 
@@ -213,7 +212,7 @@ install_requires = [
     'intervaltree>=3.0.2',
     'ipython>=8.12.2,<8.13.0; python_version=="3.8"',
     'ipython>=8.13.0,<9.0.0,!=8.17.1; python_version>"3.8"',
-    'jedi>=0.17.2,<0.20.0',
+    'jedi>=0.17.2',
     'jellyfish>=0.7',
     'jsonschema>=3.2.0',
     'keyring>=17.0.0',
@@ -232,18 +231,18 @@ install_requires = [
     'pyls-spyder>=0.4.0',
     'pyqt5>=5.10,<5.16',
     'pyqtwebengine>=5.10,<5.16',
-    'python-lsp-server[all]>=1.9.0,<1.10.0',
+    'python-lsp-server[all]>=1.9.0',
     'pyxdg>=0.26;platform_system=="Linux"',
     'pyzmq>=22.1.0',
-    'qdarkstyle>=3.2.0,<3.3.0',
+    'qdarkstyle>=3.2.0',
     'qstylizer>=0.2.2',
     'qtawesome>=1.2.1',
-    'qtconsole>=5.5.0,<5.6.0',
+    'qtconsole>=5.5.0',
     'qtpy>=2.1.0',
     'rtree>=0.9.7',
     'setuptools>=49.6.0',
     'sphinx>=0.6.6',
-    'spyder-kernels>=2.5.0,<2.6.0',
+    'spyder-kernels>=2.5.0',
     'textdistance>=4.2.0',
     'three-merge>=0.1.1',
     'watchdog>=0.10.3'
@@ -256,7 +255,7 @@ if 'dev' in __version__:
                         if req.split(">")[0] not in reqs_to_loosen]
     install_requires.append('python-lsp-server[all]>=1.9.0,<1.11.0')
     install_requires.append('qtconsole>=5.5.0,<5.7.0')
-    install_requires.append('spyder-kernels>=2.5.0,<2.7.0')
+    install_requires.append('spyder-kernels>=2.5.0')
 
 extras_require = {
     'test:platform_system == "Windows"': ['pywin32'],
