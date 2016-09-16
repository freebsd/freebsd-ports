--- src/libs/xpcom18a4/python/src/TypeObject.cpp.orig	2016-09-12 16:20:11 UTC
+++ src/libs/xpcom18a4/python/src/TypeObject.cpp
@@ -155,13 +155,21 @@ PyXPCOM_TypeObject::Py_richcmp(PyObject 
 }
 
 // @pymethod int|Py_nsISupports|__hash__|Implement a hash-code for the XPCOM object using XPCOM identity rules.
+#if PY_VERSION_HEX < 0x03020000
 /*static*/long PyXPCOM_TypeObject::Py_hash(PyObject *self)
+#else
+/*static*/Py_hash_t PyXPCOM_TypeObject::Py_hash(PyObject *self)
+#endif
 {
 	// We always return the value of the nsISupports *.
 	nsISupports *pUnkThis;
 	if (!Py_nsISupports::InterfaceFromPyObject(self, NS_GET_IID(nsISupports), &pUnkThis, PR_FALSE))
 		return -1;
+#if PY_VERSION_HEX < 0x03020000
 	long ret = _Py_HashPointer(pUnkThis);
+#else
+	Py_hash_t ret = _Py_HashPointer(pUnkThis);
+#endif
 	pUnkThis->Release();
 	return ret;
 }
