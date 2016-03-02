--- src/MainEditor/UI/EntryPanel/AudioEntryPanel.h.orig	2015-12-12 08:41:35 UTC
+++ src/MainEditor/UI/EntryPanel/AudioEntryPanel.h
@@ -27,7 +27,9 @@ private:
 	wxSlider*		slider_seek;
 	wxSlider*		slider_volume;
 	wxTimer*		timer_seek;
+#if wxUSE_MEDIACTRL
 	wxMediaCtrl*	media_ctrl;
+#endif
 	wxStaticText*	txt_title;
 	wxStaticText*	txt_track;
 	wxTextCtrl*		txt_info;
