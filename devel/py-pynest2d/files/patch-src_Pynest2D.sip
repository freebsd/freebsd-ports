--- src/Pynest2D.sip.orig	2020-12-24 22:47:54 UTC
+++ src/Pynest2D.sip
@@ -49,7 +49,7 @@ using namespace placers;
         for(size_t i = 0; i < size; ++i)
         {
             Item* item = sipCpp->at(0);
-            PyObject* python_item = sipConvertFromInstance(item, sipClass_Item, sipTransferObj);
+            PyObject* python_item = sipConvertFromType(item, sipType_Item, sipTransferObj);
             if(!python_item)
             {
                 Py_DECREF(result_list);
@@ -74,20 +74,20 @@ using namespace placers;
         PyObject* list_item;
         while(list_item = PyIter_Next(iterator))
         {
-            if(!sipCanConvertToInstance(list_item, sipClass_Item, SIP_NOT_NONE))
+            if(!sipCanConvertToType(list_item, sipType_Item, SIP_NOT_NONE))
             {
                 PyErr_Format(PyExc_TypeError, "Object in iterable cannot be converted to a libnest2d Item.");
                 *sipIsErr = 1;
                 break;
             }
             int state;
-            Item* item = reinterpret_cast<Item*>(sipConvertToInstance(list_item, sipClass_Item, 0, SIP_NOT_NONE, &state, sipIsErr));
+            Item* item = reinterpret_cast<Item*>(sipConvertToType(list_item, sipType_Item, 0, SIP_NOT_NONE, &state, sipIsErr));
             if(!*sipIsErr)
             {
                 storage_vector->push_back(item);
             }
 
-            sipReleaseInstance(item, sipClass_Item, state);
+            sipReleaseType(item, sipType_Item, state);
             Py_DECREF(list_item);
         }
 
