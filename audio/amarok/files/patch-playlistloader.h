--- amarok/amarok/playlistloader.h.orig	Fri Mar  5 22:15:11 2004
+++ amarok/amarok/playlistloader.h	Mon Mar  8 15:36:51 2004
@@ -120,6 +120,9 @@
     private:
        PlaylistLoader *m_thread;
     };
+
+    friend class MakeItemEvent;
+    friend class DownloadPlaylistEvent;
 };
 
 #endif
