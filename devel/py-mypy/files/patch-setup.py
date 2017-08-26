--- setup.py.orig	2017-08-04 19:04:43 UTC
+++ setup.py
@@ -100,7 +100,7 @@ package_dir = {'mypy': 'mypy'}
 # "pip3 install git+git://github.com/python/mypy.git"
 # (as suggested by README.md).
 install_requires = []
-install_requires.append('typed-ast >= 1.0.4, < 1.1.0')
+install_requires.append('typed-ast >= 1.0.4, < 1.2.0')
 if sys.version_info < (3, 5):
     install_requires.append('typing >= 3.5.3')
 
