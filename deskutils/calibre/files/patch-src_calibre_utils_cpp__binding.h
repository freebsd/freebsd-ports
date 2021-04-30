--- src/calibre/utils/cpp_binding.h.orig	2021-04-30 02:00:12 UTC
+++ src/calibre/utils/cpp_binding.h
@@ -14,7 +14,7 @@
 
 #define arraysz(x) (sizeof(x)/sizeof(x[0]))
 
-template<typename T, void free_T(void*), T null=reinterpret_cast<T>(NULL)>
+template<typename T, void free_T(void*), T null=static_cast<T>(NULL)>
 class generic_raii {
 	private:
 		generic_raii( const generic_raii & ) noexcept;
@@ -45,7 +45,7 @@ typedef generic_raii<wchar_t*, PyMem_Free> wchar_raii;
 static inline void python_object_destructor(void *p) { PyObject *x = reinterpret_cast<PyObject*>(p); Py_XDECREF(x); }
 typedef generic_raii<PyObject*, python_object_destructor> pyobject_raii;
 
-template<typename T, void free_T(void*), size_t sz, T null=reinterpret_cast<T>(NULL)>
+template<typename T, void free_T(void*), size_t sz, T null=static_cast<T>(NULL)>
 class generic_raii_array {
 	private:
 		generic_raii_array( const generic_raii_array & ) noexcept;
