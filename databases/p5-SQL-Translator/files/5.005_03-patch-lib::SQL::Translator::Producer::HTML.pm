--- lib/SQL/Translator/Producer/HTML.pm.orig	Sun May  9 21:14:22 2004
+++ lib/SQL/Translator/Producer/HTML.pm	Sun May  9 21:14:45 2004
@@ -59,7 +59,7 @@
                                    CGI::Pretty->new }
                     : do { require CGI;
                             import CGI; 
-                                   CGI->new };
+                                   CGI->new('') };
     my ($table, @table_names);
 
     if ($wrap) {
