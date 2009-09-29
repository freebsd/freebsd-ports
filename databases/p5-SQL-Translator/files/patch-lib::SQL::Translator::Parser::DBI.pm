--- lib/SQL/Translator/Parser/DBI.pm.orig	2009-03-17 11:34:29.000000000 +0900
+++ lib/SQL/Translator/Parser/DBI.pm	2009-03-17 11:34:45.000000000 +0900
@@ -170,7 +170,7 @@
     my $pkg     = "SQL::Translator::Parser::DBI::$driver";
     my $sub     = $pkg.'::parse';
 
-    $tr->load( $pkg );
+    SQL::Translator::load( $pkg );
 
     eval {
         no strict 'refs';
