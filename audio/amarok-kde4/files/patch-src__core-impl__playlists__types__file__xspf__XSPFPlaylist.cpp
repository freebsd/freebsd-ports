--- src/core-impl/playlists/types/file/xspf/XSPFPlaylist.cpp.orig	2014-07-27 18:29:25.000000000 +0200
+++ src/core-impl/playlists/types/file/xspf/XSPFPlaylist.cpp	2014-07-27 18:29:43.000000000 +0200
@@ -27,6 +27,7 @@
 #include "playlist/PlaylistController.h"
 #include "playlist/PlaylistModelStack.h"
 
+using Playlist::ModelStack;
 using namespace Playlists;
 
 XSPFPlaylist::XSPFPlaylist( const KUrl &url, Playlists::PlaylistProvider *provider, OnLoadAction onLoad )
@@ -101,7 +102,7 @@
     //FIXME: this needs to be moved to whatever is creating the XSPFPlaylist
     if( m_autoAppendAfterLoad )
         The::playlistController()->insertPlaylist(
-                    ::Playlist::ModelStack::instance()->bottom()->rowCount(),
+                    ModelStack::instance()->bottom()->rowCount(),
                     Playlists::PlaylistPtr( this )
                 );
 }
