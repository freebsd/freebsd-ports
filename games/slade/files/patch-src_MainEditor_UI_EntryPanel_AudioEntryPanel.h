--- src/MainEditor/UI/EntryPanel/AudioEntryPanel.h.orig	2018-11-25 00:21:04 UTC
+++ src/MainEditor/UI/EntryPanel/AudioEntryPanel.h
@@ -46,7 +46,9 @@ class AudioEntryPanel : public EntryPanel (private)
 	wxSlider*		slider_seek_	= nullptr;
 	wxSlider*		slider_volume_	= nullptr;
 	wxTimer*		timer_seek_		= nullptr;
+#if wxUSE_MEDIACTRL
 	wxMediaCtrl*	media_ctrl_		= nullptr;
+#endif
 	wxStaticText*	txt_title_		= nullptr;
 	wxStaticText*	txt_track_		= nullptr;
 	wxTextCtrl*		txt_info_		= nullptr;
