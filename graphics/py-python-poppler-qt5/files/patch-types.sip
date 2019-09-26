--- types.sip.orig	2019-09-18 15:22:50 UTC
+++ types.sip
@@ -266,13 +266,13 @@ template <TYPE>
 
     if (sipPy == Py_None)
     {
-        *sipCppPtr = new long();
+        *sipCppPtr = new time_t();
         return 1;
     }
 
     if (PyLong_Check(sipPy))
     {
-        *sipCppPtr = new long(PyLong_AsLong(sipPy)); 
+        *sipCppPtr = new time_t(PyLong_AsLong(sipPy));
         return 1;
     }
     return 0;
