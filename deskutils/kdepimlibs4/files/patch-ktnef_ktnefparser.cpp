Fix for https://www.kde.org/info/security/advisory-20170227-1.txt
--- ktnef/ktnefparser.cpp.orig	2017-03-11 20:23:43 UTC
+++ ktnef/ktnefparser.cpp
@@ -40,7 +40,9 @@
 
 #include <QtCore/QDateTime>
 #include <QtCore/QDataStream>
+#include <QtCore/QDir>
 #include <QtCore/QFile>
+#include <QtCore/QFileInfo>
 #include <QtCore/QVariant>
 #include <QtCore/QList>
 
@@ -446,7 +448,9 @@ bool KTNEFParser::extractFile( const QSt
 bool KTNEFParser::ParserPrivate::extractAttachmentTo( KTNEFAttach *att,
                                                       const QString &dirname )
 {
-  QString filename = dirname + '/';
+  const QString destDir( QDir( dirname ).absolutePath() ); // get directory path without any "." or ".."
+
+  QString filename = destDir + '/';
   if ( !att->fileName().isEmpty()) {
     filename += att->fileName();
   } else {
@@ -462,6 +466,13 @@ bool KTNEFParser::ParserPrivate::extract
   if ( !device_->seek( att->offset() ) ) {
     return false;
   }
+  const QFileInfo fi( filename );
+  if ( !fi.absoluteFilePath().startsWith( destDir ) ) {
+      kWarning() << "Attempted extract into" << fi.absoluteFilePath()
+                 << "which is outside of the extraction root folder" << destDir << "."
+                 << "Changing export of contained files to extraction root folder.";
+      filename = destDir + QLatin1Char( '/' ) + fi.fileName();
+  }
   KSaveFile outfile( filename );
   if ( !outfile.open() ) {
     return false;
