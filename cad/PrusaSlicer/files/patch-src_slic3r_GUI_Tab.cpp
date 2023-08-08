--- src/slic3r/GUI/Tab.cpp.orig	2023-07-23 21:37:19 UTC
+++ src/slic3r/GUI/Tab.cpp
@@ -243,7 +243,7 @@ void Tab::create_preset_tab()
     m_h_buttons_sizer->AddSpacer(int(8*scale_factor));
     m_h_buttons_sizer->Add(m_btn_compare_preset, 0, wxALIGN_CENTER_VERTICAL);
 
-    m_top_hsizer->Add(m_h_buttons_sizer, 1, wxEXPAND | wxALIGN_CENTRE_VERTICAL);
+    m_top_hsizer->Add(m_h_buttons_sizer, 1, wxEXPAND);
     m_top_hsizer->AddSpacer(int(16*scale_factor));
     // StretchSpacer has a strange behavior under OSX, so
     // There is used just additional sizer for m_mode_sizer with right alignment
@@ -252,7 +252,7 @@ void Tab::create_preset_tab()
         // Don't set the 2nd parameter to 1, making the sizer rubbery scalable in Y axis may lead 
         // to wrong vertical size assigned to wxBitmapComboBoxes, see GH issue #7176.
         mode_sizer->Add(m_mode_sizer, 0, wxALIGN_RIGHT);
-        m_top_hsizer->Add(mode_sizer, 1, wxALIGN_CENTER_VERTICAL | wxRIGHT, wxOSX ? 15 : 10);
+        m_top_hsizer->Add(mode_sizer, 1, wxRIGHT, wxOSX ? 15 : 10);
     }
     // hide whole top sizer to correct layout later
     m_top_hsizer->ShowItems(false);
@@ -280,7 +280,7 @@ void Tab::create_preset_tab()
     // This helps to process all the cursor key events on Windows in the tree control,
     // so that the cursor jumps to the last item.
     m_treectrl->Bind(wxEVT_TREE_SEL_CHANGED, [this](wxTreeEvent&) {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         // Events queue is opposite On Linux. wxEVT_SET_FOCUS invokes after wxEVT_TREE_SEL_CHANGED,
         // and a result wxEVT_KILL_FOCUS doesn't invoke for the TextCtrls.
         // see https://github.com/prusa3d/PrusaSlicer/issues/5720
@@ -3427,7 +3427,7 @@ void Tab::load_current_preset()
                         else
 #endif
                             wxGetApp().tab_panel()->InsertPage(wxGetApp().tab_panel()->FindPage(this), tab, tab->title());
-                        #ifdef __linux__ // the tabs apparently need to be explicitly shown on Linux (pull request #1563)
+                        #if defined(__linux__) || defined(__FreeBSD__) // the tabs apparently need to be explicitly shown on Linux (pull request #1563)
                             int page_id = wxGetApp().tab_panel()->FindPage(tab);
                             wxGetApp().tab_panel()->GetPage(page_id)->Show(true);
                         #endif // __linux__
@@ -3837,7 +3837,7 @@ bool Tab::tree_sel_change_delayed()
     // There is a bug related to Ubuntu overlay scrollbars, see https://github.com/prusa3d/PrusaSlicer/issues/898 and https://github.com/prusa3d/PrusaSlicer/issues/952.
     // The issue apparently manifests when Show()ing a window with overlay scrollbars while the UI is frozen. For this reason,
     // we will Thaw the UI prematurely on Linux. This means destroing the no_updates object prematurely.
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     std::unique_ptr<wxWindowUpdateLocker> no_updates(new wxWindowUpdateLocker(this));
 #else
     /* On Windows we use DoubleBuffering during rendering,
@@ -3883,7 +3883,7 @@ bool Tab::tree_sel_change_delayed()
         if (wxGetApp().mainframe!=nullptr && wxGetApp().mainframe->is_active_and_shown_tab(this))
             activate_selected_page(throw_if_canceled);
 
-        #ifdef __linux__
+        #if defined(__linux__) || defined(__FreeBSD__)
             no_updates.reset(nullptr);
         #endif
 
