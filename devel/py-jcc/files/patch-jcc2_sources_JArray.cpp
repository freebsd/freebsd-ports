--- jcc2/sources/JArray.cpp.orig	2017-08-13 00:37:59 UTC
+++ jcc2/sources/JArray.cpp
@@ -312,7 +312,7 @@ static PyObject *seq_concat(U *self, PyObject *arg)
     PyObject *list = toSequence<U>(self);
 
     if (list != NULL &&
-        PyList_Type.tp_as_sequence->sq_inplace_concat(list, arg) < 0)
+        PyList_Type.tp_as_sequence->sq_inplace_concat(list, arg) == NULL)
     {
         Py_DECREF(list);
         return NULL;
@@ -327,7 +327,7 @@ static PyObject *seq_repeat(U *self, Py_ssize_t n)
     PyObject *list = toSequence<U>(self);
 
     if (list != NULL &&
-        PyList_Type.tp_as_sequence->sq_inplace_repeat(list, n) < 0)
+        PyList_Type.tp_as_sequence->sq_inplace_repeat(list, n) == NULL)
     {
         Py_DECREF(list);
         return NULL;
