--- Makefile.PL.orig	2015-05-07 17:56:22 UTC
+++ Makefile.PL
@@ -30,8 +30,8 @@ $Data::Dumper::Indent = 1;
 $Data::Dumper::Sortkeys = 1;
 
 my $lmcd_api_ver = "1.0"; # eg $lmcd_src/libmemcached-$lmcd_api_ver/
-my $lmcd_inst = getcwd()."/src_inst";
-my $lmcd_built_lib = "$lmcd_inst/lib/libmemcached$Config{lib_ext}";
+my $lmcd_inst = "%%PREFIX%%";
+my $lmcd_built_lib = "$lmcd_inst/lib/libmemcached.so";
 my $is_developer = (-d ".svn" || -d ".git");
 
 my ($lmcd_h) = eval { build_libmemcached() };
@@ -76,7 +76,7 @@ WriteMakefile(
     AUTHOR              => 'Tim Bunce <Tim.Bunce@pobox.com>',
     VERSION_FROM        => 'libmemcached.pm',
     ABSTRACT_FROM       => 'libmemcached.pm',
-    INC                 => "-I$lmcd_inst/include",
+    INC                 => "-I$lmcd_inst/include/",
     # We want to link to *our* private libmemcached and not one that
     # might already be installed on the system. The LIBS config gets
     # appended to the link command line, so if we used "-L$dir -lmemcached"
