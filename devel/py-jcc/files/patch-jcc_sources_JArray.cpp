--- jcc/sources/JArray.cpp.orig	2014-02-05 23:36:44 UTC
+++ jcc/sources/JArray.cpp
@@ -312,7 +312,7 @@ static PyObject *seq_concat(U *self, PyO
     PyObject *list = toSequence<U>(self);
 
     if (list != NULL &&
-        PyList_Type.tp_as_sequence->sq_inplace_concat(list, arg) < 0)
+        PyList_Type.tp_as_sequence->sq_inplace_concat(list, arg) == NULL)
     {
         Py_DECREF(list);
         return NULL;
@@ -327,7 +327,7 @@ static PyObject *seq_repeat(U *self, Py_
     PyObject *list = toSequence<U>(self);
 
     if (list != NULL &&
-        PyList_Type.tp_as_sequence->sq_inplace_repeat(list, n) < 0)
+        PyList_Type.tp_as_sequence->sq_inplace_repeat(list, n) == NULL)
     {
         Py_DECREF(list);
         return NULL;
