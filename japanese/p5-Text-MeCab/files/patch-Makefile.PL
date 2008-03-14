--- Makefile.PL.orig	2008-03-08 20:51:04.000000000 +0900
+++ Makefile.PL	2008-03-13 05:47:28.000000000 +0900
@@ -129,7 +129,6 @@
 
 
     my $config = run_probes();
-    check_lib($config);
     define_symbols($config);
     extract_constants($config);
 
@@ -137,7 +136,7 @@
     my %INFO = (
         ABSTRACT     => 'Alternative Interface To libmecab',
         AUTHOR       => 'Daisuke Maki <daisuke@endeworks.jp>',
-        CCFLAGS      => $config->{cflags},
+        INC          => $config->{cflags},
         DEFINE       => join( " ", @{ $config->{define} } ),
         DISTNAME     => 'Text-MeCab',
         INSTALLDIRS  => 'site',
