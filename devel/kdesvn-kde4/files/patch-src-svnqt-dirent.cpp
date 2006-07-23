--- src/svnqt/dirent.cpp.orig	Fri Apr 28 16:50:10 2006
+++ src/svnqt/dirent.cpp	Fri Apr 28 16:50:28 2006
@@ -54,7 +54,7 @@
         hasProps (dirEntry->has_props != 0),
         createdRev (dirEntry->created_rev), time (dirEntry->time), m_Lock()
     {
-      lastAuthor = dirEntry->last_author == 0 ? "" : QString::FROMUTF8(dirEntry->last_author);
+      lastAuthor = dirEntry->last_author == 0 ? QString::fromLatin1("") : QString::FROMUTF8(dirEntry->last_author);
     }
 
     Data (const DirEntry & src)
