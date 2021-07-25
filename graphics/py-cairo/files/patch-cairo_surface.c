https://github.com/pygobject/pycairo/commit/0f8cdc058239
https://github.com/pygobject/pycairo/commit/4c5377787624
https://github.com/pygobject/pycairo/commit/590bcd2ecc9c

--- cairo/surface.c.orig	2018-11-03 09:30:34 UTC
+++ cairo/surface.c
@@ -142,6 +142,7 @@ _write_func (void *closure, const unsigned char *data,
 
 static const cairo_user_data_key_t surface_base_object_key;
 static const cairo_user_data_key_t surface_is_mapped_image;
+static const cairo_user_data_key_t surface_buffer_view_key;
 
 static void
 surface_dealloc (PycairoSurface *o) {
@@ -439,28 +440,30 @@ _destroy_mime_user_data_func (PyObject *user_data) {
 static void
 _destroy_mime_data_func (PyObject *user_data) {
   cairo_surface_t *surface;
+  Py_buffer *view;
   PyObject *mime_intern;
 
   PyGILState_STATE gstate = PyGILState_Ensure();
 
   /* Remove the user data holding the source object */
   surface = PyCapsule_GetPointer(PyTuple_GET_ITEM(user_data, 0), NULL);
-  mime_intern = PyTuple_GET_ITEM(user_data, 2);
+  view = PyCapsule_GetPointer(PyTuple_GET_ITEM(user_data, 1), NULL);
+  mime_intern = PyTuple_GET_ITEM(user_data, 3);
   cairo_surface_set_user_data(
     surface, (cairo_user_data_key_t *)mime_intern, NULL, NULL);
 
   /* Destroy the user data */
-  _destroy_mime_user_data_func(user_data);
+  PyBuffer_Release (view);
+  PyMem_Free (view);
+  Py_DECREF(user_data);
 
   PyGILState_Release(gstate);
 }
 
 static PyObject *
 surface_set_mime_data (PycairoSurface *o, PyObject *args) {
-  PyObject *obj, *user_data, *mime_intern, *capsule;
-  const unsigned char *buffer;
+  PyObject *obj, *user_data, *mime_intern, *surface_capsule, *view_capsule;
   const char *mime_type;
-  Py_ssize_t buffer_len;
   int res;
   cairo_status_t status;
 
@@ -475,38 +478,58 @@ surface_set_mime_data (PycairoSurface *o, PyObject *ar
     Py_RETURN_NONE;
   }
 
-PYCAIRO_BEGIN_IGNORE_DEPRECATED
-  res = PyObject_AsReadBuffer (obj, (const void **)&buffer, &buffer_len);
-PYCAIRO_END_IGNORE_DEPRECATED
-  if (res == -1)
+  Py_buffer *view = PyMem_Malloc (sizeof (Py_buffer));
+  if (view == NULL) {
+    PyErr_NoMemory ();
     return NULL;
+  }
 
+  res = PyObject_GetBuffer (obj, view, PyBUF_READ);
+  if (res == -1) {
+      PyMem_Free (view);
+      return NULL;
+  }
+
   /* We use the interned mime type string as user data key and store the
    * passed in object with it. This allows us to return the same object in
    * surface_get_mime_data().
    */
   mime_intern = PYCAIRO_PyUnicode_InternFromString(mime_type);
-  capsule = PyCapsule_New(o->surface, NULL, NULL);
-  user_data = Py_BuildValue("(NOO)", capsule, obj, mime_intern);
-  if (user_data == NULL)
+  surface_capsule = PyCapsule_New(o->surface, NULL, NULL);
+  view_capsule = PyCapsule_New(view, NULL, NULL);
+  user_data = Py_BuildValue("(NNOO)", surface_capsule, view_capsule, obj, mime_intern);
+  if (user_data == NULL) {
+    PyBuffer_Release (view);
+    PyMem_Free (view);
     return NULL;
+  }
 
   status = cairo_surface_set_user_data(
     o->surface, (cairo_user_data_key_t *)mime_intern, user_data,
     (cairo_destroy_func_t)_destroy_mime_user_data_func);
-  if (status != CAIRO_STATUS_SUCCESS)
+
+  if (status != CAIRO_STATUS_SUCCESS) {
+    PyBuffer_Release (view);
+    PyMem_Free (view);
     Py_DECREF(user_data);
-  RETURN_NULL_IF_CAIRO_ERROR(status);
+    Pycairo_Check_Status (status);
+    return NULL;
+  }
 
+  Py_INCREF(user_data);
   status = cairo_surface_set_mime_data (
-    o->surface, mime_type, buffer, (unsigned long)buffer_len,
+    o->surface, mime_type, view->buf, (unsigned long)view->len,
     (cairo_destroy_func_t)_destroy_mime_data_func, user_data);
+
   if (status != CAIRO_STATUS_SUCCESS) {
     cairo_surface_set_user_data(
       o->surface, (cairo_user_data_key_t *)mime_intern, NULL, NULL);
+    PyBuffer_Release (view);
+    PyMem_Free (view);
+    Py_DECREF(user_data);
+    Pycairo_Check_Status (status);
+    return NULL;
   }
-  RETURN_NULL_IF_CAIRO_ERROR(status);
-  Py_INCREF(user_data);
 
   Py_RETURN_NONE;
 }
@@ -534,7 +557,7 @@ surface_get_mime_data (PycairoSurface *o, PyObject *ar
     /* In case the mime data wasn't set through the Python API just copy it */
     return Py_BuildValue(PYCAIRO_DATA_FORMAT "#", buffer, buffer_len);
   } else {
-    obj = PyTuple_GET_ITEM(user_data, 1);
+    obj = PyTuple_GET_ITEM(user_data, 2);
     Py_INCREF(obj);
     return obj;
   }
@@ -804,14 +827,22 @@ image_surface_new (PyTypeObject *type, PyObject *args,
 	     NULL);
 }
 
+static void
+_release_buffer_destroy_func (void *user_data) {
+  Py_buffer *view = (Py_buffer *)user_data;
+  PyGILState_STATE gstate = PyGILState_Ensure();
+  PyBuffer_Release (view);
+  PyMem_Free (view);
+  PyGILState_Release(gstate);
+}
+
 /* METH_CLASS */
 static PyObject *
 image_surface_create_for_data (PyTypeObject *type, PyObject *args) {
   cairo_surface_t *surface;
   cairo_format_t format;
-  unsigned char *buffer;
+  cairo_status_t status;
   int width, height, stride = -1, res, format_arg;
-  Py_ssize_t buffer_len;
   PyObject *obj;
 
   if (!PyArg_ParseTuple (args, "Oiii|i:ImageSurface.create_for_data",
@@ -820,12 +851,6 @@ image_surface_create_for_data (PyTypeObject *type, PyO
 
   format = (cairo_format_t)format_arg;
 
-PYCAIRO_BEGIN_IGNORE_DEPRECATED
-  res = PyObject_AsWriteBuffer (obj, (void **)&buffer, &buffer_len);
-PYCAIRO_END_IGNORE_DEPRECATED
-  if (res == -1)
-    return NULL;
-
   if (width <= 0) {
     PyErr_SetString(PyExc_ValueError, "width must be positive");
     return NULL;
@@ -843,15 +868,42 @@ PYCAIRO_END_IGNORE_DEPRECATED
       return NULL;
     }
   }
-  if (height * stride > buffer_len) {
+
+  Py_buffer *view = PyMem_Malloc (sizeof (Py_buffer));
+  if (view == NULL) {
+    PyErr_NoMemory ();
+    return NULL;
+  }
+
+  res = PyObject_GetBuffer (obj, view, PyBUF_WRITABLE);
+  if (res == -1) {
+    PyMem_Free (view);
+    return NULL;
+  }
+
+  if (height * stride > view->len) {
+    PyBuffer_Release (view);
+    PyMem_Free (view);
     PyErr_SetString(PyExc_TypeError, "buffer is not long enough");
     return NULL;
   }
+
   Py_BEGIN_ALLOW_THREADS;
-  surface = cairo_image_surface_create_for_data (buffer, format, width,
-						 height, stride);
+  surface = cairo_image_surface_create_for_data (view->buf, format, width,
+                                                 height, stride);
   Py_END_ALLOW_THREADS;
-  return _surface_create_with_object(surface, obj);
+
+  status = cairo_surface_set_user_data(
+    surface, &surface_buffer_view_key, view,
+    (cairo_destroy_func_t)_release_buffer_destroy_func);
+  if (Pycairo_Check_Status (status)) {
+    cairo_surface_destroy (surface);
+    PyBuffer_Release (view);
+    PyMem_Free (view);
+    return NULL;
+  }
+
+  return PycairoSurface_FromSurface(surface, NULL);
 }
 
 
