Index: engine/SCons/compat/_scons_subprocess.py
===================================================================
--- engine/SCons/compat/_scons_subprocess.py.orig	2015-11-09 11:25:09 UTC
+++ engine/SCons/compat/_scons_subprocess.py
@@ -569,13 +569,19 @@ def list2cmdline(seq):
 
     return ''.join(result)
 
+import thread
+lock = thread.allocate_lock()
+
 class Popen(object):
     def __init__(self, args, bufsize=0, executable=None,
                  stdin=None, stdout=None, stderr=None,
                  preexec_fn=None, close_fds=False, shell=False,
                  cwd=None, env=None, universal_newlines=False,
                  startupinfo=None, creationflags=0):
-        """Create new Popen instance."""
+        """Create new Popen instance.
+        Popen is not thread-safe and is therefore protected with a lock.
+        """
+        lock.acquire()
         _cleanup()
 
         self._child_created = False
@@ -643,6 +649,7 @@ class Popen(object):
                 self.stderr = os.fdopen(errread, 'rU', bufsize)
             else:
                 self.stderr = os.fdopen(errread, 'rb', bufsize)
+        lock.release()
 
 
     def _translate_newlines(self, data):
