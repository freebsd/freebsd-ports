--- Makefile.PL.orig	2017-08-15 07:31:07 UTC
+++ Makefile.PL
@@ -1,6 +1,5 @@
 use ExtUtils::MakeMaker;
 
-use Canary::Stability AnyEvent::DBI => 1, 5.008;
 
 my $mm = MM->new({
     dist         => {
@@ -12,7 +11,6 @@ my $mm = MM->new({
     VERSION_FROM => "DBI.pm",
     CONFIGURE_REQUIRES => {
        "ExtUtils::MakeMaker" => 6.6,
-       "Canary::Stability" => 0,
     },
     PREREQ_PM        => {
        AnyEvent        => 4.15,
