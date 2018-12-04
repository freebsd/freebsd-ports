--- src/panoframe.cpp.orig	2008-07-23 21:09:11 UTC
+++ src/panoframe.cpp
@@ -136,7 +136,13 @@ PCX files (*.pcx)|*.pcx|\
 PNM files (*.pnm)|*.pnm|\
 TIFF files (*.tif)|*.tif|\
 XPM files (*.xpm)|*.xpm|\
-All files (*.*)|*.*"),wxOPEN|wxFILE_MUST_EXIST);
+All files (*.*)|*.*"),
+#if wxCHECK_VERSION(3,0,0)
+    wxFD_OPEN|wxFD_FILE_MUST_EXIST
+#else //wxCHECK_VERSION(3,0,0)
+    wxOPEN|wxFILE_MUST_EXIST
+#endif //wxCHECK_VERSION(3,0,0)
+  );
   if (imagename !=wxT(""))
     openImage(imagename);
 }
@@ -153,7 +159,13 @@ void panoFrame::OnFullScreen(wxCommandEvent &event)
 
 void panoFrame::OnOpenProject(wxCommandEvent &event)
 {
-  wxString filename = wxFileSelector(_("Open Project"),wxEmptyString,wxEmptyString,wxT("paf"),_("Panorama files (*.paf)|*.paf|All files (*.*)|*.*"),wxOPEN|wxFILE_MUST_EXIST);
+  wxString filename = wxFileSelector(_("Open Project"),wxEmptyString,wxEmptyString,wxT("paf"),_("Panorama files (*.paf)|*.paf|All files (*.*)|*.*"),
+#if wxCHECK_VERSION(3,0,0)
+    wxFD_OPEN|wxFD_FILE_MUST_EXIST
+#else //wxCHECK_VERSION(3,0,0)
+    wxOPEN|wxFILE_MUST_EXIST
+#endif //wxCHECK_VERSION(3,0,0)
+  );
   if (filename !=wxT("")){
     openProject(filename);
   }
@@ -292,7 +304,13 @@ void panoFrame::openArgumentFile(const wxString &filen
 
 void panoFrame::OnSaveProject(wxCommandEvent &event)
 {
-  wxString filename = wxFileSelector(_("Save Project"),wxEmptyString,wxEmptyString,wxT("paf"),_("Panorama files (*.paf)|*.paf|All files (*.*)|*.*"),wxOVERWRITE_PROMPT|wxSAVE);
+  wxString filename = wxFileSelector(_("Save Project"),wxEmptyString,wxEmptyString,wxT("paf"),_("Panorama files (*.paf)|*.paf|All files (*.*)|*.*"),
+#if wxCHECK_VERSION(3,0,0)
+    wxFD_OPEN|wxFD_FILE_MUST_EXIST
+#else //wxCHECK_VERSION(3,0,0)
+    wxOPEN|wxFILE_MUST_EXIST
+#endif //wxCHECK_VERSION(3,0,0)
+  );
   if (filename != wxT("")){
     if (wxFileExists(filename))
       wxRemoveFile(filename);
