--- Slim/Plugin/Sirius/ProtocolHandler.pm.orig	2008-12-22 14:26:28.000000000 -0800
+++ Slim/Plugin/Sirius/ProtocolHandler.pm	2008-12-22 14:32:33.000000000 -0800
@@ -19,7 +19,7 @@
 use Slim::Utils::Timers;
 
 use HTTP::Request;
-use JSON::XS qw(from_json);
+use JSON::XS::VersionOneAndTwo;
 use URI::Escape qw(uri_escape);
 
 my $log = Slim::Utils::Log->addLogCategory( {
