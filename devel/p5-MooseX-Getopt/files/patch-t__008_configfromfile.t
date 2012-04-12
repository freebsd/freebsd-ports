--- t/008_configfromfile.t.orig	2012-02-03 05:27:38.000000000 -0900
+++ t/008_configfromfile.t	2012-04-03 18:15:22.000000000 -0800
@@ -86,7 +86,7 @@
 {
     local @ARGV = qw( --required_from_argv 1 );
 
-    like exception { App->new_with_options }, qr/Required option missing: required_from_config/;
+    like exception { App->new_with_options }, qr/Mandatory parameter 'required_from_config' missing in call to/;
 
     {
         my $app = App::DefaultConfigFile->new_with_options;
@@ -155,7 +155,7 @@
 # Required arg not supplied from cmdline
 {
     local @ARGV = qw( --configfile /notused );
-    like exception { App->new_with_options }, qr/Required option missing: required_from_argv/;
+    like exception { App->new_with_options }, qr/Mandatory parameter 'required_from_argv' missing in call to/;
 }
 
 # Config file value overriden from cmdline
