--- Slim/Web/Pages/Home.pm.orig	2008-12-11 14:13:33.000000000 -0800
+++ Slim/Web/Pages/Home.pm	2008-12-22 13:11:18.000000000 -0800
@@ -14,6 +14,7 @@
 
 use base qw(Slim::Web::Pages);
 
+use Slim::Plugin::Base;
 use Slim::Utils::Prefs;
 use Slim::Utils::Strings;
 use Slim::Networking::Discovery::Server;
