--- Slim/Plugin/LastFM/ProtocolHandler.pm.orig	2008-12-22 14:26:28.000000000 -0800
+++ Slim/Plugin/LastFM/ProtocolHandler.pm	2008-12-22 14:32:41.000000000 -0800
@@ -7,7 +7,7 @@
 use strict;
 use base qw(Slim::Player::Protocols::HTTP);
 
-use JSON::XS qw(from_json);
+use JSON::XS::VersionOneAndTwo;
 use URI::Escape qw(uri_escape_utf8);
 
 use Slim::Player::Playlist;
