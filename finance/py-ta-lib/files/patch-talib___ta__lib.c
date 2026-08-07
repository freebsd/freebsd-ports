-- Regenerate talib/_ta_lib.c with the Cython version in the ports tree
-- (3.2.8) against the installed NumPy headers. The bundled copy references
-- NumPy 2.x internal C-API macros (PyDataType_*, _PyUFuncObject_*,
-- _PyDatetimeScalarObject_*) that are not declared in the ports tree NumPy
-- package, causing build failures in Poudriere.
--- talib/_ta_lib.c.orig	2026-07-22 20:08:45 UTC
+++ talib/_ta_lib.c
@@ -4,15 +4,15 @@
 {
     "distutils": {
         "depends": [
-            "/Users/jbenedik/.cache/uv/builds-v0/.tmpW1VPkd/lib/python3.12/site-packages/numpy/_core/include/numpy/arrayobject.h",
-            "/Users/jbenedik/.cache/uv/builds-v0/.tmpW1VPkd/lib/python3.12/site-packages/numpy/_core/include/numpy/arrayscalars.h",
-            "/Users/jbenedik/.cache/uv/builds-v0/.tmpW1VPkd/lib/python3.12/site-packages/numpy/_core/include/numpy/ndarrayobject.h",
-            "/Users/jbenedik/.cache/uv/builds-v0/.tmpW1VPkd/lib/python3.12/site-packages/numpy/_core/include/numpy/ndarraytypes.h",
-            "/Users/jbenedik/.cache/uv/builds-v0/.tmpW1VPkd/lib/python3.12/site-packages/numpy/_core/include/numpy/ufuncobject.h",
-            "/opt/homebrew/include/ta-lib/ta_abstract.h",
-            "/opt/homebrew/include/ta-lib/ta_common.h",
-            "/opt/homebrew/include/ta-lib/ta_defs.h",
-            "/opt/homebrew/include/ta-lib/ta_func.h"
+            "/usr/local/include/ta-lib/ta_abstract.h",
+            "/usr/local/include/ta-lib/ta_common.h",
+            "/usr/local/include/ta-lib/ta_defs.h",
+            "/usr/local/include/ta-lib/ta_func.h",
+            "/usr/local/lib/python3.12/site-packages/numpy/_core/include/numpy/arrayobject.h",
+            "/usr/local/lib/python3.12/site-packages/numpy/_core/include/numpy/arrayscalars.h",
+            "/usr/local/lib/python3.12/site-packages/numpy/_core/include/numpy/ndarrayobject.h",
+            "/usr/local/lib/python3.12/site-packages/numpy/_core/include/numpy/ndarraytypes.h",
+            "/usr/local/lib/python3.12/site-packages/numpy/_core/include/numpy/ufuncobject.h"
         ],
         "include_dirs": [
             "/usr/include",
@@ -21,7 +21,7 @@
             "/opt/local/include",
             "/opt/homebrew/include",
             "/opt/homebrew/opt/ta-lib/include",
-            "/Users/jbenedik/.cache/uv/builds-v0/.tmpW1VPkd/lib/python3.12/site-packages/numpy/_core/include"
+            "/usr/local/lib/python3.12/site-packages/numpy/_core/include"
         ],
         "libraries": [
             "ta-lib"
@@ -1427,7 +1427,7 @@ static const char* const __pyx_f[] = {
   "talib/_ta_lib.pyx",
   "talib/_common.pxi",
   "talib/_abstract.pxi",
-  "../../.cache/uv/builds-v0/.tmpW1VPkd/lib/python3.12/site-packages/numpy/__init__.cython-30.pxd",
+  "../../../../../local/lib/python3.12/site-packages/numpy/__init__.cython-30.pxd",
   "talib/_func.pxi",
   "talib/_stream.pxi",
   "cpython/type.pxd",
@@ -2914,11 +2914,6 @@ static int __Pyx_State_RemoveModule(void*);
 #define __PYX_ABI_MODULE_NAME "_cython_" CYTHON_ABI
 #define __PYX_TYPE_MODULE_PREFIX __PYX_ABI_MODULE_NAME "."
 
-static CYTHON_INLINE PyTypeObject *__pyx_f_5numpy_5dtype_7typeobj_typeobj(PyArray_Descr *__pyx_v_self); /* proto*/
-static CYTHON_INLINE char __pyx_f_5numpy_5dtype_4kind_kind(PyArray_Descr *__pyx_v_self); /* proto*/
-static CYTHON_INLINE char __pyx_f_5numpy_5dtype_4type_type(PyArray_Descr *__pyx_v_self); /* proto*/
-static CYTHON_INLINE char __pyx_f_5numpy_5dtype_9byteorder_byteorder(PyArray_Descr *__pyx_v_self); /* proto*/
-static CYTHON_INLINE int __pyx_f_5numpy_5dtype_8type_num_type_num(PyArray_Descr *__pyx_v_self); /* proto*/
 static CYTHON_INLINE npy_intp __pyx_f_5numpy_5dtype_8itemsize_itemsize(PyArray_Descr *__pyx_v_self); /* proto*/
 static CYTHON_INLINE npy_intp __pyx_f_5numpy_5dtype_9alignment_alignment(PyArray_Descr *__pyx_v_self); /* proto*/
 static CYTHON_INLINE PyObject *__pyx_f_5numpy_5dtype_6fields_fields(PyArray_Descr *__pyx_v_self); /* proto*/
@@ -2938,17 +2933,6 @@ static CYTHON_INLINE char *__pyx_f_5numpy_7ndarray_4da
 static CYTHON_INLINE npy_intp *__pyx_f_5numpy_7ndarray_7strides_strides(PyArrayObject *__pyx_v_self); /* proto*/
 static CYTHON_INLINE npy_intp __pyx_f_5numpy_7ndarray_4size_size(PyArrayObject *__pyx_v_self); /* proto*/
 static CYTHON_INLINE char *__pyx_f_5numpy_7ndarray_4data_data(PyArrayObject *__pyx_v_self); /* proto*/
-static CYTHON_INLINE int __pyx_f_5numpy_5ufunc_3nin_nin(PyUFuncObject *__pyx_v_self); /* proto*/
-static CYTHON_INLINE int __pyx_f_5numpy_5ufunc_4nout_nout(PyUFuncObject *__pyx_v_self); /* proto*/
-static CYTHON_INLINE int __pyx_f_5numpy_5ufunc_5nargs_nargs(PyUFuncObject *__pyx_v_self); /* proto*/
-static CYTHON_INLINE PyUFuncGenericFunction *__pyx_f_5numpy_5ufunc_9functions_functions(PyUFuncObject *__pyx_v_self); /* proto*/
-static CYTHON_INLINE void **__pyx_f_5numpy_5ufunc_4data_data(PyUFuncObject *__pyx_v_self); /* proto*/
-static CYTHON_INLINE int __pyx_f_5numpy_5ufunc_6ntypes_ntypes(PyUFuncObject *__pyx_v_self); /* proto*/
-static CYTHON_INLINE char const *__pyx_f_5numpy_5ufunc_4name_name(PyUFuncObject *__pyx_v_self); /* proto*/
-static CYTHON_INLINE char const *__pyx_f_5numpy_5ufunc_3doc_doc(PyUFuncObject *__pyx_v_self); /* proto*/
-static CYTHON_INLINE void *__pyx_f_5numpy_5ufunc_3ptr_ptr(PyUFuncObject *__pyx_v_self); /* proto*/
-static CYTHON_INLINE PyObject *__pyx_f_5numpy_5ufunc_3obj_obj(PyUFuncObject *__pyx_v_self); /* proto*/
-static CYTHON_INLINE PyObject *__pyx_f_5numpy_5ufunc_9userloops_userloops(PyUFuncObject *__pyx_v_self); /* proto*/
 
 /* Module declarations from "libc.string" */
 
@@ -4722,71 +4706,6 @@ return 0;
 /* #### Code section: module_code ### */
 
 
-static CYTHON_INLINE PyTypeObject *__pyx_f_5numpy_5dtype_7typeobj_typeobj(PyArray_Descr *__pyx_v_self) {
-  PyTypeObject *__pyx_r;
-
-  __pyx_r = PyDataType_TYPEOBJ(__pyx_v_self);
-  goto __pyx_L0;
-
-
-  /* function exit code */
-  __pyx_L0:;
-  return __pyx_r;
-}
-
-
-static CYTHON_INLINE char __pyx_f_5numpy_5dtype_4kind_kind(PyArray_Descr *__pyx_v_self) {
-  char __pyx_r;
-
-  __pyx_r = PyDataType_KIND(__pyx_v_self);
-  goto __pyx_L0;
-
-
-  /* function exit code */
-  __pyx_L0:;
-  return __pyx_r;
-}
-
-
-static CYTHON_INLINE char __pyx_f_5numpy_5dtype_4type_type(PyArray_Descr *__pyx_v_self) {
-  char __pyx_r;
-
-  __pyx_r = PyDataType_TYPE(__pyx_v_self);
-  goto __pyx_L0;
-
-
-  /* function exit code */
-  __pyx_L0:;
-  return __pyx_r;
-}
-
-
-static CYTHON_INLINE char __pyx_f_5numpy_5dtype_9byteorder_byteorder(PyArray_Descr *__pyx_v_self) {
-  char __pyx_r;
-
-  __pyx_r = PyDataType_BYTEORDER(__pyx_v_self);
-  goto __pyx_L0;
-
-
-  /* function exit code */
-  __pyx_L0:;
-  return __pyx_r;
-}
-
-
-static CYTHON_INLINE int __pyx_f_5numpy_5dtype_8type_num_type_num(PyArray_Descr *__pyx_v_self) {
-  int __pyx_r;
-
-  __pyx_r = PyDataType_TYPENUM(__pyx_v_self);
-  goto __pyx_L0;
-
-
-  /* function exit code */
-  __pyx_L0:;
-  return __pyx_r;
-}
-
-
 static CYTHON_INLINE npy_intp __pyx_f_5numpy_5dtype_8itemsize_itemsize(PyArray_Descr *__pyx_v_self) {
   npy_intp __pyx_r;
 
@@ -5068,7 +4987,7 @@ static CYTHON_INLINE PyObject *__pyx_f_5numpy_PyArray_
   __Pyx_RefNannySetupContext("PyArray_MultiIterNew1", 0);
 
   __Pyx_XDECREF(__pyx_r);
-  __pyx_t_1 = PyArray_MultiIterNew(1, ((void *)__pyx_v_a)); if (unlikely(!__pyx_t_1)) __PYX_ERR(3, 795, __pyx_L1_error)
+  __pyx_t_1 = PyArray_MultiIterNew(1, ((void *)__pyx_v_a)); if (unlikely(!__pyx_t_1)) __PYX_ERR(3, 778, __pyx_L1_error)
   __Pyx_GOTREF(__pyx_t_1);
   __pyx_r = __pyx_t_1;
   __pyx_t_1 = 0;
@@ -5097,7 +5016,7 @@ static CYTHON_INLINE PyObject *__pyx_f_5numpy_PyArray_
   __Pyx_RefNannySetupContext("PyArray_MultiIterNew2", 0);
 
   __Pyx_XDECREF(__pyx_r);
-  __pyx_t_1 = PyArray_MultiIterNew(2, ((void *)__pyx_v_a), ((void *)__pyx_v_b)); if (unlikely(!__pyx_t_1)) __PYX_ERR(3, 798, __pyx_L1_error)
+  __pyx_t_1 = PyArray_MultiIterNew(2, ((void *)__pyx_v_a), ((void *)__pyx_v_b)); if (unlikely(!__pyx_t_1)) __PYX_ERR(3, 781, __pyx_L1_error)
   __Pyx_GOTREF(__pyx_t_1);
   __pyx_r = __pyx_t_1;
   __pyx_t_1 = 0;
@@ -5126,7 +5045,7 @@ static CYTHON_INLINE PyObject *__pyx_f_5numpy_PyArray_
   __Pyx_RefNannySetupContext("PyArray_MultiIterNew3", 0);
 
   __Pyx_XDECREF(__pyx_r);
-  __pyx_t_1 = PyArray_MultiIterNew(3, ((void *)__pyx_v_a), ((void *)__pyx_v_b), ((void *)__pyx_v_c)); if (unlikely(!__pyx_t_1)) __PYX_ERR(3, 801, __pyx_L1_error)
+  __pyx_t_1 = PyArray_MultiIterNew(3, ((void *)__pyx_v_a), ((void *)__pyx_v_b), ((void *)__pyx_v_c)); if (unlikely(!__pyx_t_1)) __PYX_ERR(3, 784, __pyx_L1_error)
   __Pyx_GOTREF(__pyx_t_1);
   __pyx_r = __pyx_t_1;
   __pyx_t_1 = 0;
@@ -5155,7 +5074,7 @@ static CYTHON_INLINE PyObject *__pyx_f_5numpy_PyArray_
   __Pyx_RefNannySetupContext("PyArray_MultiIterNew4", 0);
 
   __Pyx_XDECREF(__pyx_r);
-  __pyx_t_1 = PyArray_MultiIterNew(4, ((void *)__pyx_v_a), ((void *)__pyx_v_b), ((void *)__pyx_v_c), ((void *)__pyx_v_d)); if (unlikely(!__pyx_t_1)) __PYX_ERR(3, 804, __pyx_L1_error)
+  __pyx_t_1 = PyArray_MultiIterNew(4, ((void *)__pyx_v_a), ((void *)__pyx_v_b), ((void *)__pyx_v_c), ((void *)__pyx_v_d)); if (unlikely(!__pyx_t_1)) __PYX_ERR(3, 787, __pyx_L1_error)
   __Pyx_GOTREF(__pyx_t_1);
   __pyx_r = __pyx_t_1;
   __pyx_t_1 = 0;
@@ -5184,7 +5103,7 @@ static CYTHON_INLINE PyObject *__pyx_f_5numpy_PyArray_
   __Pyx_RefNannySetupContext("PyArray_MultiIterNew5", 0);
 
   __Pyx_XDECREF(__pyx_r);
-  __pyx_t_1 = PyArray_MultiIterNew(5, ((void *)__pyx_v_a), ((void *)__pyx_v_b), ((void *)__pyx_v_c), ((void *)__pyx_v_d), ((void *)__pyx_v_e)); if (unlikely(!__pyx_t_1)) __PYX_ERR(3, 807, __pyx_L1_error)
+  __pyx_t_1 = PyArray_MultiIterNew(5, ((void *)__pyx_v_a), ((void *)__pyx_v_b), ((void *)__pyx_v_c), ((void *)__pyx_v_d), ((void *)__pyx_v_e)); if (unlikely(!__pyx_t_1)) __PYX_ERR(3, 790, __pyx_L1_error)
   __Pyx_GOTREF(__pyx_t_1);
   __pyx_r = __pyx_t_1;
   __pyx_t_1 = 0;
@@ -5237,149 +5156,6 @@ static CYTHON_INLINE PyObject *__pyx_f_5numpy_PyDataTy
 }
 
 
-static CYTHON_INLINE int __pyx_f_5numpy_5ufunc_3nin_nin(PyUFuncObject *__pyx_v_self) {
-  int __pyx_r;
-
-  __pyx_r = _PyUFuncObject_GET_ITEM_DATA(__pyx_v_self)->nin;
-  goto __pyx_L0;
-
-
-  /* function exit code */
-  __pyx_L0:;
-  return __pyx_r;
-}
-
-
-static CYTHON_INLINE int __pyx_f_5numpy_5ufunc_4nout_nout(PyUFuncObject *__pyx_v_self) {
-  int __pyx_r;
-
-  __pyx_r = _PyUFuncObject_GET_ITEM_DATA(__pyx_v_self)->nout;
-  goto __pyx_L0;
-
-
-  /* function exit code */
-  __pyx_L0:;
-  return __pyx_r;
-}
-
-
-static CYTHON_INLINE int __pyx_f_5numpy_5ufunc_5nargs_nargs(PyUFuncObject *__pyx_v_self) {
-  int __pyx_r;
-
-  __pyx_r = _PyUFuncObject_GET_ITEM_DATA(__pyx_v_self)->nargs;
-  goto __pyx_L0;
-
-
-  /* function exit code */
-  __pyx_L0:;
-  return __pyx_r;
-}
-
-
-static CYTHON_INLINE PyUFuncGenericFunction *__pyx_f_5numpy_5ufunc_9functions_functions(PyUFuncObject *__pyx_v_self) {
-  PyUFuncGenericFunction *__pyx_r;
-
-  __pyx_r = _PyUFuncObject_GET_ITEM_DATA(__pyx_v_self)->functions;
-  goto __pyx_L0;
-
-
-  /* function exit code */
-  __pyx_L0:;
-  return __pyx_r;
-}
-
-
-static CYTHON_INLINE void **__pyx_f_5numpy_5ufunc_4data_data(PyUFuncObject *__pyx_v_self) {
-  void **__pyx_r;
-
-  __pyx_r = ((void **)_PyUFuncObject_GET_ITEM_DATA(__pyx_v_self)->data);
-  goto __pyx_L0;
-
-
-  /* function exit code */
-  __pyx_L0:;
-  return __pyx_r;
-}
-
-
-static CYTHON_INLINE int __pyx_f_5numpy_5ufunc_6ntypes_ntypes(PyUFuncObject *__pyx_v_self) {
-  int __pyx_r;
-
-  __pyx_r = _PyUFuncObject_GET_ITEM_DATA(__pyx_v_self)->ntypes;
-  goto __pyx_L0;
-
-
-  /* function exit code */
-  __pyx_L0:;
-  return __pyx_r;
-}
-
-
-static CYTHON_INLINE char const *__pyx_f_5numpy_5ufunc_4name_name(PyUFuncObject *__pyx_v_self) {
-  char const *__pyx_r;
-
-  __pyx_r = _PyUFuncObject_GET_ITEM_DATA(__pyx_v_self)->name;
-  goto __pyx_L0;
-
-
-  /* function exit code */
-  __pyx_L0:;
-  return __pyx_r;
-}
-
-
-static CYTHON_INLINE char const *__pyx_f_5numpy_5ufunc_3doc_doc(PyUFuncObject *__pyx_v_self) {
-  char const *__pyx_r;
-
-  __pyx_r = _PyUFuncObject_GET_ITEM_DATA(__pyx_v_self)->doc;
-  goto __pyx_L0;
-
-
-  /* function exit code */
-  __pyx_L0:;
-  return __pyx_r;
-}
-
-
-static CYTHON_INLINE void *__pyx_f_5numpy_5ufunc_3ptr_ptr(PyUFuncObject *__pyx_v_self) {
-  void *__pyx_r;
-
-  __pyx_r = _PyUFuncObject_GET_ITEM_DATA(__pyx_v_self)->ptr;
-  goto __pyx_L0;
-
-
-  /* function exit code */
-  __pyx_L0:;
-  return __pyx_r;
-}
-
-
-static CYTHON_INLINE PyObject *__pyx_f_5numpy_5ufunc_3obj_obj(PyUFuncObject *__pyx_v_self) {
-  PyObject *__pyx_r;
-
-  __pyx_r = _PyUFuncObject_GET_ITEM_DATA(__pyx_v_self)->obj;
-  goto __pyx_L0;
-
-
-  /* function exit code */
-  __pyx_L0:;
-  return __pyx_r;
-}
-
-
-static CYTHON_INLINE PyObject *__pyx_f_5numpy_5ufunc_9userloops_userloops(PyUFuncObject *__pyx_v_self) {
-  PyObject *__pyx_r;
-
-  __pyx_r = _PyUFuncObject_GET_ITEM_DATA(__pyx_v_self)->userloops;
-  goto __pyx_L0;
-
-
-  /* function exit code */
-  __pyx_L0:;
-  return __pyx_r;
-}
-
-
 static CYTHON_INLINE void __pyx_f_5numpy_set_array_base(PyArrayObject *__pyx_v_arr, PyObject *__pyx_v_base) {
   int __pyx_t_1;
   int __pyx_lineno = 0;
@@ -5388,7 +5164,7 @@ static CYTHON_INLINE void __pyx_f_5numpy_set_array_bas
 
   Py_INCREF(__pyx_v_base);
 
-  __pyx_t_1 = PyArray_SetBaseObject(__pyx_v_arr, __pyx_v_base); if (unlikely(__pyx_t_1 == ((int)-1))) __PYX_ERR(3, 1067, __pyx_L1_error)
+  __pyx_t_1 = PyArray_SetBaseObject(__pyx_v_arr, __pyx_v_base); if (unlikely(__pyx_t_1 == ((int)-1))) __PYX_ERR(3, 997, __pyx_L1_error)
 
 
   /* function exit code */
@@ -5458,7 +5234,7 @@ static CYTHON_INLINE int __pyx_f_5numpy_import_array(v
     __Pyx_XGOTREF(__pyx_t_3);
     /*try:*/ {
 
-      __pyx_t_4 = _import_array(); if (unlikely(__pyx_t_4 == ((int)-1))) __PYX_ERR(3, 1079, __pyx_L3_error)
+      __pyx_t_4 = _import_array(); if (unlikely(__pyx_t_4 == ((int)-1))) __PYX_ERR(3, 1009, __pyx_L3_error)
 
     }
     __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
@@ -5470,7 +5246,7 @@ static CYTHON_INLINE int __pyx_f_5numpy_import_array(v
     __pyx_t_4 = __Pyx_PyErr_ExceptionMatches(((PyObject *)(((PyTypeObject*)PyExc_Exception))));
     if (__pyx_t_4) {
       __Pyx_AddTraceback("numpy.import_array", __pyx_clineno, __pyx_lineno, __pyx_filename);
-      if (__Pyx_GetException(&__pyx_t_5, &__pyx_t_6, &__pyx_t_7) < 0) __PYX_ERR(3, 1080, __pyx_L5_except_error)
+      if (__Pyx_GetException(&__pyx_t_5, &__pyx_t_6, &__pyx_t_7) < 0) __PYX_ERR(3, 1010, __pyx_L5_except_error)
       __Pyx_XGOTREF(__pyx_t_5);
       __Pyx_XGOTREF(__pyx_t_6);
       __Pyx_XGOTREF(__pyx_t_7);
@@ -5481,12 +5257,12 @@ static CYTHON_INLINE int __pyx_f_5numpy_import_array(v
         PyObject *__pyx_callargs[2] = {__pyx_t_9, __pyx_mstate_global->__pyx_kp_u_numpy__core_multiarray_failed_to};
         __pyx_t_8 = __Pyx_PyObject_FastCall((PyObject*)(((PyTypeObject*)PyExc_ImportError)), __pyx_callargs+__pyx_t_10, (2-__pyx_t_10) | (__pyx_t_10*__Pyx_PY_VECTORCALL_ARGUMENTS_OFFSET));
         __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
-        if (unlikely(!__pyx_t_8)) __PYX_ERR(3, 1081, __pyx_L5_except_error)
+        if (unlikely(!__pyx_t_8)) __PYX_ERR(3, 1011, __pyx_L5_except_error)
         __Pyx_GOTREF(__pyx_t_8);
       }
       __Pyx_Raise(__pyx_t_8, 0, 0, 0);
       __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
-      __PYX_ERR(3, 1081, __pyx_L5_except_error)
+      __PYX_ERR(3, 1011, __pyx_L5_except_error)
     }
     goto __pyx_L5_except_error;
 
@@ -5544,7 +5320,7 @@ static CYTHON_INLINE int __pyx_f_5numpy_import_umath(v
     __Pyx_XGOTREF(__pyx_t_3);
     /*try:*/ {
 
-      __pyx_t_4 = _import_umath(); if (unlikely(__pyx_t_4 == ((int)-1))) __PYX_ERR(3, 1085, __pyx_L3_error)
+      __pyx_t_4 = _import_umath(); if (unlikely(__pyx_t_4 == ((int)-1))) __PYX_ERR(3, 1015, __pyx_L3_error)
 
     }
     __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
@@ -5556,7 +5332,7 @@ static CYTHON_INLINE int __pyx_f_5numpy_import_umath(v
     __pyx_t_4 = __Pyx_PyErr_ExceptionMatches(((PyObject *)(((PyTypeObject*)PyExc_Exception))));
     if (__pyx_t_4) {
       __Pyx_AddTraceback("numpy.import_umath", __pyx_clineno, __pyx_lineno, __pyx_filename);
-      if (__Pyx_GetException(&__pyx_t_5, &__pyx_t_6, &__pyx_t_7) < 0) __PYX_ERR(3, 1086, __pyx_L5_except_error)
+      if (__Pyx_GetException(&__pyx_t_5, &__pyx_t_6, &__pyx_t_7) < 0) __PYX_ERR(3, 1016, __pyx_L5_except_error)
       __Pyx_XGOTREF(__pyx_t_5);
       __Pyx_XGOTREF(__pyx_t_6);
       __Pyx_XGOTREF(__pyx_t_7);
@@ -5567,12 +5343,12 @@ static CYTHON_INLINE int __pyx_f_5numpy_import_umath(v
         PyObject *__pyx_callargs[2] = {__pyx_t_9, __pyx_mstate_global->__pyx_kp_u_numpy__core_umath_failed_to_impo};
         __pyx_t_8 = __Pyx_PyObject_FastCall((PyObject*)(((PyTypeObject*)PyExc_ImportError)), __pyx_callargs+__pyx_t_10, (2-__pyx_t_10) | (__pyx_t_10*__Pyx_PY_VECTORCALL_ARGUMENTS_OFFSET));
         __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
-        if (unlikely(!__pyx_t_8)) __PYX_ERR(3, 1087, __pyx_L5_except_error)
+        if (unlikely(!__pyx_t_8)) __PYX_ERR(3, 1017, __pyx_L5_except_error)
         __Pyx_GOTREF(__pyx_t_8);
       }
       __Pyx_Raise(__pyx_t_8, 0, 0, 0);
       __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
-      __PYX_ERR(3, 1087, __pyx_L5_except_error)
+      __PYX_ERR(3, 1017, __pyx_L5_except_error)
     }
     goto __pyx_L5_except_error;
 
@@ -5630,7 +5406,7 @@ static CYTHON_INLINE int __pyx_f_5numpy_import_ufunc(v
     __Pyx_XGOTREF(__pyx_t_3);
     /*try:*/ {
 
-      __pyx_t_4 = _import_umath(); if (unlikely(__pyx_t_4 == ((int)-1))) __PYX_ERR(3, 1091, __pyx_L3_error)
+      __pyx_t_4 = _import_umath(); if (unlikely(__pyx_t_4 == ((int)-1))) __PYX_ERR(3, 1021, __pyx_L3_error)
 
     }
     __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
@@ -5642,7 +5418,7 @@ static CYTHON_INLINE int __pyx_f_5numpy_import_ufunc(v
     __pyx_t_4 = __Pyx_PyErr_ExceptionMatches(((PyObject *)(((PyTypeObject*)PyExc_Exception))));
     if (__pyx_t_4) {
       __Pyx_AddTraceback("numpy.import_ufunc", __pyx_clineno, __pyx_lineno, __pyx_filename);
-      if (__Pyx_GetException(&__pyx_t_5, &__pyx_t_6, &__pyx_t_7) < 0) __PYX_ERR(3, 1092, __pyx_L5_except_error)
+      if (__Pyx_GetException(&__pyx_t_5, &__pyx_t_6, &__pyx_t_7) < 0) __PYX_ERR(3, 1022, __pyx_L5_except_error)
       __Pyx_XGOTREF(__pyx_t_5);
       __Pyx_XGOTREF(__pyx_t_6);
       __Pyx_XGOTREF(__pyx_t_7);
@@ -5653,12 +5429,12 @@ static CYTHON_INLINE int __pyx_f_5numpy_import_ufunc(v
         PyObject *__pyx_callargs[2] = {__pyx_t_9, __pyx_mstate_global->__pyx_kp_u_numpy__core_umath_failed_to_impo};
         __pyx_t_8 = __Pyx_PyObject_FastCall((PyObject*)(((PyTypeObject*)PyExc_ImportError)), __pyx_callargs+__pyx_t_10, (2-__pyx_t_10) | (__pyx_t_10*__Pyx_PY_VECTORCALL_ARGUMENTS_OFFSET));
         __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
-        if (unlikely(!__pyx_t_8)) __PYX_ERR(3, 1093, __pyx_L5_except_error)
+        if (unlikely(!__pyx_t_8)) __PYX_ERR(3, 1023, __pyx_L5_except_error)
         __Pyx_GOTREF(__pyx_t_8);
       }
       __Pyx_Raise(__pyx_t_8, 0, 0, 0);
       __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
-      __PYX_ERR(3, 1093, __pyx_L5_except_error)
+      __PYX_ERR(3, 1023, __pyx_L5_except_error)
     }
     goto __pyx_L5_except_error;
 
@@ -5718,7 +5494,7 @@ static CYTHON_INLINE npy_datetime __pyx_f_5numpy_get_d
 static CYTHON_INLINE npy_datetime __pyx_f_5numpy_get_datetime64_value(PyObject *__pyx_v_obj) {
   npy_datetime __pyx_r;
 
-  __pyx_r = _PyDatetimeScalarObject_GetValue(__pyx_v_obj);
+  __pyx_r = ((PyDatetimeScalarObject *)__pyx_v_obj)->obval;
   goto __pyx_L0;
 
 
@@ -5731,7 +5507,7 @@ static CYTHON_INLINE npy_timedelta __pyx_f_5numpy_get_
 static CYTHON_INLINE npy_timedelta __pyx_f_5numpy_get_timedelta64_value(PyObject *__pyx_v_obj) {
   npy_timedelta __pyx_r;
 
-  __pyx_r = _PyTimedeltaScalarObject_GetValue(__pyx_v_obj);
+  __pyx_r = ((PyTimedeltaScalarObject *)__pyx_v_obj)->obval;
   goto __pyx_L0;
 
 
@@ -5744,7 +5520,7 @@ static CYTHON_INLINE NPY_DATETIMEUNIT __pyx_f_5numpy_g
 static CYTHON_INLINE NPY_DATETIMEUNIT __pyx_f_5numpy_get_datetime64_unit(PyObject *__pyx_v_obj) {
   NPY_DATETIMEUNIT __pyx_r;
 
-  __pyx_r = _PyDatetimeScalarObject_GetMetadata(__pyx_v_obj).base;
+  __pyx_r = ((NPY_DATETIMEUNIT)((PyDatetimeScalarObject *)__pyx_v_obj)->obmeta.base);
   goto __pyx_L0;
 
 
@@ -80869,7 +80645,7 @@ static int __Pyx_modinit_type_import_code(__pyx_mstate
   #else
   sizeof(PyArrayIterObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyArrayIterObject),
   #endif
-  __Pyx_ImportType_CheckSize_Ignore_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_flatiter) __PYX_ERR(3, 286, __pyx_L1_error)
+  __Pyx_ImportType_CheckSize_Ignore_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_flatiter) __PYX_ERR(3, 274, __pyx_L1_error)
   __pyx_mstate->__pyx_ptype_5numpy_broadcast = __Pyx_ImportType_3_2_8(__pyx_t_1, "numpy", "broadcast",
   #if defined(PYPY_VERSION_NUM) && PYPY_VERSION_NUM < 0x050B0000
   sizeof(PyArrayMultiIterObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyArrayMultiIterObject),
@@ -80878,7 +80654,7 @@ static int __Pyx_modinit_type_import_code(__pyx_mstate
   #else
   sizeof(PyArrayMultiIterObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyArrayMultiIterObject),
   #endif
-  __Pyx_ImportType_CheckSize_Ignore_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_broadcast) __PYX_ERR(3, 290, __pyx_L1_error)
+  __Pyx_ImportType_CheckSize_Ignore_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_broadcast) __PYX_ERR(3, 278, __pyx_L1_error)
   __pyx_mstate->__pyx_ptype_5numpy_ndarray = __Pyx_ImportType_3_2_8(__pyx_t_1, "numpy", "ndarray",
   #if defined(PYPY_VERSION_NUM) && PYPY_VERSION_NUM < 0x050B0000
   sizeof(PyArrayObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyArrayObject),
@@ -80887,7 +80663,7 @@ static int __Pyx_modinit_type_import_code(__pyx_mstate
   #else
   sizeof(PyArrayObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyArrayObject),
   #endif
-  __Pyx_ImportType_CheckSize_Ignore_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_ndarray) __PYX_ERR(3, 329, __pyx_L1_error)
+  __Pyx_ImportType_CheckSize_Ignore_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_ndarray) __PYX_ERR(3, 317, __pyx_L1_error)
   __pyx_mstate->__pyx_ptype_5numpy_generic = __Pyx_ImportType_3_2_8(__pyx_t_1, "numpy", "generic",
   #if defined(PYPY_VERSION_NUM) && PYPY_VERSION_NUM < 0x050B0000
   sizeof(PyObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyObject),
@@ -80896,7 +80672,7 @@ static int __Pyx_modinit_type_import_code(__pyx_mstate
   #else
   sizeof(PyObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyObject),
   #endif
-  __Pyx_ImportType_CheckSize_Warn_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_generic) __PYX_ERR(3, 847, __pyx_L1_error)
+  __Pyx_ImportType_CheckSize_Warn_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_generic) __PYX_ERR(3, 826, __pyx_L1_error)
   __pyx_mstate->__pyx_ptype_5numpy_number = __Pyx_ImportType_3_2_8(__pyx_t_1, "numpy", "number",
   #if defined(PYPY_VERSION_NUM) && PYPY_VERSION_NUM < 0x050B0000
   sizeof(PyObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyObject),
@@ -80905,7 +80681,7 @@ static int __Pyx_modinit_type_import_code(__pyx_mstate
   #else
   sizeof(PyObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyObject),
   #endif
-  __Pyx_ImportType_CheckSize_Warn_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_number) __PYX_ERR(3, 849, __pyx_L1_error)
+  __Pyx_ImportType_CheckSize_Warn_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_number) __PYX_ERR(3, 828, __pyx_L1_error)
   __pyx_mstate->__pyx_ptype_5numpy_integer = __Pyx_ImportType_3_2_8(__pyx_t_1, "numpy", "integer",
   #if defined(PYPY_VERSION_NUM) && PYPY_VERSION_NUM < 0x050B0000
   sizeof(PyObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyObject),
@@ -80914,7 +80690,7 @@ static int __Pyx_modinit_type_import_code(__pyx_mstate
   #else
   sizeof(PyObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyObject),
   #endif
-  __Pyx_ImportType_CheckSize_Warn_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_integer) __PYX_ERR(3, 851, __pyx_L1_error)
+  __Pyx_ImportType_CheckSize_Warn_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_integer) __PYX_ERR(3, 830, __pyx_L1_error)
   __pyx_mstate->__pyx_ptype_5numpy_signedinteger = __Pyx_ImportType_3_2_8(__pyx_t_1, "numpy", "signedinteger",
   #if defined(PYPY_VERSION_NUM) && PYPY_VERSION_NUM < 0x050B0000
   sizeof(PyObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyObject),
@@ -80923,7 +80699,7 @@ static int __Pyx_modinit_type_import_code(__pyx_mstate
   #else
   sizeof(PyObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyObject),
   #endif
-  __Pyx_ImportType_CheckSize_Warn_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_signedinteger) __PYX_ERR(3, 853, __pyx_L1_error)
+  __Pyx_ImportType_CheckSize_Warn_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_signedinteger) __PYX_ERR(3, 832, __pyx_L1_error)
   __pyx_mstate->__pyx_ptype_5numpy_unsignedinteger = __Pyx_ImportType_3_2_8(__pyx_t_1, "numpy", "unsignedinteger",
   #if defined(PYPY_VERSION_NUM) && PYPY_VERSION_NUM < 0x050B0000
   sizeof(PyObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyObject),
@@ -80932,7 +80708,7 @@ static int __Pyx_modinit_type_import_code(__pyx_mstate
   #else
   sizeof(PyObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyObject),
   #endif
-  __Pyx_ImportType_CheckSize_Warn_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_unsignedinteger) __PYX_ERR(3, 855, __pyx_L1_error)
+  __Pyx_ImportType_CheckSize_Warn_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_unsignedinteger) __PYX_ERR(3, 834, __pyx_L1_error)
   __pyx_mstate->__pyx_ptype_5numpy_inexact = __Pyx_ImportType_3_2_8(__pyx_t_1, "numpy", "inexact",
   #if defined(PYPY_VERSION_NUM) && PYPY_VERSION_NUM < 0x050B0000
   sizeof(PyObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyObject),
@@ -80941,7 +80717,7 @@ static int __Pyx_modinit_type_import_code(__pyx_mstate
   #else
   sizeof(PyObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyObject),
   #endif
-  __Pyx_ImportType_CheckSize_Warn_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_inexact) __PYX_ERR(3, 857, __pyx_L1_error)
+  __Pyx_ImportType_CheckSize_Warn_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_inexact) __PYX_ERR(3, 836, __pyx_L1_error)
   __pyx_mstate->__pyx_ptype_5numpy_floating = __Pyx_ImportType_3_2_8(__pyx_t_1, "numpy", "floating",
   #if defined(PYPY_VERSION_NUM) && PYPY_VERSION_NUM < 0x050B0000
   sizeof(PyObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyObject),
@@ -80950,7 +80726,7 @@ static int __Pyx_modinit_type_import_code(__pyx_mstate
   #else
   sizeof(PyObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyObject),
   #endif
-  __Pyx_ImportType_CheckSize_Warn_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_floating) __PYX_ERR(3, 859, __pyx_L1_error)
+  __Pyx_ImportType_CheckSize_Warn_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_floating) __PYX_ERR(3, 838, __pyx_L1_error)
   __pyx_mstate->__pyx_ptype_5numpy_complexfloating = __Pyx_ImportType_3_2_8(__pyx_t_1, "numpy", "complexfloating",
   #if defined(PYPY_VERSION_NUM) && PYPY_VERSION_NUM < 0x050B0000
   sizeof(PyObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyObject),
@@ -80959,7 +80735,7 @@ static int __Pyx_modinit_type_import_code(__pyx_mstate
   #else
   sizeof(PyObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyObject),
   #endif
-  __Pyx_ImportType_CheckSize_Warn_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_complexfloating) __PYX_ERR(3, 861, __pyx_L1_error)
+  __Pyx_ImportType_CheckSize_Warn_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_complexfloating) __PYX_ERR(3, 840, __pyx_L1_error)
   __pyx_mstate->__pyx_ptype_5numpy_flexible = __Pyx_ImportType_3_2_8(__pyx_t_1, "numpy", "flexible",
   #if defined(PYPY_VERSION_NUM) && PYPY_VERSION_NUM < 0x050B0000
   sizeof(PyObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyObject),
@@ -80968,7 +80744,7 @@ static int __Pyx_modinit_type_import_code(__pyx_mstate
   #else
   sizeof(PyObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyObject),
   #endif
-  __Pyx_ImportType_CheckSize_Warn_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_flexible) __PYX_ERR(3, 863, __pyx_L1_error)
+  __Pyx_ImportType_CheckSize_Warn_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_flexible) __PYX_ERR(3, 842, __pyx_L1_error)
   __pyx_mstate->__pyx_ptype_5numpy_character = __Pyx_ImportType_3_2_8(__pyx_t_1, "numpy", "character",
   #if defined(PYPY_VERSION_NUM) && PYPY_VERSION_NUM < 0x050B0000
   sizeof(PyObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyObject),
@@ -80977,7 +80753,7 @@ static int __Pyx_modinit_type_import_code(__pyx_mstate
   #else
   sizeof(PyObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyObject),
   #endif
-  __Pyx_ImportType_CheckSize_Warn_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_character) __PYX_ERR(3, 865, __pyx_L1_error)
+  __Pyx_ImportType_CheckSize_Warn_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_character) __PYX_ERR(3, 844, __pyx_L1_error)
   __pyx_mstate->__pyx_ptype_5numpy_ufunc = __Pyx_ImportType_3_2_8(__pyx_t_1, "numpy", "ufunc",
   #if defined(PYPY_VERSION_NUM) && PYPY_VERSION_NUM < 0x050B0000
   sizeof(PyUFuncObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyUFuncObject),
@@ -80986,7 +80762,7 @@ static int __Pyx_modinit_type_import_code(__pyx_mstate
   #else
   sizeof(PyUFuncObject), __PYX_GET_STRUCT_ALIGNMENT_3_2_8(PyUFuncObject),
   #endif
-  __Pyx_ImportType_CheckSize_Ignore_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_ufunc) __PYX_ERR(3, 946, __pyx_L1_error)
+  __Pyx_ImportType_CheckSize_Ignore_3_2_8); if (!__pyx_mstate->__pyx_ptype_5numpy_ufunc) __PYX_ERR(3, 908, __pyx_L1_error)
   __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
   __Pyx_RefNannyFinishContext();
   return 0;
