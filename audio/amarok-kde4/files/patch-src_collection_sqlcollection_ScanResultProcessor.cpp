--- src/collection/sqlcollection/ScanResultProcessor.cpp.orig
+++ src/collection/sqlcollection/ScanResultProcessor.cpp
@@ -42,19 +42,59 @@ ScanResultProcessor::ScanResultProcessor( SqlCollection *collection )
 ScanResultProcessor::~ScanResultProcessor()
 {
     //everything has a URL, so enough to just delete from here
+    QSet<QStringList*> currSet; //prevent double deletes
     foreach( QStringList *list, m_urlsHashByUid )
-        delete list;
+    {
+        if( list )
+        {
+            if( !currSet.contains( list ) )
+            {
+                delete list;
+                currSet.insert( list );
+            }
+        }
+        else
+            debug() << "GAAH! Tried to double-delete a value in m_urlsHashByUid";
+    }
     foreach( QLinkedList<QStringList*> *list, m_albumsHashByName )
     {
-        foreach( QStringList *slist, *list )
-            delete slist;
-        delete list;
+        if( list )
+        {
+            foreach( QStringList *slist, *list )
+            {
+                if( slist )
+                {
+                    if( !currSet.contains( slist ) )
+                    {
+                        delete slist;
+                        currSet.insert( slist );
+                    }
+                    else
+                        debug() << "GAAH! Tried to double-delete a value in m_albumsHashByName";
+                }
+            }
+            delete list;
+        }
     }
     foreach( QLinkedList<QStringList*> *list, m_tracksHashByAlbum )
     {
-        foreach( QStringList *slist, *list )
-            delete slist;
-        delete list;
+        if( list )
+        {
+            foreach( QStringList *slist, *list )
+            {
+                if( slist )
+                {
+                    if( !currSet.contains( slist ) )
+                    {
+                        delete slist;
+                        currSet.insert( slist );
+                    }
+                    else
+                        debug() << "GAAH! Tried to double-delete a value in m_tracksHashByAlbum";
+                }
+            }
+            delete list;
+        }
     }
 }
 
@@ -67,11 +107,11 @@ ScanResultProcessor::setScanType( ScanType type )
 void
 ScanResultProcessor::addDirectory( const QString &dir, uint mtime )
 {
-    DEBUG_BLOCK
-    debug() << "SRP::addDirectory on " << dir << " with mtime " << mtime;
+    //DEBUG_BLOCK
+    //debug() << "SRP::addDirectory on " << dir << " with mtime " << mtime;
     if( dir.isEmpty() )
     {
-        debug() << "got directory with no path from the scanner, not adding";
+        //debug() << "got directory with no path from the scanner, not adding";
         return;
     }
     setupDatabase();
@@ -254,7 +294,7 @@ ScanResultProcessor::rollback()
 void
 ScanResultProcessor::processDirectory( const QList<QVariantMap > &data )
 {
-//     DEBUG_BLOCK
+    //DEBUG_BLOCK
     setupDatabase();
     //using the following heuristics:
     //if more than one album is in the dir, use the artist of each track as albumartist
@@ -274,24 +314,54 @@ ScanResultProcessor::processDirectory( const QList<QVariantMap > &data )
         if( row.value( Field::ALBUM ).toString() != album )
             multipleAlbums = true;
     }
+
     if( multipleAlbums || album.isEmpty() || artists.size() == 1 )
     {
         foreach( const QVariantMap &row, data )
         {
-            int artist = genericId( &m_artists, row.value( Field::ARTIST ).toString(), &m_nextArtistNum );
-            addTrack( row, artist );
+            QString uid = row.value( Field::UNIQUEID ).toString();
+            if( m_uidsSeenThisScan.contains( uid ) )
+            {
+                QString originalLocation = ( ( m_urlsHashByUid.contains( uid ) &&
+                                             m_urlsHashByUid[uid] != 0 ) ?
+                                             MountPointManager::instance()->getAbsolutePath( m_urlsHashByUid[uid]->at( 1 ).toInt(), m_urlsHashByUid[uid]->at( 2 ) ) : "(unknown)" );
+                debug() << "Skipping file with uniqueid " << uid << " as it was already seen this scan," <<
+                           "file is at " << row.value( Field::URL ).toString() << ", original file is at " << originalLocation;
+            }
+            else
+            {
+                int artist = genericId( &m_artists, row.value( Field::ARTIST ).toString(), &m_nextArtistNum );
+                //debug() << "artist found = " << artist;
+                addTrack( row, artist );
+                m_uidsSeenThisScan.insert( uid );
+            }
         }
     }
     else
     {
         QString albumArtist = findAlbumArtist( artists, data.count() );
+        //debug() << "albumArtist found = " << albumArtist;
         //an empty string means that no albumartist was found
         int artist = albumArtist.isEmpty() ? 0 : genericId( &m_artists, albumArtist, &m_nextArtistNum );
+        //debug() << "artist found = " << artist;
 
         //debug() << "albumartist " << albumArtist << "for artists" << artists;
         foreach( const QVariantMap &row, data )
         {
-            addTrack( row, artist );
+            QString uid = row.value( Field::UNIQUEID ).toString();
+            if( m_uidsSeenThisScan.contains( uid ) )
+            {
+                QString originalLocation = ( ( m_urlsHashByUid.contains( uid ) &&
+                                             m_urlsHashByUid[uid] != 0 ) ?
+                                             MountPointManager::instance()->getAbsolutePath( m_urlsHashByUid[uid]->at( 1 ).toInt(), m_urlsHashByUid[uid]->at( 2 ) ) : "(unknown)" );
+                debug() << "Skipping file with uniqueid " << uid << " as it was already seen this scan," <<
+                           "file is at " << row.value( Field::URL ).toString() << ", original file is at " << originalLocation;
+            }
+            else
+            {
+                addTrack( row, artist );
+                m_uidsSeenThisScan.insert( uid );
+            }
         }
     }
 }
@@ -299,6 +369,7 @@ ScanResultProcessor::processDirectory( const QList<QVariantMap > &data )
 QString
 ScanResultProcessor::findAlbumArtist( const QSet<QString> &artists, int trackCount ) const
 {
+    //DEBUG_BLOCK
     QMap<QString, int> artistCount;
     bool featuring;
     QStringList trackArtists;
@@ -371,6 +442,7 @@ void
 ScanResultProcessor::addTrack( const QVariantMap &trackData, int albumArtistId )
 {
     //DEBUG_BLOCK
+    //debug() << "albumArtistId = " << albumArtistId;
     //amarok 1 stored all tracks of a compilation in different directories.
     //when using its "Organize Collection" feature
     //try to detect these cases
@@ -419,7 +491,15 @@ ScanResultProcessor::addTrack( const QVariantMap &trackData, int albumArtistId )
 
     //urlId will take care of the urls table part of AFT
     int url = urlId( path, uid );
-
+/*
+    foreach( QString key, m_urlsHashByUid.keys() )
+    debug() << "Key: " << key << ", list: " << *m_urlsHashByUid[key];
+    foreach( int key, m_urlsHashById.keys() )
+    debug() << "Key: " << key << ", list: " << *m_urlsHashById[key];
+    typedef QPair<int, QString> blahType; //QFOREACH is stupid when it comes to QPairs
+    foreach( blahType key, m_urlsHashByLocation.keys() )
+    debug() << "Key: " << key << ", list: " << *m_urlsHashByLocation[key];
+*/
     QStringList *trackList = new QStringList();
     int id = m_nextTrackNum;
     //debug() << "Appending new track number with tracknum: " << id;
@@ -470,7 +550,7 @@ ScanResultProcessor::addTrack( const QVariantMap &trackData, int albumArtistId )
     //insert into hashes
     if( m_tracksHashByUrl.contains( url ) && m_tracksHashByUrl[url] != 0 )
     {
-        //debug() << "m_tracksHashByUrl contains the url!";
+        //debug() << "m_tracksHashByUrl already contains url " << url;
         //need to replace, not overwrite/add a new one
         QStringList *oldValues = m_tracksHashByUrl[url];
         QString oldId = oldValues->at( 0 );
@@ -490,8 +570,24 @@ ScanResultProcessor::addTrack( const QVariantMap &trackData, int albumArtistId )
         m_tracksHashById.insert( id, trackList );
     }
 
+    //debug() << "album = " << album;
+
     if( m_tracksHashByAlbum.contains( album ) && m_tracksHashByAlbum[album] != 0 )
-        m_tracksHashByAlbum[album]->append( trackList );
+    {
+        //contains isn't the fastest on linked lists, but in reality this is on the order of maybe
+        //ten quick pointer comparisons per track on average...probably lower
+        //debug() << "trackList is " << trackList;
+        if( !m_tracksHashByAlbum[album]->contains( trackList ) )
+        {
+            //debug() << "appending trackList to m_tracksHashByAlbum";
+            m_tracksHashByAlbum[album]->append( trackList );
+        }
+        else
+        {
+            //debug() << "not appending trackList to m_tracksHashByAlbum";
+        }
+
+    }
     else
     {
         QLinkedList<QStringList*> *list = new QLinkedList<QStringList*>();
@@ -595,6 +691,8 @@ ScanResultProcessor::albumId( const QString &album, int albumArtistId )
         QLinkedList<QStringList*> *list = m_albumsHashByName[album];
         foreach( QStringList *slist, *list )
         {
+            //debug() << "albumArtistId = " << albumArtistId;
+            //debug() << "Checking list: " << *slist;
             if( slist->at( 2 ).isEmpty() && albumArtistId == 0 )
             {
                 //debug() << "artist is empty and albumArtistId = 0, returning " << slist->at( 0 );
@@ -631,7 +729,10 @@ ScanResultProcessor::albumInsert( const QString &album, int albumArtistId )
     albumList->append( QString() );
     m_albumsHashById[returnedNum] = albumList;
     if( m_albumsHashByName.contains( album ) && m_albumsHashByName[album] != 0 )
-        m_albumsHashByName[album]->append( albumList );
+    {
+        if( !m_albumsHashByName[album]->contains( albumList ) )
+            m_albumsHashByName[album]->append( albumList );
+    }
     else
     {
         QLinkedList<QStringList*> *list = new QLinkedList<QStringList*>();
@@ -645,7 +746,7 @@ ScanResultProcessor::albumInsert( const QString &album, int albumArtistId )
 int
 ScanResultProcessor::urlId( const QString &url, const QString &uid )
 {
-    /*
+/*
     DEBUG_BLOCK
     foreach( QString key, m_urlsHashByUid.keys() )
     debug() << "Key: " << key << ", list: " << *m_urlsHashByUid[key];
@@ -654,8 +755,7 @@ ScanResultProcessor::urlId( const QString &url, const QString &uid )
     typedef QPair<int, QString> blahType; //QFOREACH is stupid when it comes to QPairs
     foreach( blahType key, m_urlsHashByLocation.keys() )
     debug() << "Key: " << key << ", list: " << *m_urlsHashByLocation[key];
-    */
- 
+*/
     QFileInfo fileInfo( url );
     const QString dir = fileInfo.absoluteDir().absolutePath();
     int dirId = directoryId( dir );
@@ -665,6 +765,7 @@ ScanResultProcessor::urlId( const QString &url, const QString &uid )
     QPair<int, QString> locationPair( deviceId, rpath );
     //debug() << "in urlId with url = " << url << " and uid = " << uid;
     //debug() << "checking locationPair " << locationPair;
+/*
     if( m_urlsHashByLocation.contains( locationPair ) )
     {
         QStringList values;
@@ -674,6 +775,7 @@ ScanResultProcessor::urlId( const QString &url, const QString &uid )
             values << "zero";
         //debug() << "m_urlsHashByLocation contains it! It is " << values;
     }
+*/
     QStringList currUrlIdValues;
     if( m_urlsHashByUid.contains( uid ) && m_urlsHashByUid[uid] != 0 )
         currUrlIdValues = *m_urlsHashByUid[uid];
@@ -717,6 +819,7 @@ ScanResultProcessor::urlId( const QString &url, const QString &uid )
             //debug() << "m_urlsHashByUid contains this UID, updating deviceId and path";
             QStringList *list = m_urlsHashByUid[uid];
             //debug() << "list from UID hash is " << list << " with values " << *list;
+            QPair<int, QString> oldLocationPair( list->at( 1 ).toInt(), list->at( 2 ) );
             list->replace( 1, QString::number( deviceId ) );
             list->replace( 2, rpath );
             list->replace( 3, QString::number( dirId ) );
@@ -737,6 +840,7 @@ ScanResultProcessor::urlId( const QString &url, const QString &uid )
                 delete oldList;
             }
             m_urlsHashByLocation[locationPair] = list;
+            m_urlsHashByLocation.remove( oldLocationPair );
         }
         m_permanentTablesUrlUpdates.insert( uid, url );
         m_changedUrls.insert( uid, QPair<QString, QString>( MountPointManager::instance()->getAbsolutePath( currUrlIdValues[1].toInt(), currUrlIdValues[2] ), url ) );
@@ -751,6 +855,7 @@ ScanResultProcessor::urlId( const QString &url, const QString &uid )
         {
             QStringList *list = m_urlsHashByLocation[locationPair];
             //debug() << "Replacing hash " << list->at( 4 ) << " with " << uid;
+            QString oldId = list->at( 4 );
             list->replace( 4, uid );
             if( m_urlsHashByUid.contains( uid )
                 && m_urlsHashByUid[uid] != 0 
@@ -762,6 +867,7 @@ ScanResultProcessor::urlId( const QString &url, const QString &uid )
                 delete oldList;
             }
             m_urlsHashByUid[uid] = list;
+            m_urlsHashByUid.remove( oldId );
         }
         m_permanentTablesUidUpdates.insert( url, uid );
         m_changedUids.insert( currUrlIdValues[4], uid );
@@ -855,7 +961,8 @@ ScanResultProcessor::directoryId( const QString &dir )
 int
 ScanResultProcessor::checkExistingAlbums( const QString &album )
 {
-//     DEBUG_BLOCK
+    //DEBUG_BLOCK
+    //debug() << "looking for album " << album;
     // "Unknown" albums shouldn't be handled as compilations
     if( album.isEmpty() )
         return 0;
@@ -865,7 +972,10 @@ ScanResultProcessor::checkExistingAlbums( const QString &album )
     //it's probably a compilation.
     //this handles A1 compilations that were automatically organized by Amarok
     if( !m_albumsHashByName.contains( album ) || m_albumsHashByName[album] == 0 )
+    {
+        //debug() << "hashByName doesn't contain album, or it's zero";
         return 0;
+    }
 
     QStringList trackIds;
     QLinkedList<QStringList*> *llist = m_albumsHashByName[album];
@@ -915,8 +1025,10 @@ ScanResultProcessor::checkExistingAlbums( const QString &album )
         }
     }
 
+    //debug() << "trackIds = " << trackIds;
     if( trackIds.isEmpty() )
     {
+        //debug() << "trackIds empty, returning zero";
         return 0;
     }
     else
@@ -933,6 +1045,7 @@ ScanResultProcessor::checkExistingAlbums( const QString &album )
                 list->replace( 3, compilationString );
             }
         }
+        //debug() << "returning " << compilationId;
         return compilationId;
     }
 }
@@ -1167,6 +1280,17 @@ ScanResultProcessor::copyHashesToTempTables()
     foreach( blahType key, m_urlsHashByLocation.keys() )
         debug() << "Key: " << key << ", list: " << *m_urlsHashByLocation[key];
     debug() << "Next album num: " << m_nextAlbumNum;
+
+    foreach( int key, m_tracksHashById.keys() )
+        debug() << "Key: " << key << ", list: " << *m_tracksHashById[key];
+    foreach( int key, m_tracksHashByUrl.keys() )
+        debug() << "Key: " << key << ", list: " << *m_tracksHashByUrl[key];
+    foreach( int key, m_tracksHashByAlbum.keys() )
+    {
+        debug() << "Key: " << key;
+        foreach( QStringList* item, *m_tracksHashByAlbum[key] )
+            debug() << "list: " << item << " is " << *item;
+    }
     */
  
     DEBUG_BLOCK
--- src/collection/sqlcollection/ScanResultProcessor.h.orig
+++ src/collection/sqlcollection/ScanResultProcessor.h
@@ -94,6 +94,7 @@ class ScanResultProcessor : public QObject
         QMap<QString, int> m_directories;
         QMap<QString, QList< QPair< QString, QString > > > m_imageMap;
 
+        QSet<QString> m_uidsSeenThisScan;
         QHash<QString, uint> m_filesInDirs;
 
         TrackUrls m_changedUids; //not really track urls
