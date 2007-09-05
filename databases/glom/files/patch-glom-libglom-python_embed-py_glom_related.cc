--- glom/libglom/python_embed/py_glom_related.cc.orig	2006-05-20 06:35:32.000000000 -0500
+++ glom/libglom/python_embed/py_glom_related.cc	2007-09-05 00:42:52.657306150 -0500
@@ -52,62 +52,79 @@
 
 //Set the object's member data, from the parameters supplied when creating the object:
 static int
-Related_init(PyGlomRelated *self, PyObject* /* args */, PyObject* /* kwds */)
+Related_init(PyObject *self, PyObject* /* args */, PyObject* /* kwds */)
 {
-  if(self)
+  PyGlomRelated *self_related = (PyGlomRelated*)self;
+
+  if(self_related)
   {
-    self->m_record = 0;
+    self_related->m_record = 0;
 
-    if(self->m_pMap_relationships == 0)
-      self->m_pMap_relationships = new PyGlomRelated::type_map_relationships();
+    if(self_related->m_pMap_relationships == 0)
+      self_related->m_pMap_relationships = new PyGlomRelated::type_map_relationships();
 
-    if(self->m_pMap_relatedrecords == 0)
-      self->m_pMap_relatedrecords = new PyGlomRelated::type_map_relatedrecords();
+    if(self_related->m_pMap_relatedrecords == 0)
+      self_related->m_pMap_relatedrecords = new PyGlomRelated::type_map_relatedrecords();
   }
 
   return 0;
 }
 
 static void
-Related_dealloc(PyGlomRelated* self)
+Related_dealloc(PyObject* self)
 {
-  if(self->m_pMap_relationships)
+  PyGlomRelated *self_related = (PyGlomRelated*)self;
+
+  if(self_related->m_pMap_relationships)
   {
-    delete self->m_pMap_relationships;
-    self->m_pMap_relationships = 0;
+    delete self_related->m_pMap_relationships;
+    self_related->m_pMap_relationships = 0;
   }
 
-  if(self->m_record)
+  if(self_related->m_record)
   {
-    Py_XDECREF( (PyObject*)self->m_record );
-    self->m_record = 0;
+    Py_XDECREF( (PyObject*)self_related->m_record );
+    self_related->m_record = 0;
   }
 
-  if(self->m_pMap_relatedrecords)
+  if(self_related->m_pMap_relatedrecords)
   {
     //Unref each item:
-    for(PyGlomRelated::type_map_relatedrecords::iterator iter = self->m_pMap_relatedrecords->begin(); iter != self->m_pMap_relatedrecords->end(); ++iter)
+    for(PyGlomRelated::type_map_relatedrecords::iterator iter = self_related->m_pMap_relatedrecords->begin(); iter != self_related->m_pMap_relatedrecords->end(); ++iter)
     {
       Py_XDECREF( (PyObject*)(iter->second) );
     }
 
-    delete self->m_pMap_relatedrecords;
-    self->m_pMap_relatedrecords = 0;
+    delete self_related->m_pMap_relatedrecords;
+    self_related->m_pMap_relatedrecords = 0;
   }
 
-  self->ob_type->tp_free((PyObject*)self);
+  self_related->ob_type->tp_free((PyObject*)self);
 }
 
 
+//Adapt to API changes in Python 2.5:
+#if defined(PY_VERSION_HEX) && (PY_VERSION_HEX >= 0x02050000) /* Python 2.5 */
+static Py_ssize_t
+Related_tp_as_mapping_length(PyObject *self)
+{
+  PyGlomRelated *self_related = (PyGlomRelated*)self;
+  return self_related->m_pMap_relationships->size();
+}
+#else
 static int
-Related_tp_as_mapping_length(PyGlomRelated *self)
+Related_tp_as_mapping_length(PyObject *self)
 {
-  return self->m_pMap_relationships->size();
+  PyGlomRelated *self_related = (PyGlomRelated*)self;
+  return self_related->m_pMap_relationships->size();
 }
+#endif
 
 static PyObject *
-Related_tp_as_mapping_getitem(PyGlomRelated *self, PyObject *item)
+Related_tp_as_mapping_getitem(PyObject *self, PyObject *item)
 {
+  PyGlomRelated *self_related = (PyGlomRelated*)self;
+
   if(PyString_Check(item))
   {
     const char* pchKey = PyString_AsString(item);
@@ -116,8 +133,8 @@
       const Glib::ustring key(pchKey);
 
       //Return a cached item if possible:
-      PyGlomRelated::type_map_relatedrecords::iterator iterCacheFind = self->m_pMap_relatedrecords->find(key);
-      if(iterCacheFind != self->m_pMap_relatedrecords->end())
+      PyGlomRelated::type_map_relatedrecords::iterator iterCacheFind = self_related->m_pMap_relatedrecords->find(key);
+      if(iterCacheFind != self_related->m_pMap_relatedrecords->end())
       {
         //Return a reference to the cached item:
         PyGlomRelatedRecord* pyRelatedRecord = iterCacheFind->second;
@@ -127,8 +144,8 @@
       else
       {
         //If the relationship exists:
-        PyGlomRelated::type_map_relationships::const_iterator iterFind = self->m_pMap_relationships->find(key);
-        if(iterFind != self->m_pMap_relationships->end())
+        PyGlomRelated::type_map_relationships::const_iterator iterFind = self_related->m_pMap_relationships->find(key);
+        if(iterFind != self_related->m_pMap_relationships->end())
         {
           //Return a new RelatedRecord:
           PyObject* new_args = PyTuple_New(0);
@@ -140,15 +157,15 @@
           //Get the value of the from_key in the parent record.
           sharedptr<Relationship> relationship = iterFind->second;
           const Glib::ustring from_key = relationship->get_from_field();
-          PyGlomRecord::type_map_field_values::const_iterator iterFromKey = self->m_record->m_pMap_field_values->find(from_key);
-          if(iterFromKey != self->m_record->m_pMap_field_values->end())
+          PyGlomRecord::type_map_field_values::const_iterator iterFromKey = self_related->m_record->m_pMap_field_values->find(from_key);
+          if(iterFromKey != self_related->m_record->m_pMap_field_values->end())
           {
             const Gnome::Gda::Value from_key_value = iterFromKey->second;
 
             //TODO_Performance:
             //Get the full field details so we can sqlize its value:
             sharedptr<Field> from_key_field;
-            from_key_field = self->m_record->m_document->get_field(*(self->m_record->m_table_name), from_key);
+            from_key_field = self_related->m_record->m_document->get_field(*(self_related->m_record->m_table_name), from_key);
             if(from_key_field)
             {
               Glib::ustring key_value_sqlized;
@@ -157,11 +174,11 @@
               if(!GlomConversions::value_is_empty(from_key_value)) //Do not link on null-values. That would cause us to link on 0, or "0".
                 key_value_sqlized = from_key_field->sql(from_key_value);
 
-              PyGlomRelatedRecord_SetRelationship(pyRelatedRecord, iterFind->second, key_value_sqlized, self->m_record->m_document);
+              PyGlomRelatedRecord_SetRelationship(pyRelatedRecord, iterFind->second, key_value_sqlized, self_related->m_record->m_document);
 
               //Store it in the cache:
               Py_INCREF((PyObject*)pyRelatedRecord); //Dereferenced in _dealloc().
-              (*(self->m_pMap_relatedrecords))[key] = pyRelatedRecord;
+              (*(self_related->m_pMap_relatedrecords))[key] = pyRelatedRecord;
 
               return (PyObject*)pyRelatedRecord; //TODO: pygda_value_as_pyobject(iterFind->second.gobj(), true /* copy */);
             }
@@ -185,8 +202,8 @@
 */
 
 static PyMappingMethods Related_tp_as_mapping = {
-    (inquiry)Related_tp_as_mapping_length,
-    (binaryfunc)Related_tp_as_mapping_getitem,
+    Related_tp_as_mapping_length,
+    Related_tp_as_mapping_getitem,
     (objobjargproc)0 /* Related_tp_as_mapping_setitem */
 };
 
