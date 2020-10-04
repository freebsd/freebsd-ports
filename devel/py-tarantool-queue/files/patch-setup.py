--- setup.py.orig	2014-08-21 15:11:15 UTC
+++ setup.py
@@ -42,13 +42,13 @@ setup(name='tarantool-queue',
       packages=['tarantool_queue'],
       platforms = ["all"],
       install_requires=[
-            'msgpack-python',
-            'tarantool<0.4'
+            'msgpack',
+            'tarantool'
           ],
       url='http://github.com/tarantool/tarantool-queue-python',
       test_suite='tests.test_queue',
       tests_require=[
-            'msgpack-python',
+            'msgpack',
             'tarantool'
           ],
       classifiers=[
