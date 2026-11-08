--- libs/mpi/src/python/py_request.cpp.orig	2026-08-05 17:09:12 UTC
+++ libs/mpi/src/python/py_request.cpp
@@ -64,9 +64,13 @@ const object python::request_with_value::wrap_test()
     return object();
 }
 
-
 namespace boost { namespace mpi { namespace python {
-  
+
+bool operator==(request_with_value const&, request_with_value const&) {
+  PyErr_SetString(PyExc_NotImplementedError, "mpi requests are not comparable");
+  throw error_already_set();
+}
+
 const object request_test(request &req)                                         
 {                                                                               
   ::boost::optional<status> stat = req.test();                                  
