--- glom/libglom/python_embed/py_glom_record.cc.orig	Sun Jul 15 13:34:18 2007
+++ glom/libglom/python_embed/py_glom_record.cc	Sun Jul 15 13:34:44 2007
@@ -122,7 +122,7 @@
 
 
 
-static int
+static Py_ssize_t
 Record_tp_as_mapping_length(PyGlomRecord *self)
 {
   return self->m_pMap_field_values->size();
@@ -146,7 +146,7 @@
         }
         else
         {
-          g_warning("Record_tp_as_mapping_getitem(): item not found in m_pMap_field_values. size=%d, item=%s", self->m_pMap_field_values->size(), pchKey);
+          g_warning("Record_tp_as_mapping_getitem(): item not found in m_pMap_field_values. size=%d, item=%s", (int)self->m_pMap_field_values->size(), pchKey);
         }
       }
       else
