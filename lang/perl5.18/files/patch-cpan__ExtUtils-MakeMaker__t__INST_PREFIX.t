--- cpan/ExtUtils-MakeMaker/t/INST_PREFIX.t.orig	2014-10-01 01:32:59 UTC
+++ cpan/ExtUtils-MakeMaker/t/INST_PREFIX.t
@@ -10,7 +10,7 @@
 }
 
 use strict;
-use Test::More tests => 52;
+use Test::More tests => 51;
 use MakeMaker::Test::Utils;
 use MakeMaker::Test::Setup::BFD;
 use ExtUtils::MakeMaker;
@@ -58,7 +58,7 @@
                         (?:Writing\ MYMETA.yml\ and\ MYMETA.json\n)?
 }x );
 
-is( $mm->{PREFIX}, '$(SITEPREFIX)', 'PREFIX set based on INSTALLDIRS' );
+## is( $mm->{PREFIX}, '$(SITEPREFIX)', 'PREFIX set based on INSTALLDIRS' );
 
 isa_ok( $mm, 'ExtUtils::MakeMaker' );
 
