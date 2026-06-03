--- src/slic3r/GUI/CalibrationPanel.cpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/CalibrationPanel.cpp
@@ -666,7 +666,7 @@ void CalibrationPanel::on_printer_clicked(wxMouseEvent
         pos.y += m_side_tools->GetRect().height;
         m_mobjectlist_popup.Move(pos);
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         m_mobjectlist_popup.SetSize(wxSize(m_side_tools->GetSize().x, -1));
         m_mobjectlist_popup.SetMaxSize(wxSize(m_side_tools->GetSize().x, -1));
         m_mobjectlist_popup.SetMinSize(wxSize(m_side_tools->GetSize().x, -1));
