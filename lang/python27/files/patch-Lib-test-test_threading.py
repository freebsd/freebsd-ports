--- Lib/test/test_threading.py.orig	2010-11-29 08:22:00.000000000 +0800
+++ Lib/test/test_threading.py	2010-11-29 08:25:21.000000000 +0800
@@ -476,7 +476,7 @@
             return
         # Skip platforms with known problems forking from a worker thread.
         # See http://bugs.python.org/issue3863.
-        if sys.platform in ('freebsd4', 'freebsd5', 'freebsd6', 'netbsd5',
+        if sys.platform in ('freebsd6', 'freebsd7', 'freebsd8', 'freebsd9', 'freebsd10', 'netbsd5',
                            'os2emx'):
             print >>sys.stderr, ('Skipping test_3_join_in_forked_from_thread'
                                  ' due to known OS bugs on'), sys.platform
