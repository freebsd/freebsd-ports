--- DatabaseExplorer/SqliteDbAdapter.cpp.orig	2020-08-28 17:30:30 UTC
+++ DatabaseExplorer/SqliteDbAdapter.cpp
@@ -122,7 +122,7 @@ bool SQLiteDbAdapter::GetColumns(Table* pTab) {
 	int i = 0;
 	DatabaseLayerPtr dbLayer = this->GetDatabaseLayer(wxT(""));
 	if (dbLayer) {
-		if (!dbLayer->IsOpen()) return NULL;
+		if (!dbLayer->IsOpen()) return false;
 		// loading columns
 		//TODO:SQL:
 		DatabaseResultSet *database = dbLayer->RunQueryWithResults(wxString::Format(wxT("PRAGMA table_info('%s')"),pTab->GetName().c_str()));
