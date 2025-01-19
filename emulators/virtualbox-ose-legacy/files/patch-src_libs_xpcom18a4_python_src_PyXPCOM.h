--- src/libs/xpcom18a4/python/src/PyXPCOM.h.orig
+++ src/libs/xpcom18a4/python/src/PyXPCOM.h
@@ -140,7 +140,7 @@ inline PyObject *PyBool_FromLong(long ok)
 #  ifndef PyUnicode_AsUTF8
 #   define PyUnicode_AsUTF8(o) _PyUnicode_AsString(o)
 #  endif
-#  ifndef PyUnicode_AsUTF8AndSize
+#  if PY_MINOR_VERSION < 10
 #   define PyUnicode_AsUTF8AndSize(o,s) _PyUnicode_AsStringAndSize(o,s)
 #  endif
 typedef struct PyMethodChain
