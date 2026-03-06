--- src/slic3r/GUI/Widgets/SideTools.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/Widgets/SideTools.cpp
@@ -326,7 +326,7 @@ SideTools::SideTools(wxWindow *parent, wxWindowID id, 
     wxBoxSizer* sizer_error_desc = new wxBoxSizer(wxHORIZONTAL);
     wxBoxSizer* sizer_extra_info = new wxBoxSizer(wxHORIZONTAL);
 
-    m_link_network_state = new wxHyperlinkCtrl(m_side_error_panel, wxID_ANY,_L("Check the status of current system services"),"",wxDefaultPosition,wxDefaultSize,wxALIGN_CENTER_HORIZONTAL | wxST_ELLIPSIZE_END);
+    m_link_network_state = new wxHyperlinkCtrl(m_side_error_panel, wxID_ANY,_L("Check the status of current system services"),"",wxDefaultPosition,wxDefaultSize,wxHL_DEFAULT_STYLE);
     m_link_network_state->SetMinSize(wxSize(FromDIP(220), -1));
     m_link_network_state->SetMaxSize(wxSize(FromDIP(220), -1));
     m_link_network_state->SetFont(::Label::Body_12);
