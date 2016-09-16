--- src/libs/xpcom18a4/python/src/PyIID.cpp.orig	2016-09-12 16:20:10 UTC
+++ src/libs/xpcom18a4/python/src/PyIID.cpp
@@ -318,12 +318,20 @@ Py_nsIID::PyTypeMethod_str(PyObject *sel
 	return ret;
 }
 
+#if PY_VERSION_HEX < 0x03020000
 /* static */long
+#else
+/* static */Py_hash_t
+#endif
 Py_nsIID::PyTypeMethod_hash(PyObject *self)
 {
 	const nsIID &iid = ((Py_nsIID *)self)->m_iid;
 
+#if PY_VERSION_HEX < 0x03020000
 	long ret = iid.m0 + iid.m1 + iid.m2;
+#else
+	Py_hash_t ret = iid.m0 + iid.m1 + iid.m2;
+#endif
 	for (int i=0;i<7;i++)
 		ret += iid.m3[i];
 	if ( ret == -1 )
