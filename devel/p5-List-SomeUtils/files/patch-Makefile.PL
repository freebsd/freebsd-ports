--- Makefile.PL.orig	2016-02-27 15:18:00 UTC
+++ Makefile.PL
@@ -13,7 +13,6 @@ my %WriteMakefileArgs = (
   "ABSTRACT" => "Provide the stuff missing in List::Util",
   "AUTHOR" => "Tassilo von Parseval <tassilo.von.parseval\@rwth-aachen.de>, Adam Kennedy <adamk\@cpan.org>, Jens Rehsack <rehsack\@cpan.org>, Dave Rolsky <autarch\@urth.org>",
   "CONFIGURE_REQUIRES" => {
-    "ExtUtils::HasCompiler" => 0,
     "ExtUtils::MakeMaker" => 0
   },
   "DISTNAME" => "List-SomeUtils",
@@ -76,9 +75,6 @@ unless ( eval { ExtUtils::MakeMaker->VER
 delete $WriteMakefileArgs{CONFIGURE_REQUIRES}
   unless eval { ExtUtils::MakeMaker->VERSION(6.52) };
 
-use ExtUtils::HasCompiler qw( can_compile_loadable_object );
-if ( can_compile_loadable_object( quiet => 1 ) ) {
-    $WriteMakefileArgs{PREREQ_PM}{'List::SomeUtils::XS'} = 0;
-}
+$WriteMakefileArgs{PREREQ_PM}{'List::SomeUtils::XS'} = 0;
 
 WriteMakefile(%WriteMakefileArgs);
