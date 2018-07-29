--- src/WEDImportExport/WED_GatewayExport.cpp.orig	2018-07-07 14:06:35 UTC
+++ src/WEDImportExport/WED_GatewayExport.cpp
@@ -572,7 +572,7 @@ void WED_GatewayExportDialog::Submit()
 		vector<char> temp_chars(temp_folder.begin(),temp_folder.end());
 		temp_chars.push_back(0);
 
-		if(!mktemp(&temp_chars[0]))
+		if(!mkstemp(&temp_chars[0]))
 		{
 			gExportTarget = old_target;
 			return;
