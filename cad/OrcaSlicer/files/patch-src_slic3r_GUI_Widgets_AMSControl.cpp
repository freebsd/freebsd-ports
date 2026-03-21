--- src/slic3r/GUI/Widgets/AMSControl.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/Widgets/AMSControl.cpp
@@ -496,7 +496,7 @@ AMSControl::AMSControl(wxWindow *parent, wxWindowID id
     m_calibration_err_panel->SetBackgroundColour(AMS_CONTROL_WHITE_COLOUR);
     wxBoxSizer *sizer_err_calibration_h = new wxBoxSizer(wxHORIZONTAL);
     wxBoxSizer *sizer_err_calibration_v = new wxBoxSizer(wxVERTICAL);
-    m_hyperlink = new wxHyperlinkCtrl(m_calibration_err_panel, wxID_ANY, wxEmptyString, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE);
+    m_hyperlink = new wxHyperlinkCtrl(m_calibration_err_panel, wxID_ANY, " ", " ", wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE);
     m_hyperlink->SetVisitedColour(wxColour(31, 142, 234));
     auto m_tip_calibration_err = new wxStaticText(m_calibration_err_panel, wxID_ANY, _L("A problem occurred during calibration. Click to view the solution."), wxDefaultPosition,
                                                   wxDefaultSize, 0);
