--- DatabaseExplorer/MySqlDbAdapter.cpp.orig	2020-08-28 17:23:13 UTC
+++ DatabaseExplorer/MySqlDbAdapter.cpp
@@ -210,7 +210,7 @@ bool MySqlDbAdapter::GetColumns(Table* pTab)
 {
 	DatabaseLayerPtr dbLayer = this->GetDatabaseLayer(wxT(""));
 
-	if (!dbLayer->IsOpen()) return NULL;
+	if (!dbLayer->IsOpen()) return false;
 	// loading columns
 	//TODO:SQL:
 	DatabaseResultSet *database = dbLayer->RunQueryWithResults(wxString::Format(wxT("SHOW COLUMNS IN `%s`.`%s`"),pTab->GetParentName().c_str(),pTab->GetName().c_str()));
