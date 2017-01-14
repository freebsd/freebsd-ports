--- rtgui/soundman.cc.orig	2017-01-14 17:35:19 UTC
+++ rtgui/soundman.cc
@@ -24,9 +24,7 @@
 #ifdef WIN32
 #include <windows.h>
 #include <mmsystem.h>
-#endif
-
-#ifdef __linux__
+#elif !defined(__APPLE__)
 #include <canberra-gtk.h>
 #endif
 
@@ -65,7 +63,7 @@ void SoundManager::playSoundAsync(const 
     wchar_t *wfilename = (wchar_t*)g_utf8_to_utf16 (sound.c_str(), -1, NULL, NULL, NULL);
     PlaySoundW(wfilename, NULL, sndParam);
     g_free( wfilename );
-#elif defined(__linux__)
+#elif !defined(__APPLE__)
     ca_context_play(ca_gtk_context_get(), 0, CA_PROP_EVENT_ID, sound.c_str(), CA_PROP_MEDIA_FILENAME, sound.c_str(), NULL);
 #endif
 }
