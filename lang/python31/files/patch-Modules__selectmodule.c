--- ./Modules/selectmodule.c.orig	2013-11-30 23:09:48.211062086 +1100
+++ ./Modules/selectmodule.c	2013-11-30 23:53:51.740895007 +1100
@@ -1229,7 +1229,7 @@
 
     EV_SET(&(self->e), 0, EVFILT_READ, EV_ADD, 0, 0, 0); /* defaults */
 
-    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O|hhiii:kevent", kwlist,
+    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O|hHIii:kevent", kwlist,
         &pfd, &(self->e.filter), &(self->e.flags),
         &(self->e.fflags), &(self->e.data), &(self->e.udata))) {
         return -1;
