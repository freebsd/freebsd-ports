--- src/slic3r/GUI/WipeTowerDialog.cpp.orig	2024-10-15 09:12:21 UTC
+++ src/slic3r/GUI/WipeTowerDialog.cpp
@@ -379,7 +379,7 @@ WipingPanel::WipingPanel(wxWindow* parent, const std::
                                               int xpos = m_gridsizer_advanced->GetPosition().x;
                                               if (!m_page_advanced->IsEnabled()) {
                                                   dc.SetTextForeground(wxSystemSettings::GetColour(
-#if defined (__linux__) && defined (__WXGTK2__)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined (__WXGTK2__)
                                                       wxSYS_COLOUR_BTNTEXT
 #else 
                                                       wxSYS_COLOUR_GRAYTEXT
