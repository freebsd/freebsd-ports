
$FreeBSD$

--- Slim/Plugin/LastFM/ProtocolHandler.pm.orig
+++ Slim/Plugin/LastFM/ProtocolHandler.pm
@@ -7,7 +7,7 @@
 use strict;
 use base qw(Slim::Player::Protocols::HTTP);
 
-use JSON::XS qw(from_json);
+use JSON::XS qw(decode_json);
 use URI::Escape qw(uri_escape_utf8);
 
 use Slim::Player::Playlist;
@@ -155,7 +155,7 @@
 	my $client = $http->params->{client};
 	my $params = $http->params->{params};
 	
-	my $track = eval { from_json( $http->content ) };
+	my $track = eval { decode_json( $http->content ) };
 	
 	if ( $@ || $track->{error} ) {
 		# We didn't get the next track to play
