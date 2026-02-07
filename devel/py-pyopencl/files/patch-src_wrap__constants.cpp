--- src/wrap_constants.cpp.orig	2025-05-13 14:38:07 UTC
+++ src/wrap_constants.cpp
@@ -67,7 +67,7 @@ void pyopencl_expose_constants(py::module &m)
 #define DECLARE_EXC(NAME, BASE) \
   static py::exception<pyopencl::error> CL##NAME(m, #NAME, BASE);
 
-    DECLARE_EXC(Error, NULL);
+    DECLARE_EXC(Error, nullptr);
     DECLARE_EXC(MemoryError, CLError.ptr());
     DECLARE_EXC(LogicError, CLError.ptr());
     DECLARE_EXC(RuntimeError, CLError.ptr());
