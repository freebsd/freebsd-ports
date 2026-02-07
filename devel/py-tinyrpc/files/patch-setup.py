--- setup.py.orig	2023-02-09 16:43:13 UTC
+++ setup.py
@@ -14,7 +14,7 @@ setup(
                 'library that, among other things, supports JSON-RPC and zmq.',
     long_description=read('README.rst'),
     long_description_content_type="text/x-rst",
-    packages=find_packages(exclude=['examples']),
+    packages=find_packages(exclude=['examples', 'tests']),
     keywords='json rpc json-rpc jsonrpc 0mq zmq zeromq',
     author='Marc Brinkmann',
     author_email='git@marcbrinkmann.de',
