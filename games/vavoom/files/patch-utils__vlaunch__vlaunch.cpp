--- utils/vlaunch/vlaunch.cpp.orig	2011-01-01 12:51:56.000000000 +0100
+++ utils/vlaunch/vlaunch.cpp	2012-12-24 00:17:28.000000000 +0100
@@ -145,7 +145,7 @@
 	wxNotebook* nbook = new wxNotebook(panel, -1, wxPoint(0, 105), wxSize(447, 270));
 	mainsizer->Add(nbook);
 
-	wxPanel* page = new wxPanel(nbook);
+	wxScrolledWindow* page = new wxScrolledWindow(nbook);
 	nbook->AddPage(page, wxT("Main"));
 	wxFlexGridSizer* gsizer = new wxFlexGridSizer(2);
 
@@ -185,12 +185,17 @@
 	gsizer->Add(EditMisc, 0, wxALL, 4);
 	page->SetSizer(gsizer);
 	gsizer->Layout();
+	gsizer->FitInside(page);
+	page->SetScrollRate(10, 10);
 
 	//	Video options
-	page = new wxPanel(nbook);
+	page = new wxScrolledWindow(nbook);
 	nbook->AddPage(page, wxT("Video"));
 	wxFlexGridSizer* vsizer = new wxFlexGridSizer(2);
 
+	vsizer->Add(new wxStaticText(page, -1, wxT(" ")), 0, wxALL, 4);
+	vsizer->Add(new wxStaticText(page, -1, wxT(" ")), 0, wxALL, 4);
+
 	vsizer->Add(new wxStaticText(page, -1, wxT("Renderer:")), 0, wxALL, 4);
 	wxString RendChoices[2];
 	RendChoices[0] = wxT("OpenGL");
@@ -237,9 +242,11 @@
 	vsizer->Add(Particles, 0, wxALL, 4);
 	page->SetSizer(vsizer);
 	vsizer->Layout();
+	vsizer->FitInside(page);
+	page->SetScrollRate(10, 10);
 
 	//	Sound options
-	page = new wxPanel(nbook);
+	page = new wxScrolledWindow(nbook);
 	nbook->AddPage(page, wxT("Sound"));
 	wxFlexGridSizer* ssizer = new wxFlexGridSizer(2);
 
@@ -272,9 +279,11 @@
 	ssizer->Add(PatchFiles, 0, wxALL, 4);
 	page->SetSizer(ssizer);
 	ssizer->Layout();
+	ssizer->FitInside(page);
+	page->SetScrollRate(10, 10);
 
 	//	Input options
-	page = new wxPanel(nbook);
+	page = new wxScrolledWindow(nbook);
 	nbook->AddPage(page, wxT("Input"));
 	wxFlexGridSizer* isizer = new wxFlexGridSizer(2);
 
@@ -297,9 +306,11 @@
 	isizer->Add(MouseY, 0, wxALL, 4);
 	page->SetSizer(isizer);
 	isizer->Layout();
+	isizer->FitInside(page);
+	page->SetScrollRate(10, 10);
 
 	//	Network options
-	page = new wxPanel(nbook);
+	page = new wxScrolledWindow(nbook);
 	nbook->AddPage(page, wxT("Network"));
 	gsizer = new wxFlexGridSizer(2);
 	gsizer->AddSpacer(1);
@@ -331,6 +342,8 @@
 	gsizer->Add(EditMasterIPAddress, 0, wxALL, 4);
 	page->SetSizer(gsizer);
 	gsizer->Layout();
+	gsizer->FitInside(page);
+	page->SetScrollRate(10, 10);
 
 	wxBoxSizer* bsizer = new wxBoxSizer(wxHORIZONTAL);
 	bsizer->Add(new wxButton(panel, VLaunch_Run, wxT("Run")), 0, wxALL, 4);
