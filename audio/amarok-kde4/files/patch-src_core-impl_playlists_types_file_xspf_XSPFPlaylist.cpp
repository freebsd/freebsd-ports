--- src/core-impl/playlists/types/file/xspf/XSPFPlaylist.cpp.orig	2013-08-14 20:22:52 UTC
+++ src/core-impl/playlists/types/file/xspf/XSPFPlaylist.cpp
@@ -27,6 +27,7 @@
 #include "playlist/PlaylistController.h"
 #include "playlist/PlaylistModelStack.h"
 
+using Playlist::ModelStack;
 using namespace Playlists;
 
 XSPFPlaylist::XSPFPlaylist( const KUrl &url, Playlists::PlaylistProvider *provider, OnLoadAction onLoad )
@@ -101,7 +102,7 @@ XSPFPlaylist::load()
     //FIXME: this needs to be moved to whatever is creating the XSPFPlaylist
     if( m_autoAppendAfterLoad )
         The::playlistController()->insertPlaylist(
-                    ::Playlist::ModelStack::instance()->bottom()->rowCount(),
+                    ModelStack::instance()->bottom()->rowCount(),
                     Playlists::PlaylistPtr( this )
                 );
 }
