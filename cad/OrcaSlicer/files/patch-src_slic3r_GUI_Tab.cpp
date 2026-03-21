--- src/slic3r/GUI/Tab.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/Tab.cpp
@@ -473,7 +473,7 @@ void Tab::create_preset_tab()
         m_tabctrl->SetItemBold(sel_item, false);
         });
     m_tabctrl->Bind(wxEVT_TAB_SEL_CHANGED, [this](wxCommandEvent& event) {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         // Events queue is opposite On Linux. wxEVT_SET_FOCUS invokes after wxEVT_TAB_SEL_CHANGED,
         // and a result wxEVT_KILL_FOCUS doesn't invoke for the TextCtrls.
         // So, call SetFocus explicitly for this control before changing of the selection
@@ -4925,7 +4925,7 @@ void Tab::load_current_preset()
                         else
 #endif
                             wxGetApp().tab_panel()->InsertPage(wxGetApp().tab_panel()->FindPage(this), tab, tab->title(), "");
-                        #ifdef __linux__ // the tabs apparently need to be explicitly shown on Linux (pull request #1563)
+                        #if defined(__linux__) || defined(__FreeBSD__) // the tabs apparently need to be explicitly shown on Linux (pull request #1563)
                             int page_id = wxGetApp().tab_panel()->FindPage(tab);
                             wxGetApp().tab_panel()->GetPage(page_id)->Show(true);
                         #endif // __linux__
@@ -5544,7 +5544,7 @@ bool Tab::tree_sel_change_delayed(wxCommandEvent& even
 {
     // The issue apparently manifests when Show()ing a window with overlay scrollbars while the UI is frozen. For this reason,
     // we will Thaw the UI prematurely on Linux. This means destroing the no_updates object prematurely.
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     std::unique_ptr<wxWindowUpdateLocker> no_updates(new wxWindowUpdateLocker(this));
 #else
     /* On Windows we use DoubleBuffering during rendering,
@@ -5639,7 +5639,7 @@ bool Tab::tree_sel_change_delayed(wxCommandEvent& even
         if (wxGetApp().mainframe!=nullptr && wxGetApp().mainframe->is_active_and_shown_tab(m_parent))
             activate_selected_page(throw_if_canceled);
 
-        #ifdef __linux__
+        #if defined(__linux__) || defined(__FreeBSD__)
             no_updates.reset(nullptr);
         #endif
 
