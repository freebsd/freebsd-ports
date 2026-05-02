commit e466dffadc797958fbebb18e553fdec0f51e2b28
Author: Seth Hillbrand <seth@kipro-pcb.com>
Date:   Sun Apr 26 15:42:16 2026 -0700

    Try to fix crash opening Pre-defined Sizes
    
    Potential cause is that Gtk events are still on the stack after we
    destroy the wxChoice
    
    Wrap the two ShowBoardSetupDialog calls in CallAfter so the dropdown
    event finishes unwinding before the toolbar is rebuilt.
    
    Fixes https://gitlab.com/kicad/code/kicad/-/issues/23708

diff --git pcbnew/edit_track_width.cpp pcbnew/edit_track_width.cpp
index 0f123e8771..07dd200232 100644
--- pcbnew/edit_track_width.cpp
+++ pcbnew/edit_track_width.cpp
@@ -162,7 +162,16 @@ void PCB_EDIT_FRAME::Tracks_and_Vias_Size_Event( wxCommandEvent& event )
         else if( ii == int( m_SelTrackWidthBox->GetCount() - 1 ) )
         {
             m_SelTrackWidthBox->SetSelection( GetDesignSettings().GetTrackWidthIndex() );
-            ShowBoardSetupDialog( _( "Pre-defined Sizes" ) );
+
+            // Best-guess fix for issue #23708 (crash on dialog OK reported on
+            // Flatpak/FreeBSD, not reproduced locally). Suspected cause is that
+            // ReCreateAuxiliaryToolbar(), run on dialog OK, destroys this very
+            // wxChoice while its EVT_CHOICE handler is still on the GTK signal
+            // stack. Defer the dialog so the handler unwinds first.
+            CallAfter( [this]()
+                       {
+                           ShowBoardSetupDialog( _( "Pre-defined Sizes" ) );
+                       } );
         }
         else
         {
@@ -186,7 +195,12 @@ void PCB_EDIT_FRAME::Tracks_and_Vias_Size_Event( wxCommandEvent& event )
         else if( ii == int( m_SelViaSizeBox->GetCount() - 1 ) )
         {
             m_SelViaSizeBox->SetSelection( GetDesignSettings().GetViaSizeIndex() );
-            ShowBoardSetupDialog( _( "Pre-defined Sizes" ) );
+
+            // See the matching comment in the track-width case above.
+            CallAfter( [this]()
+                       {
+                           ShowBoardSetupDialog( _( "Pre-defined Sizes" ) );
+                       } );
         }
         else
         {
