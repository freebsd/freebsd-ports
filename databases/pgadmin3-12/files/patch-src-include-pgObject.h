--- src/include/pgObject.h.orig	Mon Dec 18 14:02:09 2006
+++ src/include/pgObject.h	Mon Dec 18 14:02:19 2006
@@ -223,7 +223,7 @@
     pgSchemaObject(pgSchema *newSchema, int newType, const wxString& newName = wxT("")) : pgDatabaseObject(newType, newName)
         { tableOid=0; SetSchema(newSchema); wxLogInfo(wxT("Creating a pg") + GetTypeName() + wxT(" object")); }
 
-    pgSchemaObject::~pgSchemaObject()
+    ~pgSchemaObject()
         { wxLogInfo(wxT("Destroying a pg") + GetTypeName() + wxT(" object")); }
 
     bool GetSystemObject() const;
