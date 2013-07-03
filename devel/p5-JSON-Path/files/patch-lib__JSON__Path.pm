--- ./lib/JSON/Path.pm.orig	2013-07-03 13:31:32.000000000 -0400
+++ ./lib/JSON/Path.pm	2013-07-03 13:31:52.000000000 -0400
@@ -12,7 +12,7 @@
 use Carp;
 use JSON qw[from_json];
 use Scalar::Util qw[blessed];
-use lvalue ();
+use Lvalue qw/lvalue/;
 
 use Sub::Exporter -setup => {
 	exports => [qw/ jpath jpath1 jpath_map /],
