--- glom/frame_glom.cc.orig	2014-03-06 22:06:42.000000000 +0100
+++ glom/frame_glom.cc	2014-03-06 22:06:55.000000000 +0100
@@ -1583,7 +1583,7 @@
   //Get the fields information from the database:
   Base_DB::type_vec_fields fieldsDatabase = Base_DB::get_fields_for_table_from_database(m_table_name);
 
-  Document* pDoc = dynamic_cast<const Document*>(get_document());
+  Document* pDoc = dynamic_cast<Document*>(get_document());
   if(pDoc)
   {
     bool document_must_be_updated = false;
