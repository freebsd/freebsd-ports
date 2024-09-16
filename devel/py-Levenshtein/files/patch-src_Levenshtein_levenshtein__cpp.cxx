--- src/Levenshtein/levenshtein_cpp.cxx.orig	2023-09-26 11:15:40 UTC
+++ src/Levenshtein/levenshtein_cpp.cxx
@@ -3094,7 +3094,7 @@ static PyObject *__pyx_pf_11Levenshtein_15levenshtein_
 static PyObject *__pyx_pf_11Levenshtein_15levenshtein_cpp_median(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_strlist, PyObject *__pyx_v_wlist) {
   std::vector<double>  __pyx_v_weights;
   std::vector<RF_String>  __pyx_v_strings;
-  std::basic_string<uint32_t>  __pyx_v_median;
+  std::vector<uint32_t>  __pyx_v_median;
   PyObject *__pyx_r = NULL;
   __Pyx_RefNannyDeclarations
   int __pyx_t_1;
@@ -3104,7 +3104,7 @@ static PyObject *__pyx_pf_11Levenshtein_15levenshtein_
   PyObject *__pyx_t_5 = NULL;
   std::vector<double>  __pyx_t_6;
   std::vector<RF_String>  __pyx_t_7;
-  std::basic_string<uint32_t>  __pyx_t_8;
+  std::vector<uint32_t>  __pyx_t_8;
   int __pyx_lineno = 0;
   const char *__pyx_filename = NULL;
   int __pyx_clineno = 0;
@@ -3345,7 +3345,7 @@ static PyObject *__pyx_pf_11Levenshtein_15levenshtein_
 static PyObject *__pyx_pf_11Levenshtein_15levenshtein_cpp_2quickmedian(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_strlist, PyObject *__pyx_v_wlist) {
   std::vector<double>  __pyx_v_weights;
   std::vector<RF_String>  __pyx_v_strings;
-  std::basic_string<uint32_t>  __pyx_v_median;
+  std::vector<uint32_t>  __pyx_v_median;
   PyObject *__pyx_r = NULL;
   __Pyx_RefNannyDeclarations
   int __pyx_t_1;
@@ -3355,7 +3355,7 @@ static PyObject *__pyx_pf_11Levenshtein_15levenshtein_
   PyObject *__pyx_t_5 = NULL;
   std::vector<double>  __pyx_t_6;
   std::vector<RF_String>  __pyx_t_7;
-  std::basic_string<uint32_t>  __pyx_t_8;
+  std::vector<uint32_t>  __pyx_t_8;
   int __pyx_lineno = 0;
   const char *__pyx_filename = NULL;
   int __pyx_clineno = 0;
@@ -3612,7 +3612,7 @@ static PyObject *__pyx_pf_11Levenshtein_15levenshtein_
   std::vector<double>  __pyx_v_weights;
   RF_String __pyx_v_query;
   std::vector<RF_String>  __pyx_v_strings;
-  std::basic_string<uint32_t>  __pyx_v_median;
+  std::vector<uint32_t>  __pyx_v_median;
   PyObject *__pyx_r = NULL;
   __Pyx_RefNannyDeclarations
   int __pyx_t_1;
@@ -3623,7 +3623,7 @@ static PyObject *__pyx_pf_11Levenshtein_15levenshtein_
   std::vector<double>  __pyx_t_6;
   RF_String __pyx_t_7;
   std::vector<RF_String>  __pyx_t_8;
-  std::basic_string<uint32_t>  __pyx_t_9;
+  std::vector<uint32_t>  __pyx_t_9;
   int __pyx_lineno = 0;
   const char *__pyx_filename = NULL;
   int __pyx_clineno = 0;
@@ -3874,7 +3874,7 @@ static PyObject *__pyx_pf_11Levenshtein_15levenshtein_
 static PyObject *__pyx_pf_11Levenshtein_15levenshtein_cpp_6setmedian(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_strlist, PyObject *__pyx_v_wlist) {
   std::vector<double>  __pyx_v_weights;
   std::vector<RF_String>  __pyx_v_strings;
-  std::basic_string<uint32_t>  __pyx_v_median;
+  std::vector<uint32_t>  __pyx_v_median;
   PyObject *__pyx_r = NULL;
   __Pyx_RefNannyDeclarations
   int __pyx_t_1;
@@ -3884,7 +3884,7 @@ static PyObject *__pyx_pf_11Levenshtein_15levenshtein_
   PyObject *__pyx_t_5 = NULL;
   std::vector<double>  __pyx_t_6;
   std::vector<RF_String>  __pyx_t_7;
-  std::basic_string<uint32_t>  __pyx_t_8;
+  std::vector<uint32_t>  __pyx_t_8;
   int __pyx_lineno = 0;
   const char *__pyx_filename = NULL;
   int __pyx_clineno = 0;
