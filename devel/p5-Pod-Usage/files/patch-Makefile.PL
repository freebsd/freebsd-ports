Do not conflict with lang/perl5.*

--- Makefile.PL.orig	2020-10-06 09:26:36 UTC
+++ Makefile.PL
@@ -39,7 +39,7 @@ my %WriteMakefileArgs = (
 %WriteMakefileArgs = (
     %WriteMakefileArgs,
     EXE_FILES => MY::exe(),
-    PL_FILES => { MY::pod2usage() . '.PL', MY::pod2usage() },
+    PL_FILES => {},
     INSTALLDIRS  => ($] < 5.012 ? 'perl' : 'site'),
     clean => { FILES => join( ' ', @{MY::exe()}) },
 );
@@ -70,9 +70,8 @@ WriteMakefile(%WriteMakefileArgs);
 # <custom footer>
 package MY; use strict; use warnings;
 use File::Spec ();
-sub SCRIPTS { qw( pod2usage ) }
+sub SCRIPTS { qw() }
 sub script { File::Spec->catfile ('scripts', @_) }
-sub pod2usage { MY::exe()->[0] or die "pod2usage failed" }
 sub exe {
    if ( $^O eq 'VMS' ) {
      return [ map { script("$_.com") } SCRIPTS() ];
