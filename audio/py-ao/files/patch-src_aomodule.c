--- src/aomodule.c.orig	2010-06-06 18:41:04.000000000 +0200
+++ src/aomodule.c	2010-06-06 18:45:01.000000000 +0200
@@ -4,7 +4,7 @@
 static ao_option *
 dict_to_options(PyObject *dict)
 {
-  int pos = 0;
+  Py_ssize_t pos = 0;
   PyObject *key, *val;
   ao_option *head = NULL;
   int ret;
@@ -71,7 +71,7 @@ parse_args(PyObject *args, PyObject *kwa
   
   *overwrite = 0;
 
-  if(PyArg_ParseTupleAndKeywords(args, kwargs, "s|llllO!sl", 
+  if(PyArg_ParseTupleAndKeywords(args, kwargs, "s|iiiiO!si", 
 				 (char **) driver_name_kwlist,
 				 &driver_name, 
 				 &format->bits, 
@@ -84,7 +84,7 @@ parse_args(PyObject *args, PyObject *kwa
     *driver_id = ao_driver_id(driver_name);
   } else {
     PyErr_Clear();
-    if(!(PyArg_ParseTupleAndKeywords(args, kwargs, "i|llllO!sl",
+    if(!(PyArg_ParseTupleAndKeywords(args, kwargs, "i|iiiiO!si",
 				     (char **) driver_id_kwlist,
 				     driver_id, 
 				     &format->bits, 
@@ -114,6 +114,7 @@ py_ao_new(PyObject *self, PyObject *args
   ao_sample_format sample_format;
   ao_Object *retobj;
 
+  memset(&sample_format, 0, sizeof(sample_format));
   if (!parse_args(args, kwargs, 
 		  &sample_format, &py_options,
 		  &filename, &driver_id, &overwrite))
@@ -141,8 +142,9 @@ py_ao_new(PyObject *self, PyObject *args
     return NULL;
   }
 
-  retobj = (ao_Object *) PyObject_NEW(ao_Object, &ao_Type);
+  retobj = (ao_Object *) PyObject_New(ao_Object, &ao_Type);
   retobj->dev = dev;
+  retobj->driver_id = driver_id;
   return (PyObject *) retobj;
 }
 
@@ -150,7 +152,7 @@ static void
 py_ao_dealloc(ao_Object *self)
 {
   ao_close(self->dev);
-  PyMem_DEL(self);
+  PyObject_Del(self);
 }
 
 static PyObject *
@@ -184,7 +186,7 @@ py_ao_driver_info(PyObject *self, PyObje
 
     /* It's a method */
     ao_Object *ao_self = (ao_Object *) self;
-    info = ao_driver_info(ao_self->dev->driver_id);
+    info = ao_driver_info(ao_self->driver_id);
 
   } else {
 
