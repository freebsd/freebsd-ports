--- ext/DynaLoader/Makefile.PL.orig	Mon Nov 24 21:47:20 2003
+++ ext/DynaLoader/Makefile.PL	Mon Nov 24 21:56:15 2003
@@ -1,5 +1,8 @@
 use ExtUtils::MakeMaker;
 
+my $ccflags = $Config::Config{ccflags};
+tied(%Config::Config)->{ccflags} = "$ccflags -DPIC -fPIC";
+
 WriteMakefile(
     NAME => 'DynaLoader',
     LINKTYPE	=> 'static',
