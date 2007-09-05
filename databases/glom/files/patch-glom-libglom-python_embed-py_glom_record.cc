--- glom/libglom/python_embed/py_glom_record.cc.orig	2006-04-28 03:12:31.000000000 -0500
+++ glom/libglom/python_embed/py_glom_record.cc	2007-09-05 00:21:02.305894450 -0500
@@ -50,51 +50,57 @@
 
 //Set the object's member data, from the parameters supplied when creating the object:
 static int
-Record_init(PyGlomRecord *self, PyObject * /* args */, PyObject * /* kwds */)
+Record_init(PyObject *self, PyObject * /* args */, PyObject * /* kwds */)
 {
+  PyGlomRecord *self_record = (PyGlomRecord*)self;
+
   //static char *kwlist[] = {"test", NULL};
 
   //if(!PyArg_ParseTupleAndKeywords(args, kwds, "|i", kwlist,
    //                                 &self->m_test))
    // return -1;
 
-  if(self)
+  if(self_record)
   {
-    self->m_related = 0;
+    self_record->m_related = 0;
 
-    if(self->m_pMap_field_values == 0)
-      self->m_pMap_field_values = new PyGlomRecord::type_map_field_values();
+    if(self_record->m_pMap_field_values == 0)
+      self_record->m_pMap_field_values = new PyGlomRecord::type_map_field_values();
   }
 
   return 0;
 }
 
 static void
-Record_dealloc(PyGlomRecord* self)
+Record_dealloc(PyObject* self)
 {
-  if(self->m_pMap_field_values)
+  PyGlomRecord *self_record = (PyGlomRecord*)self;
+
+  if(self_record->m_pMap_field_values)
   {
-    delete self->m_pMap_field_values;
-    self->m_pMap_field_values = 0;
+    delete self_record->m_pMap_field_values;
+    self_record->m_pMap_field_values = 0;
   }
 
-  self->ob_type->tp_free((PyObject*)self);
+  self_record->ob_type->tp_free((PyObject*)self);
 }
 
 
 static PyObject *
-Record__get_related(PyGlomRecord* self, void* /* closure */)
+Record__get_related(PyObject* self, void* /* closure */)
 {
+  PyGlomRecord *self_record = (PyGlomRecord*)self;
+
   //We initialize it here, so that this work never happens if it's not needed:
-  if(!(self->m_related))
+  if(!(self_record->m_related))
   {
     //Return a new RelatedRecord:
     PyObject* new_args = PyTuple_New(0);
-    self->m_related = (PyGlomRelated*)PyObject_Call((PyObject*)PyGlomRelated_GetPyType(), new_args, 0);
+    self_record->m_related = (PyGlomRelated*)PyObject_Call((PyObject*)PyGlomRelated_GetPyType(), new_args, 0);
     Py_DECREF(new_args);
 
     //Fill it:
-    Document_Glom::type_vecRelationships vecRelationships = self->m_document->get_relationships(*(self->m_table_name));
+    Document_Glom::type_vecRelationships vecRelationships = self_record->m_document->get_relationships(*(self_record->m_table_name));
     PyGlomRelated::type_map_relationships map_relationships;
     for(Document_Glom::type_vecRelationships::const_iterator iter = vecRelationships.begin(); iter != vecRelationships.end(); ++iter)
     {
@@ -102,14 +108,14 @@
         map_relationships[(*iter)->get_name()] = *iter;
     }
 
-    PyGlomRelated_SetRelationships(self->m_related, map_relationships);
+    PyGlomRelated_SetRelationships(self_record->m_related, map_relationships);
 
-    self->m_related->m_record = self;
-    Py_XINCREF(self); //unreffed in the self->m_related's _dealloc. //TODO: Is this a circular reference?
+    self_record->m_related->m_record = self_record;
+    Py_XINCREF(self_record); //unreffed in the self->m_related's _dealloc. //TODO: Is this a circular reference?
   }
 
-  Py_INCREF(self->m_related); //Should we do this?
-  return (PyObject*)self->m_related;
+  Py_INCREF(self_record->m_related); //Should we do this?
+  return (PyObject*)self_record->m_related;
 }
 
 
@@ -122,31 +128,44 @@
 
 
 
+//Adapt to API changes in Python 2.5:
+#if defined(PY_VERSION_HEX) && (PY_VERSION_HEX >= 0x02050000) /* Python 2.5+ */
+static Py_ssize_t
+Record_tp_as_mapping_length(PyObject *self)
+{
+  PyGlomRecord *self_record = (PyGlomRecord*)self;
+  return self_record->m_pMap_field_values->size();
+}
+#else
 static int
-Record_tp_as_mapping_length(PyGlomRecord *self)
+Record_tp_as_mapping_length(PyObject *self)
 {
-  return self->m_pMap_field_values->size();
+  PyGlomRecord *self_record = (PyGlomRecord*)self;
+  return (int)(self->m_pMap_field_values->size());
 }
+#endif
 
 static PyObject *
-Record_tp_as_mapping_getitem(PyGlomRecord *self, PyObject *item)
+Record_tp_as_mapping_getitem(PyObject *self, PyObject *item)
 {
+  PyGlomRecord *self_record = (PyGlomRecord*)self;
+
   if(PyString_Check(item))
   {
     const char* pchKey = PyString_AsString(item);
     if(pchKey)
     {
       const Glib::ustring key(pchKey);
-      if(self && self->m_pMap_field_values)
+      if(self_record && self_record->m_pMap_field_values)
       {
-        PyGlomRecord::type_map_field_values::const_iterator iterFind = self->m_pMap_field_values->find(key);
-        if(iterFind != self->m_pMap_field_values->end())
+        PyGlomRecord::type_map_field_values::const_iterator iterFind = self_record->m_pMap_field_values->find(key);
+        if(iterFind != self_record->m_pMap_field_values->end())
         {
           return pygda_value_as_pyobject(iterFind->second.gobj(), true /* copy */);
         }
         else
         {
-          g_warning("Record_tp_as_mapping_getitem(): item not found in m_pMap_field_values. size=%d, item=%s", self->m_pMap_field_values->size(), pchKey);
+          g_warning("Record_tp_as_mapping_getitem(): item not found in m_pMap_field_values. size=%d, item=%s", (int)self_record->m_pMap_field_values->size(), pchKey);
         }
       }
       else
@@ -180,8 +199,8 @@
 */
 
 static PyMappingMethods Record_tp_as_mapping = {
-    (inquiry)Record_tp_as_mapping_length,
-    (binaryfunc)Record_tp_as_mapping_getitem,
+    Record_tp_as_mapping_length,
+    Record_tp_as_mapping_getitem,
     (objobjargproc)0 /* Record_tp_as_mapping_setitem */
 };
 
