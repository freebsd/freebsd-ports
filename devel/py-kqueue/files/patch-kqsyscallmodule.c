--- ./kqsyscallmodule.c.orig	2001-01-29 10:59:50.000000000 +0800
+++ ./kqsyscallmodule.c	2007-08-24 18:27:42.250897722 +0800
@@ -42,6 +42,12 @@
 
 #define MAX_KEVENTS 512
 
+#if PYTHON_API_VERSION <= 1007
+    /* 1.5 compatibility */
+#define PyObject_New PyObject_NEW
+#define PyObject_Del PyMem_DEL
+#endif
+
 // ----------------------------------------------------------------------
 //			    KQEventObject
 // ----------------------------------------------------------------------
@@ -58,8 +64,7 @@
 static KQEventObject *
 newKQEventObject (PyObject *arg)
 {
-  // return PyObject_New (KQEventObject, &KQEvent_Type);
-  return PyObject_NEW (KQEventObject, &KQEvent_Type);
+  return PyObject_New (KQEventObject, &KQEvent_Type);
 }
 
 /* KQEvent methods */
@@ -67,8 +72,7 @@
 static void
 KQEvent_dealloc(KQEventObject *self)
 {
-  // PyObject_Del(self);
-  PyMem_DEL (self);
+  PyObject_Del(self);
 }
 
 // --------------------------------------------------------------------------------
@@ -201,14 +205,14 @@
 static KQueueObject *
 newKQueueObject (PyObject *arg)
 {
-  KQueueObject * self = PyObject_NEW (KQueueObject, &KQueue_Type);
+  KQueueObject * self = PyObject_New(KQueueObject, &KQueue_Type);
   if (!self) {
     PyErr_SetFromErrno (PyExc_MemoryError);
     return NULL;
   } else {
     int kqfd = kqueue();
     if (kqfd < 0) {
-      PyMem_DEL (self);
+      PyObject_Del(self);
       PyErr_SetFromErrno (PyExc_OSError);
       return NULL;
     } else {
@@ -234,7 +238,7 @@
 KQueue_dealloc(KQueueObject *self)
 {
   close (self->fd);
-  PyMem_DEL(self);
+  PyObject_Del(self);
 }
 
 /* Call kevent(2) and do appropriate digestion of lists. */
