--- setup.py.orig	2009-02-15 22:49:32 UTC
+++ setup.py
@@ -10,20 +10,8 @@ if not hasattr(sys, 'version_info') or s
     raise SystemExit, "Qct requires python 2.4 or later."
 
 extra = {}
-try:
-    # to generate qct MSI installer, you run python setup.py bdist_msi
-    from setuptools import setup
-    if os.name in ['nt']:
-        # the msi will automatically install the qct.py plugin into hgext
-        extra['data_files'] = [('lib/site-packages/hgext', ['hgext/qct.py']),
-                ('mercurial/hgrc.d', ['qct.rc']),
-                ('share/qct', ['doc/qct.1.html', 'README', 'README.mercurial'])]
-        extra['scripts'] = ['win32/qct_postinstall.py']
-    else:
-        extra['scripts'] = ['qct']
-except ImportError:
-    from distutils.core import setup
-    extra['scripts'] = ['qct']
+from distutils.core import setup
+extra['scripts'] = ['qct']
 
 from distutils.command.build import build
 from distutils.spawn import find_executable, spawn
