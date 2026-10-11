Let tools/test.py run on FreeBSD (series 0023).
FreeBSD-specific, not submitted upstream yet.
--- tools/utils.py.orig	2026-09-29 08:00:52 UTC
+++ tools/utils.py
@@ -1001,7 +1001,7 @@ def FileDescriptorLimitIncreaser():
     if osname == 'macos':
         return IncreasedNumberOfFileDescriptors(nofiles=10000)
 
-    assert osname in ('linux', 'win32')
+    assert osname in ('linux', 'freebsd', 'win32')
     # We don't have support for MacOS yet.
     return NooptContextManager()
 
