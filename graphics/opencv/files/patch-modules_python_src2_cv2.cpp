--- modules/python/src2/cv2.cpp.orig	2018-02-23 08:38:33 UTC
+++ modules/python/src2/cv2.cpp
@@ -886,7 +886,7 @@ bool pyopencv_to(PyObject* obj, String& value, const c
     (void)name;
     if(!obj || obj == Py_None)
         return true;
-    char* str = PyString_AsString(obj);
+    const char* str = PyString_AsString(obj);
     if(!str)
         return false;
     value = String(str);
