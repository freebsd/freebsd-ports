--- src/slic3r/GUI/CalibrationPanel.cpp.orig	2025-03-01 00:00:00 UTC
+++ src/slic3r/GUI/CalibrationPanel.cpp
@@ -680,7 +680,7 @@
         pos.y += m_side_tools->GetRect().height;
         m_mobjectlist_popup.Move(pos);

-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         m_mobjectlist_popup.SetSize(wxSize(m_side_tools->GetSize().x, -1));
         m_mobjectlist_popup.SetMaxSize(wxSize(m_side_tools->GetSize().x, -1));
         m_mobjectlist_popup.SetMinSize(wxSize(m_side_tools->GetSize().x, -1));
