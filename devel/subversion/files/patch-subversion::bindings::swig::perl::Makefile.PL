--- subversion/bindings/swig/perl/Makefile.PL.orig	Sat Jan 24 20:46:46 2004
+++ subversion/bindings/swig/perl/Makefile.PL	Sat Jan 31 21:40:23 2004
@@ -41,7 +41,7 @@
 
 my %config = (
     ABSTRACT => 'Perl bindings for Subversion',
-    CCFLAGS  => join(' ', $apr_cflags, $apu_cflags, 
+    CCFLAGS  => join(' ', $ENV{'CCFLAGS'} || '', $apr_cflags, $apu_cflags, 
                      `$perl_path -MExtUtils::Embed -e ccopts`,
                      ' -I.. -I../../../include -g'),
     OBJECT => q/$(O_FILES)/,
