--- Slim/Formats/XML.pm.orig	2008-12-22 14:26:28.000000000 -0800
+++ Slim/Formats/XML.pm	2008-12-22 14:32:10.000000000 -0800
@@ -13,7 +13,7 @@
 use strict;
 use File::Slurp;
 use HTML::Entities;
-use JSON::XS qw(from_json);
+use JSON::XS::VersionOneAndTwo;
 use Scalar::Util qw(weaken);
 use URI::Escape qw(uri_escape);
 use XML::Simple;
