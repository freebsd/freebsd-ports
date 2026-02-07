--- src/Levenshtein/levenshtein_cpp.pyx.orig	2023-09-26 11:15:28 UTC
+++ src/Levenshtein/levenshtein_cpp.pyx
@@ -12,10 +12,10 @@ cdef extern from "<string>" namespace "std" nogil:
     object PyUnicode_FromKindAndData(int kind, const void *buffer, Py_ssize_t size)
 
 cdef extern from "<string>" namespace "std" nogil:
-    cdef cppclass basic_string[T]:
+    cdef cppclass vector[T]:
         ctypedef size_t size_type
 
-        basic_string() except +
+        vector() except +
 
         void resize(size_type) except +
 
@@ -25,10 +25,10 @@ cdef extern from "_levenshtein.hpp":
         size_type size()
 
 cdef extern from "_levenshtein.hpp":
-    cdef basic_string[uint32_t] lev_greedy_median(const vector[RF_String]& strings, const vector[double]& weights) except +
-    cdef basic_string[uint32_t] lev_median_improve(const RF_String& string, const vector[RF_String]& strings, const vector[double]& weights) except +
-    cdef basic_string[uint32_t] lev_quick_median(const vector[RF_String]& strings, const vector[double]& weights) except +
-    cdef basic_string[uint32_t] lev_set_median(const vector[RF_String]& strings, const vector[double]& weights) except +
+    cdef vector[uint32_t] lev_greedy_median(const vector[RF_String]& strings, const vector[double]& weights) except +
+    cdef vector[uint32_t] lev_median_improve(const RF_String& string, const vector[RF_String]& strings, const vector[double]& weights) except +
+    cdef vector[uint32_t] lev_quick_median(const vector[RF_String]& strings, const vector[double]& weights) except +
+    cdef vector[uint32_t] lev_set_median(const vector[RF_String]& strings, const vector[double]& weights) except +
 
     cdef double lev_set_distance(const vector[RF_String]& strings1, const vector[RF_String]& strings2) except +
     cdef double lev_edit_seq_distance(const vector[RF_String]& strings1, const vector[RF_String]& strings2) except +
