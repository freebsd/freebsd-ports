--- Include/weakrefobject.h.orig	Mon Aug 12 16:21:58 2002
+++ Include/weakrefobject.h	Fri Nov 21 11:39:53 2003
@@ -39,6 +39,8 @@
 
 PyAPI_FUNC(long) _PyWeakref_GetWeakrefCount(PyWeakReference *head);
 
+PyAPI_FUNC(void) _PyWeakref_ClearRef(PyWeakReference *self);
+
 #define PyWeakref_GET_OBJECT(ref) (((PyWeakReference *)(ref))->wr_object)
 
 
