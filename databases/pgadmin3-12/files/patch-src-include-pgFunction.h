--- src/include/pgFunction.h.orig	Mon Dec 18 14:03:22 2006
+++ src/include/pgFunction.h	Mon Dec 18 14:03:33 2006
@@ -33,7 +33,7 @@
     int GetIcon() { return PGICON_FUNCTION; }
     void ShowTreeDetail(wxTreeCtrl *browser, frmMain *form=0, ctlListView *properties=0, ctlSQLBox *sqlPane=0);
     static pgObject *ReadObjects(pgCollection *collection, wxTreeCtrl *browser);
-    static pgFunction *pgFunction::AppendFunctions(pgObject *obj, pgSchema *schema, wxTreeCtrl *browser, const wxString &restriction);
+    static pgFunction *AppendFunctions(pgObject *obj, pgSchema *schema, wxTreeCtrl *browser, const wxString &restriction);
 
     wxString GetFullName() const {return GetName()+wxT("(")+GetArgTypes()+wxT(")"); }
     wxString GetArgTypeNames() const { return argTypeNames; }
