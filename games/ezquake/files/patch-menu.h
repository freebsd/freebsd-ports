--- ./menu.h.orig	Thu Apr  6 13:47:34 2006
+++ ./menu.h	Tue Aug 29 21:09:39 2006
@@ -34,7 +34,7 @@
     m_none, m_main, m_singleplayer, m_load, m_save, m_multiplayer,
     m_setup, m_options, m_video, m_keys, m_help, m_quit,
     m_gameoptions, m_slist,/* m_sedit,*/ m_fps, m_demos, m_demos_del
-#if defined(_WIN32) || (defined(__linux__) && defined(WITH_XMMS))
+#if defined(_WIN32) || (defined(__unix__) && defined(WITH_XMMS))
     , m_mp3_control, m_mp3_playlist
 #endif
 } m_state;
