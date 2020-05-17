--- src/organise/organiseformat.cpp.orig	2020-04-27 23:42:16 UTC
+++ src/organise/organiseformat.cpp
@@ -35,6 +35,7 @@
 #include <QPalette>
 #include <QValidator>
 #include <QTextEdit>
+#include <QTextDocument>
 #include <QTextFormat>
 
 #include "core/arraysize.h"
@@ -44,8 +45,6 @@
 
 #include "organiseformat.h"
 
-class QTextDocument;
-
 const char *OrganiseFormat::kTagPattern = "\\%([a-zA-Z]*)";
 const char *OrganiseFormat::kBlockPattern = "\\{([^{}]+)\\}";
 const QStringList OrganiseFormat::kKnownTags = QStringList() << "title"
@@ -145,7 +144,12 @@ QString OrganiseFormat::GetFilenameForSong(const Song 
 
   QFileInfo info(filename);
   QString extension = info.suffix();
-  QString filepath = info.path() + "/" + info.completeBaseName();
+  QString filepath;
+  if (!info.path().isEmpty() && info.path() != ".") {
+    filepath.append(info.path());
+    filepath.append("/");
+  }
+  filepath.append(info.completeBaseName());
 
   // Fix any parts of the path that start with dots.
   QStringList parts_old = filepath.split("/");
