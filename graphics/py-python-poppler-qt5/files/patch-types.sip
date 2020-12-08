From https://github.com/frescobaldi/python-poppler-qt5/pull/33/commits/6cc4d83b172ffb2d206e696ce508e508cd46b7c3

--- types.sip.orig	2019-11-22 05:56:45 UTC
+++ types.sip
@@ -182,7 +182,7 @@ template <TYPE>
   if ((l = PyList_New(sipCpp->size())) == NULL)
     return NULL;
 
-  const sipMappedType* qlinkedlist_type = sipFindMappedType("QLinkedList<TYPE>");
+  const sipTypeDef* qlinkedlist_type = sipFindType("QLinkedList<TYPE>");
 
   // Set the list elements.
   for (int i = 0; i < sipCpp->size(); ++i)
@@ -190,7 +190,7 @@ template <TYPE>
     QLinkedList<TYPE>* t = new QLinkedList<TYPE>(sipCpp->at(i));
     PyObject *tobj;
 
-    if ((tobj = sipConvertFromMappedType(t, qlinkedlist_type, sipTransferObj)) == NULL)
+    if ((tobj = sipConvertFromType(t, qlinkedlist_type, sipTransferObj)) == NULL)
     {
       Py_DECREF(l);
       delete t;
@@ -203,7 +203,7 @@ template <TYPE>
 %End
 
 %ConvertToTypeCode
-  const sipMappedType* qlinkedlist_type = sipFindMappedType("QLinkedList<TYPE>");
+  const sipTypeDef* qlinkedlist_type = sipFindType("QLinkedList<TYPE>");
 
   // Check the type if that is all that is required.
   if (sipIsErr == NULL)
@@ -212,7 +212,7 @@ template <TYPE>
       return 0;
 
     for (int i = 0; i < PySequence_Size(sipPy); ++i)
-      if (!sipCanConvertToMappedType(PySequence_ITEM(sipPy, i), qlinkedlist_type, SIP_NOT_NONE))
+      if (!sipCanConvertToType(PySequence_ITEM(sipPy, i), qlinkedlist_type, SIP_NOT_NONE))
         return 0;
 
     return 1;
@@ -224,16 +224,16 @@ template <TYPE>
   for (int i = 0; i < PySequence_Size(sipPy); ++i)
   {
     int state;
-    QLinkedList<TYPE> * t = reinterpret_cast< QLinkedList<TYPE> * >(sipConvertToMappedType(PySequence_ITEM(sipPy, i), qlinkedlist_type, sipTransferObj, SIP_NOT_NONE, &state, sipIsErr));
+    QLinkedList<TYPE> * t = reinterpret_cast< QLinkedList<TYPE> * >(sipConvertToType(PySequence_ITEM(sipPy, i), qlinkedlist_type, sipTransferObj, SIP_NOT_NONE, &state, sipIsErr));
 
     if (*sipIsErr)
     {
-      sipReleaseInstance(t, sipClass_TYPE, state);
+      sipReleaseType(t, qlinkedlist_type, state);
       delete ql;
       return 0;
     }
     ql->append(*t);
-    sipReleaseInstance(t, sipClass_TYPE, state);
+    sipReleaseType(t, qlinkedlist_type, state);
   }
 
   *sipCppPtr = ql;
