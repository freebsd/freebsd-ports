--- Makefile.PL.orig	Wed Sep 15 01:31:24 2004
+++ Makefile.PL	Wed Sep 15 01:33:11 2004
@@ -66,7 +66,7 @@
   $dbi_arch_dir = dbd_dbi_arch_dir();
 }
 
-my $comp_opts = $Config{q{ccflags}};
+my $comp_opts = '';
 if ($major_ver == 7) {
     if ($minor_ver >= 2) {
         $comp_opts .= " -DHAVE_PQescapeString";
@@ -86,7 +86,7 @@
 my %opts = (
     NAME         => 'DBD::Pg',
     VERSION_FROM => 'Pg.pm',
-    INC          => "-I$POSTGRES_INCLUDE -I$dbi_arch_dir",
+    INC          => "-I$POSTGRES_INCLUDE -I$dbi_arch_dir $comp_opts",
     OBJECT       => "Pg\$(OBJ_EXT) dbdimp\$(OBJ_EXT) quote\$(OBJ_EXT) types\$(OBJ_EXT)",
     LIBS         => ["-L$POSTGRES_LIB -lpq"],
     AUTHOR       => 'http://gborg.postgresql.org/project/dbdpg/projdisplay.php',
@@ -94,7 +94,6 @@
     PREREQ_PM    => { 'Test::Simple' => '0.17',  # Need Test::More.
                       'Test::Harness' => '2.03', # Need TODO tests.
                     },
-    CCFLAGS      => $comp_opts,
     PERL_MALLOC_OK => 1,
 );
 
