- Allow overriding PREFIX? (fix test)

--- cpan/ExtUtils-MakeMaker/t/INST_PREFIX.t.orig	2020-10-18 21:18:11 UTC
+++ cpan/ExtUtils-MakeMaker/t/INST_PREFIX.t
@@ -11,7 +11,7 @@ BEGIN {
 
 use strict;
 use warnings;
-use Test::More tests => 52;
+use Test::More tests => 51;
 use MakeMaker::Test::Utils;
 use MakeMaker::Test::Setup::BFD;
 use ExtUtils::MakeMaker;
@@ -65,7 +65,7 @@ like( $stdout->read, qr{
                         (?:Writing\ MYMETA.yml\ and\ MYMETA.json\n)?
 }x );
 
-is( $mm->{PREFIX}, '$(SITEPREFIX)', 'PREFIX set based on INSTALLDIRS' );
+## is( $mm->{PREFIX}, '$(SITEPREFIX)', 'PREFIX set based on INSTALLDIRS' );
 
 isa_ok( $mm, 'ExtUtils::MakeMaker' );
 
