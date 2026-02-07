--- python/modules/IcePy/Util.cpp.orig	2024-06-05 08:44:17 UTC
+++ python/modules/IcePy/Util.cpp
@@ -214,7 +214,11 @@ IcePy::getFunction()
     //
     // Get name of current function.
     //
+#if PY_VERSION_HEX >= 0x02050000 && PY_VERSION_HEX < 0x030B0000
     PyFrameObject *f = PyThreadState_GET()->frame;
+#else
+    PyFrameObject *f = PyThreadState_GetFrame(PyThreadState_GET());
+#endif
     PyObjectHandle code = PyObject_GetAttrString(reinterpret_cast<PyObject*>(f), STRCAST("f_code"));
     assert(code.get());
     PyObjectHandle func = PyObject_GetAttrString(code.get(), STRCAST("co_name"));
