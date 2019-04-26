--- setup.py.orig	2019-04-07 13:12:23 UTC
+++ setup.py
@@ -486,6 +486,8 @@ test_deps = [
     'boto3',
     'moto',
     'mock>=2.0.0',
+    'parameterized',
+    'buildbot-worker',
 ]
 if sys.platform != 'win32':
     test_deps += [
