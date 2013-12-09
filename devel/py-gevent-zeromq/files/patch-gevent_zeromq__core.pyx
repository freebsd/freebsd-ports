Adjust import of context.pxd and socket.pxd files after update of
devel/py-pyzmg (>= 14.x). 

--- ./gevent_zeromq/core.pyx.orig	2012-07-13 21:43:35.000000000 +0000
+++ ./gevent_zeromq/core.pyx	2013-12-04 21:54:31.000000000 +0000
@@ -10,8 +10,8 @@
 from gevent.event import AsyncResult
 from gevent.hub import get_hub
 
-from zmq.core.context cimport Context as _Context
-from zmq.core.socket cimport Socket as _Socket
+from zmq.backend.cython.context cimport Context as _Context
+from zmq.backend.cython.socket cimport Socket as _Socket
 
 
 cdef class GreenSocket(_Socket):
