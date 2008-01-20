--- setup.py.orig	2008-01-19 10:06:45.253272917 +0100
+++ setup.py	2008-01-19 10:07:03.283255219 +0100
@@ -36,8 +36,8 @@
       author_email = "mitch@garnaat.com",
       url = "http://code.google.com/p/boto/",
       packages = [ 'boto', 'boto.sqs', 'boto.s3', 'boto.ec2', 'boto.sdb',
-                   'boto.mturk', 'boto.contrib', 'tests'],
-      scripts=['test.py'],
+                   'boto.mturk', 'boto.contrib' ],
+      scripts=[],
       license = 'MIT',
       platforms = 'Posix; MacOS X; Windows',
       classifiers = [ 'Development Status :: 3 - Alpha',
