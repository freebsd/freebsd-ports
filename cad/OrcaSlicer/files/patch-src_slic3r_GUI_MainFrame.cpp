--- src/slic3r/GUI/MainFrame.cpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/MainFrame.cpp
@@ -117,12 +117,13 @@ class ResizeEdgePanel : public wxPanel (public)
     static constexpr int BORDER_PX = 5;
 
     ResizeEdgePanel(MainFrame* frame, Edge edge)
-        : wxPanel(frame, wxID_ANY, wxDefaultPosition, wxDefaultSize,
-                  wxBORDER_NONE | wxTRANSPARENT_WINDOW)
+        : wxPanel()
         , m_frame(frame)
         , m_edge(edge)
     {
         SetBackgroundStyle(wxBG_STYLE_TRANSPARENT);
+        Create(frame, wxID_ANY, wxDefaultPosition, wxDefaultSize,
+               wxBORDER_NONE | wxTRANSPARENT_WINDOW);
         Bind(wxEVT_MOTION,       &ResizeEdgePanel::OnCursorUpdate, this);
         Bind(wxEVT_ENTER_WINDOW, &ResizeEdgePanel::OnCursorUpdate, this);
         Bind(wxEVT_LEFT_DOWN,    &ResizeEdgePanel::OnLeftDown,     this);
