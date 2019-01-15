--- src/core/qgsproject.cpp.orig	2018-11-23 12:08:36 UTC
+++ src/core/qgsproject.cpp
@@ -1867,7 +1867,7 @@ bool QgsProject::writeProjectFile( const QString &file
     }
 
     QFileInfo fi( fileName() );
-    struct utimbuf tb = { fi.lastRead().toTime_t(), fi.lastModified().toTime_t() };
+    struct utimbuf tb = { static_cast<time_t>( fi.lastRead().toSecsSinceEpoch() ), static_cast<time_t>( fi.lastModified().toSecsSinceEpoch() ) };
     utime( backupFile.fileName().toUtf8().constData(), &tb );
   }
 
