--- src/slic3r/GUI/Tab.cpp.orig	2024-06-27 09:25:47 UTC
+++ src/slic3r/GUI/Tab.cpp
@@ -278,7 +278,7 @@ void Tab::create_preset_tab()
     m_treectrl = new wxTreeCtrl(panel, wxID_ANY, wxDefaultPosition, wxSize(20 * m_em_unit, -1),
         wxTR_NO_BUTTONS | wxTR_HIDE_ROOT | wxTR_SINGLE | wxTR_NO_LINES | wxBORDER_SUNKEN | wxWANTS_CHARS);
     m_treectrl->SetFont(wxGetApp().normal_font());
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     m_treectrl->SetBackgroundColour(m_parent->GetBackgroundColour());
 #endif
     m_left_sizer->Add(m_treectrl, 1, wxEXPAND);
@@ -292,7 +292,7 @@ void Tab::create_preset_tab()
     // This helps to process all the cursor key events on Windows in the tree control,
     // so that the cursor jumps to the last item.
     m_treectrl->Bind(wxEVT_TREE_SEL_CHANGED, [this](wxTreeEvent&) {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         // Events queue is opposite On Linux. wxEVT_SET_FOCUS invokes after wxEVT_TREE_SEL_CHANGED,
         // and a result wxEVT_KILL_FOCUS doesn't invoke for the TextCtrls.
         // see https://github.com/prusa3d/PrusaSlicer/issues/5720
@@ -4106,7 +4106,7 @@ bool Tab::tree_sel_change_delayed()
     // There is a bug related to Ubuntu overlay scrollbars, see https://github.com/prusa3d/PrusaSlicer/issues/898 and https://github.com/prusa3d/PrusaSlicer/issues/952.
     // The issue apparently manifests when Show()ing a window with overlay scrollbars while the UI is frozen. For this reason,
     // we will Thaw the UI prematurely on Linux. This means destroing the no_updates object prematurely.
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     std::unique_ptr<wxWindowUpdateLocker> no_updates(new wxWindowUpdateLocker(this));
 #else
     /* On Windows we use DoubleBuffering during rendering,
@@ -4152,7 +4152,7 @@ bool Tab::tree_sel_change_delayed()
         if (wxGetApp().mainframe!=nullptr && wxGetApp().mainframe->is_active_and_shown_tab(this))
             activate_selected_page(throw_if_canceled);
 
-        #ifdef __linux__
+        #if defined(__linux__) || defined(__FreeBSD__)
             no_updates.reset(nullptr);
         #endif
 
