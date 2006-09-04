
$FreeBSD$

--- amarok/src/collectiondb.cpp.orig
+++ amarok/src/collectiondb.cpp
@@ -3447,28 +3447,6 @@
             bundle->copyFrom( peb );
             valid = true;
         }
-        else if( bundle->url().protocol() == "audiocd" || bundle->url().protocol() == "cdda" )
-        {
-            // try to see if the engine has some info about the
-            // item (the intended behaviour should be that if the
-            // item is an AudioCD track, the engine can return
-            // CDDB data for it)
-            Engine::SimpleMetaBundle smb;
-            if ( EngineController::engine()->metaDataForUrl( bundle->url(), smb ) )
-            {
-                valid = true;
-                bundle->setTitle( smb.title );
-                bundle->setArtist( smb.artist );
-                bundle->setAlbum( smb.album );
-                bundle->setComment( smb.comment );
-                bundle->setGenre( smb.genre );
-                bundle->setBitrate( smb.bitrate.toInt() );
-                bundle->setSampleRate( smb.samplerate.toInt() );
-                bundle->setLength( smb.length.toInt() );
-                bundle->setYear( smb.year.toInt() );
-                bundle->setTrack( smb.tracknr.toInt() );
-            }
-        }
     }
 
     return valid;
@@ -5745,7 +5723,8 @@
 {
 
     QStringList values;
-    int error, rc;
+    int error;
+    int rc = 0;
     const char* tail;
     sqlite3_stmt* stmt;
     int busyCnt = 0;
@@ -5771,6 +5750,7 @@
             Debug::error() << sqlite3_errmsg( m_db ) << endl;
             Debug::error() << "on query: " << statement << endl;
             values = QStringList();
+            break;
         }
         else
         {
@@ -5835,7 +5815,8 @@
 
 int SqliteConnection::insert( const QString& statement, const QString& /* table */ )
 {
-    int error, rc;
+    int error;
+    int rc = 0;
     const char* tail;
     sqlite3_stmt* stmt;
     int busyCnt = 0;
@@ -5860,6 +5841,7 @@
             Debug::error() << k_funcinfo << " sqlite3_compile error:" << endl;
             Debug::error() << sqlite3_errmsg( m_db ) << endl;
             Debug::error() << "on insert: " << statement << endl;
+            break;
         }
         else
         {
