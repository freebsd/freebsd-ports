--- src/slic3r/GUI/wxMediaCtrl2.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/wxMediaCtrl2.cpp
@@ -10,8 +10,9 @@
 #include <shellapi.h>
 #endif
 
-#ifdef __LINUX__
+#if defined(__LINUX__) || defined(__FreeBSD__)
 #include "Printer/gstbambusrc.h"
+#endif
 #include <gst/gst.h> // main gstreamer header
 class WXDLLIMPEXP_MEDIA
     wxGStreamerMediaBackend : public wxMediaBackendCommonBase
@@ -19,7 +20,6 @@ class WXDLLIMPEXP_MEDIA (public)
 public:
     GstElement *m_playbin; // GStreamer media element
 };
-#endif
 
 wxDEFINE_EVENT(EVT_MEDIA_CTRL_STAT, wxCommandEvent);
 
@@ -40,7 +40,7 @@ wxMediaCtrl2::wxMediaCtrl2(wxWindow *parent)
     }
 #endif
     wxMediaCtrl::Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxMEDIACTRLPLAYERCONTROLS_NONE);
-#ifdef __LINUX__
+#if defined(__LINUX__) || defined(__FreeBSD__)
     /* Register only after we have created the wxMediaCtrl, since only then are we guaranteed to have fired up Gstreamer's plugin registry. */
     auto playbin = reinterpret_cast<wxGStreamerMediaBackend *>(m_imp)->m_playbin;
     g_object_set (G_OBJECT (playbin),
@@ -216,13 +216,13 @@ void wxMediaCtrl2::Stop()
     wxMediaCtrl::Stop();
 }
 
-#ifdef __LINUX__
+#if defined(__LINUX__) || defined(__FreeBSD__)
 extern "C" int gst_bambu_last_error;
 #endif
 
 int wxMediaCtrl2::GetLastError() const
 {
-#ifdef __LINUX__
+#if defined(__LINUX__) || defined(__FreeBSD__)
     return gst_bambu_last_error;
 #else
     return m_error;
@@ -231,7 +231,7 @@ wxSize wxMediaCtrl2::GetVideoSize() const
 
 wxSize wxMediaCtrl2::GetVideoSize() const
 {
-#ifdef __LINUX__
+#if defined(__LINUX__) || defined(__FreeBSD__)
     // Gstreamer doesn't give us a VideoSize until we're playing, which
     // confuses the MediaPlayCtrl into claiming that it is stuck
     // "Loading...".  Fake it out for now.
