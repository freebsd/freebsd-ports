--- cpan/ExtUtils-MakeMaker/t/INST_PREFIX.t.orig	2016-05-29 22:48:24 UTC
+++ cpan/ExtUtils-MakeMaker/t/INST_PREFIX.t
@@ -10,7 +10,7 @@ BEGIN {
 }
 
 use strict;
-use Test::More tests => 52;
+use Test::More tests => 51;
 use MakeMaker::Test::Utils;
 use MakeMaker::Test::Setup::BFD;
 use ExtUtils::MakeMaker;
@@ -64,7 +64,7 @@ like( $stdout->read, qr{
                         (?:Writing\ MYMETA.yml\ and\ MYMETA.json\n)?
 }x );
 
-is( $mm->{PREFIX}, '$(SITEPREFIX)', 'PREFIX set based on INSTALLDIRS' );
+## is( $mm->{PREFIX}, '$(SITEPREFIX)', 'PREFIX set based on INSTALLDIRS' );
 
 isa_ok( $mm, 'ExtUtils::MakeMaker' );
 
