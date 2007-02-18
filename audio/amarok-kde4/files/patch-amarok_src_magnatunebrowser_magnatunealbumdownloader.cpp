
$FreeBSD$

--- amarok/src/magnatunebrowser/magnatunealbumdownloader.cpp.orig
+++ amarok/src/magnatunebrowser/magnatunealbumdownloader.cpp
@@ -89,19 +89,19 @@
 
     //ok, now we have the .zip file downloaded. All we need is to unpack it to the desired location and add it to the collection.
 
-    QString unzipString = "unzip \""+m_tempDir.name() + m_currentAlbumFileName + "\" -d \"" + m_currentAlbumUnpackLocation + "\" &";
+    QString unzipString = "unzip "+ KProcess::quote( m_tempDir.name() + m_currentAlbumFileName) + " -d " +KProcess::quote( m_currentAlbumUnpackLocation ) + " &";
 
     debug() << "unpacking: " << unzipString << endl;
 
     system( unzipString.ascii() );
 
-  
+
 
     if (m_currentAlbumId != -1 ) {
 
-        //now I really want to add the album cover to the same folder where I just unzipped the album... The 
+        //now I really want to add the album cover to the same folder where I just unzipped the album... The
         //only way of getting the actual location where the album was unpacked is using the artist and album names
-   
+
         MagnatuneAlbum album = MagnatuneDatabaseHandler::instance()->getAlbumById( m_currentAlbumId );
         MagnatuneArtist artist = MagnatuneDatabaseHandler::instance()->getArtistById( album.getArtistId() );
 
