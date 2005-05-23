--- Makefile.PL.orig	Sat May 21 16:43:17 2005
+++ Makefile.PL	Mon May 23 13:32:05 2005
@@ -85,13 +85,13 @@
   }
 }
 
-my $comp_opts = $Config{q{ccflags}} . " -DPGLIBVERSION=$serverversion";
+my $comp_opts = " -DPGLIBVERSION=$serverversion";
 
 my %opts = 
 	(
 	 NAME           => 'DBD::Pg',
 	 VERSION_FROM   => 'Pg.pm',
-	 INC            => "-I$POSTGRES_INCLUDE -I$dbi_arch_dir",
+	 INC            => "-I$POSTGRES_INCLUDE -I$dbi_arch_dir $comp_opts",
 	 OBJECT         => "Pg\$(OBJ_EXT) dbdimp\$(OBJ_EXT) quote\$(OBJ_EXT) types\$(OBJ_EXT)",
 	 LIBS           => ["-L$POSTGRES_LIB -lpq"],
 	 AUTHOR         => 'http://gborg.postgresql.org/project/dbdpg/',
@@ -99,7 +99,6 @@
 	 PREREQ_PM      => { 'Test::Simple' => '0.17',  # Need Test::More.
 											 'Test::Harness' => '2.03', # Need TODO tests.
 									 },
-	 CCFLAGS        => $comp_opts,
 	 PERL_MALLOC_OK => 1,
 	 NEEDS_LINKING  => 1,
 	 clean          => { FILES => 'trace' },
