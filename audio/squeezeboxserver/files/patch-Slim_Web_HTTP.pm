
$FreeBSD$

--- Slim/Web/HTTP.pm.orig
+++ Slim/Web/HTTP.pm
@@ -54,7 +54,7 @@
 	$Template::Config::CONTEXT = 'Slim::Web::Template::Context';
 }
 
-use constant defaultSkin => 'Default';
+use constant defaultSkin => '%%DEFAULT_SKIN%%';
 use constant baseSkin	 => 'EN';
 use constant HALFYEAR	 => 60 * 60 * 24 * 180;
 
