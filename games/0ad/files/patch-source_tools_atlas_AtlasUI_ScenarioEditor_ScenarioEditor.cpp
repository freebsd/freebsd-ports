--- source/tools/atlas/AtlasUI/ScenarioEditor/ScenarioEditor.cpp.orig	2018-03-13 20:20:45 UTC
+++ source/tools/atlas/AtlasUI/ScenarioEditor/ScenarioEditor.cpp
@@ -723,7 +723,7 @@ bool ScenarioEditor::OpenFile(const wxString& name, co
 	wxBusyInfo busy(_("Loading ") + name);
 	wxBusyCursor busyc;
 
-	AtlasMessage::qVFSFileExists qry(filename.wc_str());
+	AtlasMessage::qVFSFileExists qry(filename.ToStdWstring());
 	qry.Post();
 	if (!qry.exists)
 		return false;
@@ -733,7 +733,7 @@ bool ScenarioEditor::OpenFile(const wxString& name, co
 	m_ToolManager.SetCurrentTool(_T(""));
 	// TODO: clear the undo buffer, etc
 
-	std::wstring map(filename.wc_str());
+	std::wstring map(filename.ToStdWstring());
 	POST_MESSAGE(LoadMap, (map));
 
 	SetOpenFilename(name);
@@ -786,7 +786,7 @@ void ScenarioEditor::OnImportHeightmap(wxCommandEvent&
 
 	OpenFile(_T(""), _T("maps/scenarios/_default.xml"));
 
-	std::wstring image(dlg.GetPath().wc_str());
+	std::wstring image(dlg.GetPath().ToStdWstring());
 	POST_MESSAGE(ImportHeightmap, (image));
 
 	// TODO: Make this a non-undoable command
@@ -830,7 +830,7 @@ void ScenarioEditor::OnSave(wxCommandEvent& event)
 		// the preview units.)
 		m_ToolManager.SetCurrentTool(_T(""));
 
-		std::wstring map(m_OpenFilename.wc_str());
+		std::wstring map(m_OpenFilename.ToStdWstring());
 		POST_MESSAGE(SaveMap, (map));
 
 		// Wait for it to finish saving
@@ -852,7 +852,7 @@ void ScenarioEditor::OnSaveAs(wxCommandEvent& WXUNUSED
 
 		m_ToolManager.SetCurrentTool(_T(""));
 
-		std::wstring map(filePath.wc_str());
+		std::wstring map(filePath.ToStdWstring());
 		POST_MESSAGE(SaveMap, (map));
 
 		SetOpenFilename(filePath);
@@ -920,7 +920,7 @@ void ScenarioEditor::OnJavaScript(wxCommandEvent& WXUN
 	wxString cmd = ::wxGetTextFromUser(_T(""), _("JS command"), _T(""), this);
 	if (cmd.IsEmpty())
 		return;
-	POST_MESSAGE(JavaScript, ((std::wstring)cmd.wc_str()));
+	POST_MESSAGE(JavaScript, ((std::wstring)cmd.ToStdWstring()));
 }
 
 void ScenarioEditor::OnCameraReset(wxCommandEvent& WXUNUSED(event))
