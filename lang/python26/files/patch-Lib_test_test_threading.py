--- Lib/test/test_threading.py.bak	2009-03-12 07:59:17.000000000 +0000
+++ Lib/test/test_threading.py	2009-03-12 10:48:04.000000000 +0000
@@ -382,7 +382,7 @@
             return
         # Skip platforms with known problems forking from a worker thread.
         # See http://bugs.python.org/issue3863.
-        if sys.platform in ('freebsd4', 'freebsd5', 'freebsd6', 'os2emx'):
+        if sys.platform in ('freebsd4', 'freebsd5', 'freebsd6', 'freebsd7', 'freebsd8', 'freebsd9', 'os2emx'):
             print >>sys.stderr, ('Skipping test_3_join_in_forked_from_thread'
                                  ' due to known OS bugs on'), sys.platform
             return
