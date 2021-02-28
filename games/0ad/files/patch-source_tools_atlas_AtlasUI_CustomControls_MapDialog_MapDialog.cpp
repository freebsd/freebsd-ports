--- source/tools/atlas/AtlasUI/CustomControls/MapDialog/MapDialog.cpp.orig	2020-12-07 06:38:29 UTC
+++ source/tools/atlas/AtlasUI/CustomControls/MapDialog/MapDialog.cpp
@@ -166,11 +166,11 @@ void MapDialog::OnListBox(wxCommandEvent& evt)
 	else
 	{
 		wxString filePath = GetSelectedFilePath();
-		AtlasMessage::qVFSFileExists fileExistsQuery(filePath.wc_str());
+		AtlasMessage::qVFSFileExists fileExistsQuery(filePath.ToStdWstring());
 		fileExistsQuery.Post();
 		if (!filePath.IsEmpty() && fileExistsQuery.exists)
 		{
-			AtlasMessage::qVFSFileRealPath pathQuery(filePath.wc_str());
+			AtlasMessage::qVFSFileRealPath pathQuery(filePath.ToStdWstring());
 			pathQuery.Post();
 			wxDynamicCast(FindWindow(ID_MapDialogFilename), wxTextCtrl)->ChangeValue(*pathQuery.realPath);
 		}
@@ -221,7 +221,7 @@ void MapDialog::OpenFile()
 	if (filePath.empty())
 		return;
 
-	AtlasMessage::qVFSFileExists qry(filePath.wc_str());
+	AtlasMessage::qVFSFileExists qry(filePath.ToStdWstring());
 	qry.Post();
 	if (!qry.exists)
 		return;
@@ -236,7 +236,7 @@ void MapDialog::SaveFile()
 		return;
 
 	// TODO: this test would work better outside the VFS
-	AtlasMessage::qVFSFileExists qry(filePath.wc_str());
+	AtlasMessage::qVFSFileExists qry(filePath.ToStdWstring());
 	qry.Post();
 	if (qry.exists)
 	{
