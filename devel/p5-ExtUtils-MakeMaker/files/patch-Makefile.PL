--- Makefile.PL.orig	2020-09-15 18:49:10 UTC
+++ Makefile.PL
@@ -4,7 +4,6 @@ use 5.006;
 use strict;
 
 use lib ".";
-use my::bundles;  # Must be used before anything else to set up bundled dependencies
 
 use lib qw(lib);    # build ourself with ourself
 
@@ -46,7 +45,6 @@ else {
      $Extra_Params{PERL} = "$^X -Iinc";
    };
 
-   my::bundles::copy_bundles("bundled", "inc");
 }
 
 # Test::Harnesses prior to 2.00 shoved all of @INC onto the command line
@@ -72,7 +70,6 @@ my $MM = WriteMakefile(
     MIN_PERL_VERSION => '5.006',
     PMLIBDIRS        => [qw(lib inc)],
     PMLIBPARENTDIRS  => [qw(lib inc)],         # PMLIBPARENTDIRS is an experimental feature
-    EXE_FILES        => [qw(bin/instmodsh)],
 
     META_MERGE => {
         no_index => {
