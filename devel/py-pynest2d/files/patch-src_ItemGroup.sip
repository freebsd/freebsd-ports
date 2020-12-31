--- src/ItemGroup.sip.orig	2020-12-24 22:41:47 UTC
+++ src/ItemGroup.sip
@@ -23,7 +23,7 @@
         for(size_t i = 0; i < size; ++i)
         {
             Item item = sipCpp->at(0);
-            PyObject* python_item = sipConvertFromInstance(&item, sipClass_Item, sipTransferObj);
+            PyObject* python_item = sipConvertFromType(&item, sipType_Item, sipTransferObj);
             if(!python_item)
             {
                 Py_DECREF(result_list);
@@ -48,20 +48,20 @@
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
                 result->push_back(*item);
             }
 
-            sipReleaseInstance(item, sipClass_Item, state);
+            sipReleaseType(item, sipType_Item, state);
             Py_DECREF(list_item);
         }
 
@@ -74,4 +74,4 @@
         *sipCppPtr = result;
         return sipGetState(sipTransferObj);
     %End
-};
\ No newline at end of file
+};
