--- dtrace_cython/consumer.pyx.orig	2015-01-24 23:40:08 UTC
+++ dtrace_cython/consumer.pyx
@@ -2,7 +2,7 @@
 import time
 import threading
 from threading import Thread
-from dtrace_consumer.dtrace_h cimport *
+from dtrace_cython.dtrace_h cimport *
 
 # ----------------------------------------------------------------------------
 # The DTrace callbacks
@@ -333,6 +333,11 @@ cdef class DTraceConsumer:
                             dtrace_errmsg(self.handle,
                                           dtrace_errno(self.handle)))
 
+    def setopt(self, key, value):
+        if dtrace_setopt(self.handle, key, value) != 0:
+            raise Exception(dtrace_errmsg(self.handle,
+                                          dtrace_errno(self.handle)))
+
 
 cdef class DTraceContinuousConsumer:
     """
@@ -434,6 +439,11 @@ cdef class DTraceContinuousConsumer:
 
         return status
 
+    def setopt(self, key, value):
+        if dtrace_setopt(self.handle, key, value) != 0:
+            raise Exception(dtrace_errmsg(self.handle,
+                                          dtrace_errno(self.handle)))
+
 
 class DTraceConsumerThread(Thread):
     """
