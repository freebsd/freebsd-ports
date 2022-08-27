--- setup.py.orig	2022-01-25 21:31:58 UTC
+++ setup.py
@@ -22,9 +22,6 @@ with open('requirements.txt') as f:  # pylint: disable
     install_reqs += f.read().splitlines()
 
 setup_requires = [
-    # Pin pytest-runner to 5.2.0, since 5.3.0 uses `find_namespaces` directive, not supported in
-    # Python 2.7
-    'pytest-runner == 5.2.0',
 ]
 
 # WARNING: This imposes limitations on test/requirements.txt such that the
