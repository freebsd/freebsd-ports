--- src/python/num_util.cpp	Thu Nov 30 07:06:03 2006
+++ src/python/num_util.cpp.port	Thu Mar  8 11:18:50 2007
@@ -230,7 +230,7 @@
     PyErr_SetString(PyExc_ValueError, "expected a PyArrayObject");
     throw_error_already_set();
   }
-  int* dims_ptr = PyArray_DIMS(arr.ptr());
+  npy_intp* dims_ptr = PyArray_DIMS(arr.ptr());
   int the_rank = rank(arr);
   for (int i = 0; i < the_rank; i++){
     out_dims.push_back(*(dims_ptr + i));
