--- src/gevent/subprocess.py.orig	2017-05-18 13:28:38 UTC
+++ src/gevent/subprocess.py
@@ -185,6 +185,32 @@ for _x in ('run', 'CompletedProcess', 'T
         __all__.append(_x)
 
 
+# This routine below is a pure python
+# translation of python's _posixsubprocess.c's
+# _is_fdescfs_mounted_on_dev_fd method
+# https://hg.python.org/cpython/file/3f3cbfd52f94/Modules/_posixsubprocess.c
+def bsd_is_devfs_mounted():
+    """
+    Checks if fdescfs is truly mounted on /dev/fd
+    Returns True if yes else False
+    """
+    dev_stdev = os.stat('/dev').st_dev
+    dev_fd_stdev = os.stat('/dev/fd').st_dev
+    if (dev_stdev == 0 or dev_fd_stdev == 0 or dev_stdev == dev_fd_stdev):
+        # This means that the either the /dev/fd is only there for purely
+        # devfs reasons or something else is funky thus return False
+        return False
+    return True
+
+# devfs path string template
+devfs_path_template = None
+if sys.platform.startswith('freebsd'):
+    if bsd_is_devfs_mounted():
+        devfs_path_template = '/dev/fd'
+elif sys.platform.startswith('linux'):
+    devfs_path_template = '/proc/{0}/fd'
+
+
 mswindows = sys.platform == 'win32'
 if mswindows:
     import msvcrt # pylint: disable=import-error
@@ -702,10 +728,12 @@ class Popen(object):
         self._stdout_buffer = None
         stderr_value = self._stderr_buffer
         self._stderr_buffer = None
-        # XXX: Under python 3 in universal newlines mode we should be
-        # returning str, not bytes
-        return (None if stdout is None else stdout_value or b'',
-                None if stderr is None else stderr_value or b'')
+        if PY3 and (self.encoding or self.errors or self.universal_newlines):
+            empty_value = ''
+        else:
+            empty_value = b''
+        return (None if stdout is None else stdout_value or empty_value,
+                None if stderr is None else stderr_value or empty_value)
 
     def poll(self):
         """Check if child process has terminated. Set and return :attr:`returncode` attribute."""
@@ -1078,6 +1106,11 @@ class Popen(object):
             self._set_cloexec_flag(w)
             return r, w
 
+        def _get_max_fd(self):
+            if devfs_path_template is None:
+                return MAXFD
+            return int(max(os.listdir(devfs_path_template.format(self.pid))))
+
         def _close_fds(self, keep):
             # `keep` is a set of fds, so we
             # use os.closerange from 3 to min(keep)
@@ -1094,7 +1127,7 @@ class Popen(object):
                 min_keep = min(keep)
                 max_keep = max(keep)
                 os.closerange(3, min_keep)
-                os.closerange(max_keep + 1, MAXFD)
+                os.closerange(max_keep + 1, self._get_max_fd())
                 for i in xrange(min_keep, max_keep):
                     if i in keep:
                         set_inheritable(i, True)
@@ -1105,7 +1138,7 @@ class Popen(object):
                     except:
                         pass
             else:
-                for i in xrange(3, MAXFD):
+                for i in xrange(3, self._get_max_fd()):
                     if i in keep:
                         set_inheritable(i, True)
                         continue
@@ -1224,7 +1257,7 @@ class Popen(object):
                                 # are closed, and inheritable handles
                                 # are only inherited if the close_fds
                                 # parameter is False."
-                                for i in xrange(3, MAXFD):
+                                for i in xrange(3, self._get_max_fd()):
                                     try:
                                         if i == errpipe_write or os.get_inheritable(i):
                                             continue
