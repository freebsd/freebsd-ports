--- Lib/test/test_posix.py.orig	2025-11-01 21:42:35 UTC
+++ Lib/test/test_posix.py
@@ -412,11 +412,12 @@ class PosixTester(unittest.TestCase):
             # so skip Solaris-based since they are likely to have ZFS.
             # issue33655: Also ignore EINVAL on *BSD since ZFS is also
             # often used there.
-            if inst.errno == errno.EINVAL and sys.platform.startswith(
+            if (inst.errno == errno.EINVAL or inst.errno == errno.ENODEV) and sys.platform.startswith(
                 ('sunos', 'freebsd', 'openbsd', 'gnukfreebsd')):
                 raise unittest.SkipTest("test may fail on ZFS filesystems")
-            elif inst.errno == errno.EOPNOTSUPP and sys.platform.startswith("netbsd"):
-                raise unittest.SkipTest("test may fail on FFS filesystems")
+	    # FreeBSD may return EOPNOTSUPP in some versions
+            elif inst.errno == errno.EOPNOTSUPP and sys.platform.startswith(('netbsd', 'freebsd')):
+                raise unittest.SkipTest("test may fail on ZFS and FFS filesystems")
             else:
                 raise
         finally:
