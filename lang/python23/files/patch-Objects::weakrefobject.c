--- Objects/weakrefobject.c.orig	Tue Jul 15 06:46:23 2003
+++ Objects/weakrefobject.c	Fri Nov 21 11:39:53 2003
@@ -53,17 +53,43 @@
         if (*list == self)
             *list = self->wr_next;
         self->wr_object = Py_None;
-        self->wr_callback = NULL;
         if (self->wr_prev != NULL)
             self->wr_prev->wr_next = self->wr_next;
         if (self->wr_next != NULL)
             self->wr_next->wr_prev = self->wr_prev;
         self->wr_prev = NULL;
         self->wr_next = NULL;
-        Py_XDECREF(callback);
+    }
+    if (callback != NULL) {
+        Py_DECREF(callback);
+        self->wr_callback = NULL;
     }
 }
 
+/* Cyclic gc uses this to *just* clear the passed-in reference, leaving
+ * the callback intact and uncalled.  It must be possible to call self's
+ * tp_dealloc() after calling this, so self has to be left in a sane enough
+ * state for that to work.  We expect tp_dealloc to decref the callback
+ * then.  The reason for not letting clear_weakref() decref the callback
+ * right now is that if the callback goes away, that may in turn trigger
+ * another callback (if a weak reference to the callback exists) -- running
+ * arbitrary Python code in the middle of gc is a disaster.  The convolution
+ * here allows gc to delay triggering such callbacks until the world is in
+ * a sane state again.
+ */
+void
+_PyWeakref_ClearRef(PyWeakReference *self)
+{
+    PyObject *callback;
+
+    assert(self != NULL);
+    assert(PyWeakref_Check(self));
+    /* Preserve and restore the callback around clear_weakref. */
+    callback = self->wr_callback;
+    self->wr_callback = NULL;
+    clear_weakref(self);
+    self->wr_callback = callback;
+}
 
 static void
 weakref_dealloc(PyWeakReference *self)
@@ -117,7 +143,7 @@
     self->hash = PyObject_Hash(PyWeakref_GET_OBJECT(self));
     return self->hash;
 }
-    
+
 
 static PyObject *
 weakref_repr(PyWeakReference *self)
@@ -324,7 +350,7 @@
 WRAP_BINARY(proxy_ixor, PyNumber_InPlaceXor)
 WRAP_BINARY(proxy_ior, PyNumber_InPlaceOr)
 
-static int 
+static int
 proxy_nonzero(PyWeakReference *proxy)
 {
     PyObject *o = PyWeakref_GET_OBJECT(proxy);
