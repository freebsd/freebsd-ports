# Prevent installation of test.py in PREFIX/bin, which would easily
# conflict with other software.
--- setup.py.orig	Thu Aug 23 19:01:03 2007
+++ setup.py	Thu Aug 23 19:01:22 2007
@@ -37,7 +37,7 @@
       url = "http://code.google.com/p/boto/",
       packages = [ 'boto', 'boto.sqs', 'boto.s3', 'boto.ec2',
                    'boto.mturk', 'tests'],
-      scripts=['test.py'],
+      scripts=[],
       license = 'MIT',
       platforms = 'Posix; MacOS X; Windows',
       classifiers = [ 'Development Status :: 3 - Alpha',
