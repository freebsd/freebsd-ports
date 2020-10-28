--- modules/javafx.media/src/main/native/jfxmedia/platform/gstreamer/GstAudioSpectrum.cpp	2020-07-17 20:51:26 UTC
+++ modules/javafx.media/src/main/native/jfxmedia/platform/gstreamer/GstAudioSpectrum.cpp
@@ -95,7 +95,7 @@ void CGstAudioSpectrum::SetBands(int bands, CBandsHold
     g_object_set(m_pSpectrum, "bands", bands, NULL);
 
     CBandsHolder *old_holder = (CBandsHolder*)g_atomic_pointer_get(&m_pHolder);
-    g_atomic_pointer_compare_and_exchange((gpointer*)&m_pHolder, old_holder, holder);
+    g_atomic_pointer_compare_and_exchange((CBandsHolder**)&m_pHolder, old_holder, holder);
     CBandsHolder::ReleaseRef(old_holder);
 }
 
