--- test/test_packaging.py.orig	2015-10-11 12:44:56 UTC
+++ test/test_packaging.py
@@ -37,7 +37,7 @@ import txaio
 def test_sdist():
     if not hasattr(subprocess, 'check_output'):
         pytest.skip()
-    subprocess.check_output([sys.executable, 'setup.py', 'sdist'], cwd='..')
+    subprocess.check_output([sys.executable, 'setup.py', 'sdist'])
     tmp = tempfile.mkdtemp()
     try:
         subprocess.check_output([
@@ -47,7 +47,7 @@ def test_sdist():
             'install',
             '--target', tmp,
             '--no-deps',
-            '../dist/txaio-{}.tar.gz'.format(txaio.__version__),
+            'dist/txaio-{}.tar.gz'.format(txaio.__version__),
         ])
     finally:
         rmtree(tmp)
