--- src/slic3r/GUI/Monitor.cpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/Monitor.cpp
@@ -312,7 +312,7 @@ void MonitorPanel::on_printer_clicked(wxMouseEvent &ev
         //pos.x = pos.x < 0? 0:pos.x;
         m_select_machine.Move(pos);
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         m_select_machine.SetSize(wxSize(m_side_tools->GetSize().x, -1));
         m_select_machine.SetMaxSize(wxSize(m_side_tools->GetSize().x, -1));
         m_select_machine.SetMinSize(wxSize(m_side_tools->GetSize().x, -1));
