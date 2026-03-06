--- src/slic3r/GUI/Monitor.cpp.orig	2025-03-01 00:00:00 UTC
+++ src/slic3r/GUI/Monitor.cpp
@@ -319,7 +319,7 @@
         //pos.x = pos.x < 0? 0:pos.x;
         m_select_machine.Move(pos);

-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         m_select_machine.SetSize(wxSize(m_side_tools->GetSize().x, -1));
         m_select_machine.SetMaxSize(wxSize(m_side_tools->GetSize().x, -1));
         m_select_machine.SetMinSize(wxSize(m_side_tools->GetSize().x, -1));
