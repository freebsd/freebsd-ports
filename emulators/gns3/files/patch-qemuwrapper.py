--- qemuwrapper/qemuwrapper.py.orig
+++ qemuwrapper/qemuwrapper.py
@@ -45,6 +45,7 @@ import SocketServer
 import time
 import random
 import pemubin
+import ctypes
 
 
 __author__ = 'Thomas Pani and Jeremy Grossmann'
@@ -118,6 +119,33 @@ class xEMUInstance(object):
     def unbase_disk(self):
         pass
 
+    def preexec(self):
+        # FreeBSD preexec_fn hack to unblock signals in child processes
+        # to work around the bug in this PR:
+        #        http://www.freebsd.org/cgi/query-pr.cgi?pr=ports/153167
+        # inspired by:
+        #        http://stackoverflow.com/questions/3791398/how-to-stop-python-from-propagating-signals-to-subprocesses
+
+        # Get the size of the array used to
+        # represent the signal mask
+        SIGSET_NWORDS = 1024 / (8 * ctypes.sizeof(ctypes.c_uint))
+
+        # Define the sigset_t structure
+        class SIGSET(ctypes.Structure):
+            _fields_ = [
+                ('val', ctypes.c_uint * SIGSET_NWORDS)
+            ]
+
+        # Create a new sigset_t to mask out SIGINT
+        sigs = (ctypes.c_uint * SIGSET_NWORDS)()
+        mask = SIGSET(sigs)
+
+        SIG_SETMASK = 3
+        libc = ctypes.CDLL('libc.so')
+
+        # Unblock all signals
+        libc.sigprocmask(SIG_SETMASK, ctypes.pointer(mask), 0)
+
     def start(self):
         command = self._build_command()
 
@@ -125,6 +152,7 @@ class xEMUInstance(object):
         try:
             self.process = subprocess.Popen(command,
                                             stdin=subprocess.PIPE,
+                                            preexec_fn=self.preexec,
                                             cwd=self.workdir)
         except OSError, e:
             print >> sys.stderr, "Unable to start instance", self.name, "of", self.__class__
