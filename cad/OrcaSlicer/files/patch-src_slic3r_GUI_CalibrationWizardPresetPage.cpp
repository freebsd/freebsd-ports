--- src/slic3r/GUI/CalibrationWizardPresetPage.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/CalibrationWizardPresetPage.cpp
@@ -766,7 +766,8 @@ void CalibrationPresetPage::create_page(wxWindow* pare
     m_top_sizer->Add(m_selection_panel, 0);
     m_top_sizer->Add(m_filament_list_panel, 0);
     m_top_sizer->Add(m_ext_spool_panel, 0);
-    m_top_sizer->Add(m_pa_cali_method_combox, 0);
+    if (m_pa_cali_method_combox)
+        m_top_sizer->Add(m_pa_cali_method_combox, 0);
     m_top_sizer->Add(m_custom_range_panel, 0);
     m_top_sizer->AddSpacer(FromDIP(15));
     m_top_sizer->Add(m_warning_panel, 0);
