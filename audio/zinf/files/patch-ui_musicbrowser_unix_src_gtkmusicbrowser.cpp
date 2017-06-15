--- ui/musicbrowser/unix/src/gtkmusicbrowser.cpp.orig	2004-02-02 18:34:19 UTC
+++ ui/musicbrowser/unix/src/gtkmusicbrowser.cpp
@@ -1203,7 +1203,7 @@ void GTKMusicBrowser::SaveCurrentPlaylis
     if (m_currentListName.length() == 0)
         return;
 
-    char *ext = strrchr(m_currentListName.c_str(), '.');
+    const char *ext = strrchr(m_currentListName.c_str(), '.');
     if (ext)
         ext = ext + 1;
     Error result = kError_NoErr;
