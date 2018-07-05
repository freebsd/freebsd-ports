--- source/tools/atlas/AtlasUI/CustomControls/MapDialog/MapDialog.cpp.orig	2018-03-13 20:26:30 UTC
+++ source/tools/atlas/AtlasUI/CustomControls/MapDialog/MapDialog.cpp
@@ -166,11 +166,11 @@ void MapDialog::OnListBox(wxCommandEvent& evt)
 	else
 	{
 		wxString filePath = GetSelectedFilePath();
-		AtlasMessage::qVFSFileExists qry(filePath.wc_str());
+		AtlasMessage::qVFSFileExists qry(filePath.ToStdWstring());
 		qry.Post();
 		if (!filePath.IsEmpty() && qry.exists)
 		{
-			AtlasMessage::qVFSFileRealPath qry(filePath.wc_str());
+			AtlasMessage::qVFSFileRealPath qry(filePath.ToStdWstring());
 			qry.Post();
 			wxDynamicCast(FindWindow(ID_MapDialogFilename), wxTextCtrl)->ChangeValue(*qry.realPath);
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
