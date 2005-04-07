--- Makefile.PL.orig	Tue Apr  5 03:50:36 2005
+++ Makefile.PL	Thu Apr  7 10:34:20 2005
@@ -83,12 +83,12 @@
   }
 }
 
-my $comp_opts = $Config{q{ccflags}} . " -DPGLIBVERSION=$serverversion";
+my $comp_opts = " -DPGLIBVERSION=$serverversion";
 
 my %opts = (
     NAME         => 'DBD::Pg',
     VERSION_FROM => 'Pg.pm',
-    INC          => "-I$POSTGRES_INCLUDE -I$dbi_arch_dir",
+    INC          => "-I$POSTGRES_INCLUDE -I$dbi_arch_dir $comp_opts",
     OBJECT       => "Pg\$(OBJ_EXT) dbdimp\$(OBJ_EXT) quote\$(OBJ_EXT) types\$(OBJ_EXT)",
     LIBS         => ["-L$POSTGRES_LIB -lpq"],
     AUTHOR       => 'http://gborg.postgresql.org/project/dbdpg/',
@@ -96,7 +96,6 @@
     PREREQ_PM    => { 'Test::Simple' => '0.17',  # Need Test::More.
                       'Test::Harness' => '2.03', # Need TODO tests.
                     },
-    CCFLAGS      => $comp_opts,
     PERL_MALLOC_OK => 1,
     clean        => { FILES => 'trace' },
 );
