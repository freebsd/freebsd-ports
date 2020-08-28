--- DatabaseExplorer/PostgreSqlDbAdapter.cpp.orig	2020-08-28 17:27:12 UTC
+++ DatabaseExplorer/PostgreSqlDbAdapter.cpp
@@ -307,7 +307,7 @@ bool PostgreSqlDbAdapter::GetColumns(Table* pTab) {
 //		SetDatabase(pTab->GetParentName());
 		DatabaseLayerPtr dbLayer = this->GetDatabaseLayer(pTab->GetParentName());
 
-		if (!dbLayer->IsOpen()) return NULL;
+		if (!dbLayer->IsOpen()) return false;
 		// loading columns
 		//TODO:SQL:
 		//DatabaseResultSet *database = dbLayer->RunQueryWithResults(wxString::Format(wxT("SHOW COLUMNS IN `%s`.`%s`"),pTab->getParentName().c_str(),pTab->getName().c_str()));
