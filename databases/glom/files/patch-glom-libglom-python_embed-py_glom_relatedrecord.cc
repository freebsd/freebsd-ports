--- glom/libglom/python_embed/py_glom_relatedrecord.cc.orig	2006-05-20 06:35:36.000000000 -0500
+++ glom/libglom/python_embed/py_glom_relatedrecord.cc	2007-09-05 01:02:13.606806043 -0500
@@ -137,11 +137,22 @@
 */
 
 
+//Adapt to API changes in Python 2.5:
+#if defined(PY_VERSION_HEX) && (PY_VERSION_HEX >= 0x02050000) /* Python 2.5+ */
+static Py_ssize_t
+RelatedRecord_tp_as_mapping_length(PyObject *self)
+{
+  PyGlomRelatedRecord* self_derived = (PyGlomRelatedRecord*)self;
+  return self_derived->m_pMap_field_values->size();
+}
+#else
 static int
-RelatedRecord_tp_as_mapping_length(PyGlomRelatedRecord *self)
+RelatedRecord_tp_as_mapping_length(PyObject *self)
 {
-  return self->m_pMap_field_values->size();
+  PyGlomRelatedRecord* self_derived = (PyGlomRelatedRecord*)self;
+  return (int)(self_derived->m_pMap_field_values->size());
 }
+#endif
 
 static void RelatedRecord_HandlePythonError()
 {
@@ -150,29 +161,31 @@
 }
 
 static PyObject *
-RelatedRecord_tp_as_mapping_getitem(PyGlomRelatedRecord *self, PyObject *item)
+RelatedRecord_tp_as_mapping_getitem(PyObject *self, PyObject *item)
 {
+  PyGlomRelatedRecord* self_derived = (PyGlomRelatedRecord*)self;
+
   if(PyString_Check(item))
   {
     const char* pchKey = PyString_AsString(item);
     if(pchKey)
     {
       const Glib::ustring field_name(pchKey);
-      PyGlomRelatedRecord::type_map_field_values::const_iterator iterFind = self->m_pMap_field_values->find(field_name);
-      if(iterFind != self->m_pMap_field_values->end())
+      PyGlomRelatedRecord::type_map_field_values::const_iterator iterFind = self_derived->m_pMap_field_values->find(field_name);
+      if(iterFind != self_derived->m_pMap_field_values->end())
       {
         //If the value has already been stored, then just return it again:
         return pygda_value_as_pyobject(iterFind->second.gobj(), true /* copy */);
       }
       else
       {
-         const Glib::ustring related_table = (*(self->m_relationship))->get_to_table();
+         const Glib::ustring related_table = (*(self_derived->m_relationship))->get_to_table();
 
         //Check whether the field exists in the table.
         //TODO_Performance: Do this without the useless Field information?
-        sharedptr<Field> field  = self->m_document->get_field((*(self->m_relationship))->get_to_table(), field_name);
+        sharedptr<Field> field  = self_derived->m_document->get_field((*(self_derived->m_relationship))->get_to_table(), field_name);
         if(!field)
-          g_warning("RelatedRecord_tp_as_mapping_getitem: field %s not found in table %s", field_name.c_str(), (*(self->m_relationship))->get_to_table().c_str());
+          g_warning("RelatedRecord_tp_as_mapping_getitem: field %s not found in table %s", field_name.c_str(), (*(self_derived->m_relationship))->get_to_table().c_str());
         else
         {
           //Try to get the value from the database:
@@ -182,15 +195,15 @@
           {
             Glib::RefPtr<Gnome::Gda::Connection> gda_connection = sharedconnection->get_gda_connection();
 
-            const Glib::ustring related_key_name = (*(self->m_relationship))->get_to_field();
+            const Glib::ustring related_key_name = (*(self_derived->m_relationship))->get_to_field();
 
             //Do not try to get a value based on a null key value:
-            if(!(self->m_from_key_value_sqlized))
+            if(!(self_derived->m_from_key_value_sqlized))
               return Py_None;
        
             //Get the single value from the related records:
             Glib::ustring sql_query = "SELECT \"" + related_table + "\".\"" + field_name + "\" FROM \"" + related_table + "\""
-              + " WHERE \"" + related_table + "\".\"" + related_key_name + "\" = " + *(self->m_from_key_value_sqlized);
+              + " WHERE \"" + related_table + "\".\"" + related_key_name + "\" = " + *(self_derived->m_from_key_value_sqlized);
 
             //std::cout << "PyGlomRelatedRecord: Executing:  " << sql_query << std::endl;
             Glib::RefPtr<Gnome::Gda::DataModel> datamodel = gda_connection->execute_single_command(sql_query);
@@ -200,7 +213,7 @@
               //g_warning("RelatedRecord_tp_as_mapping_getitem(): value from datamodel = %s", value.to_string().c_str());
 
               //Cache it, in case it's asked-for again.
-              (*(self->m_pMap_field_values))[field_name] = value;
+              (*(self_derived->m_pMap_field_values))[field_name] = value;
               return pygda_value_as_pyobject(value.gobj(), true /* copy */);
             }
             else if(!datamodel)
@@ -211,7 +224,7 @@
             }
             else
             {
-              g_warning("RelatedRecord_tp_as_mapping_getitem(): No related records exist yet for relationship %s.",  (*(self->m_relationship))->get_name().c_str());
+              g_warning("RelatedRecord_tp_as_mapping_getitem(): No related records exist yet for relationship %s.",  (*(self_derived->m_relationship))->get_name().c_str());
             }
           }
         }
@@ -234,8 +247,8 @@
 */
 
 static PyMappingMethods RelatedRecord_tp_as_mapping = {
-    (inquiry)RelatedRecord_tp_as_mapping_length,
-    (binaryfunc)RelatedRecord_tp_as_mapping_getitem,
+    RelatedRecord_tp_as_mapping_length,
+    RelatedRecord_tp_as_mapping_getitem,
     (objobjargproc)0 /* RelatedRecord_tp_as_mapping_setitem */
 };
 
@@ -311,27 +324,31 @@
 }
 
 static PyObject *
-RelatedRecord_sum(PyGlomRelatedRecord* self, PyObject *args, PyObject *kwargs)
+RelatedRecord_sum(PyObject* self, PyObject *args, PyObject *kwargs)
 {
-  return RelatedRecord_generic_aggregate(self, args, kwargs, "sum");
+  PyGlomRelatedRecord* self_derived = (PyGlomRelatedRecord*)self;
+  return RelatedRecord_generic_aggregate(self_derived, args, kwargs, "sum");
 }
 
 static PyObject *
-RelatedRecord_count(PyGlomRelatedRecord* self, PyObject *args, PyObject *kwargs)
+RelatedRecord_count(PyObject* self, PyObject *args, PyObject *kwargs)
 {
-  return RelatedRecord_generic_aggregate(self, args, kwargs, "count");
+  PyGlomRelatedRecord* self_derived = (PyGlomRelatedRecord*)self;
+  return RelatedRecord_generic_aggregate(self_derived, args, kwargs, "count");
 }
 
 static PyObject *
-RelatedRecord_min(PyGlomRelatedRecord* self, PyObject *args, PyObject *kwargs)
+RelatedRecord_min(PyObject* self, PyObject *args, PyObject *kwargs)
 {
-  return RelatedRecord_generic_aggregate(self, args, kwargs, "min");
+  PyGlomRelatedRecord* self_derived = (PyGlomRelatedRecord*)self;
+  return RelatedRecord_generic_aggregate(self_derived, args, kwargs, "min");
 }
 
 static PyObject *
-RelatedRecord_max(PyGlomRelatedRecord* self, PyObject *args, PyObject *kwargs)
+RelatedRecord_max(PyObject* self, PyObject *args, PyObject *kwargs)
 {
-  return RelatedRecord_generic_aggregate(self, args, kwargs, "max");
+  PyGlomRelatedRecord* self_derived = (PyGlomRelatedRecord*)self;
+  return RelatedRecord_generic_aggregate(self_derived, args, kwargs, "max");
 }
 
 static PyMethodDef RelatedRecord_methods[] = {
