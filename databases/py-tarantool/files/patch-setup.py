--- setup.py.orig	2018-10-25 00:05:26 UTC
+++ setup.py
@@ -82,6 +82,6 @@ setup(
     cmdclass=cmdclass,
     command_options=command_options,
     install_requires=[
-        'msgpack-python>=0.4',
+        'msgpack>=0.4',
     ]
 )
