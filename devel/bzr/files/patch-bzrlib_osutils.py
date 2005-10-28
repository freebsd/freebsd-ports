--- bzrlib/osutils.py.orig	Fri Oct 28 11:30:13 2005
+++ bzrlib/osutils.py	Fri Oct 28 11:30:38 2005
@@ -448,10 +448,10 @@
 except (NotImplementedError, AttributeError):
     # If python doesn't have os.urandom, or it doesn't work,
     # then try to first pull random data from /dev/urandom
-    if os.path.exists("/dev/urandom"):
+    try:
         rand_bytes = file('/dev/urandom', 'rb').read
     # Otherwise, use this hack as a last resort
-    else:
+    except:
         # not well seeded, but better than nothing
         def rand_bytes(n):
             import random
