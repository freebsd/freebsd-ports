Fix crash when clicking on "Network and HDD Settings"

--- pcsx2/DEV9/ConfigUI.cpp.orig	2022-10-20 13:57:30 UTC
+++ pcsx2/DEV9/ConfigUI.cpp
@@ -366,7 +366,7 @@ class DEV9Dialog : public wxDialog (public)
 		m_eth_adapter->SetSelection(selection);
 		// Update minimum sizes for the possibly increased dropdown size
 		// Nothing else seems to update the minimum size of the window
-		SetSizerAndFit(GetSizer(), false);
+		// SetSizerAndFit(GetSizer(), false);
 	}
 
 	void OnCheck(wxCommandEvent&)
