--- src/svnqt/log_entry.cpp.orig	Sat Apr 29 00:36:34 2006
+++ src/svnqt/log_entry.cpp	Sat Apr 29 00:37:18 2006
@@ -93,8 +93,8 @@
     }
 
     revision = revision_;
-    author = author_ == 0 ? "" : QString::FROMUTF8(author_);
-    message = message_ == 0 ? "" : QString::FROMUTF8(message_);
+    author = author_ == 0 ? QString::fromLatin1("") : QString::FROMUTF8(author_);
+    message = message_ == 0 ? QString::fromLatin1("") : QString::FROMUTF8(message_);
   }
 }
 
