--- event.pyx.orig	2005-09-12 03:44:04 UTC
+++ event.pyx
@@ -62,9 +62,6 @@ EV_PERSIST = 0x10
 
 __event_exc = None
 
-cdef int __event_sigcb():
-    return -1
-
 cdef void __event_handler(int fd, short evtype, void *arg):
     (<object>arg).__callback(evtype)
 
@@ -109,8 +106,6 @@ cdef class event:
             event_set(&self.ev, handle, evtype, handler, <void *>self)
 
     def __simple_callback(self, short evtype):
-        cdef extern int event_gotsig
-        cdef extern int (*event_sigcb)()
         global __event_exc
         try:
             if self.callback(*self.args) != None:
@@ -120,23 +115,17 @@ cdef class event:
                     event_add(&self.ev, NULL)
         except:
             __event_exc = sys.exc_info()
-            event_sigcb = __event_sigcb
-            event_gotsig = 1
         # XXX - account for event.signal() EV_PERSIST
         if not (evtype & EV_SIGNAL) and \
            not event_pending(&self.ev, EV_READ|EV_WRITE|EV_SIGNAL|EV_TIMEOUT, NULL):
             Py_DECREF(self)
     
     def __callback(self, short evtype):
-        cdef extern int event_gotsig
-        cdef extern int (*event_sigcb)()
         global __event_exc
         try:
             self.callback(self, self.handle, evtype, self.args)
         except:
             __event_exc = sys.exc_info()
-            event_sigcb = __event_sigcb
-            event_gotsig = 1
         if not event_pending(&self.ev, EV_READ|EV_WRITE|EV_SIGNAL|EV_TIMEOUT, NULL):
             Py_DECREF(self)
 
@@ -153,7 +142,7 @@ cdef class event:
         self.timeout = timeout
         if timeout >= 0.0:
             self.tv.tv_sec = <long>timeout
-            self.tv.tv_usec = (timeout - <float>self.tv.tv_sec) * 1000000.0
+            self.tv.tv_usec = <long>(timeout - <float>self.tv.tv_sec) * 1000000
             event_add(&self.ev, &self.tv)
         else:
             self.tv.tv_sec = self.tv.tv_usec = 0
@@ -271,10 +260,6 @@ def loop(nonblock=False):
 
 def abort():
     """Abort event dispatch loop."""
-    cdef extern int event_gotsig
-    cdef extern int (*event_sigcb)()
-    event_sigcb = __event_sigcb
-    event_gotsig = 1
 
 # XXX - make sure event queue is always initialized.
 init()
