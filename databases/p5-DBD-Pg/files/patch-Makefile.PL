--- Makefile.PL.orig	Thu Apr 20 19:25:49 2006
+++ Makefile.PL	Thu Apr 20 19:26:54 2006
@@ -96,7 +96,7 @@
   }
 }
 
-my $comp_opts = $Config{q{ccflags}} . " -DPGLIBVERSION=$serverversion -DPGDEFPORT=$defaultport";
+my $comp_opts = " -DPGLIBVERSION=$serverversion -DPGDEFPORT=$defaultport";
 
 if ($ENV{DBDPG_GCCDEBUG}) {
 	warn "Enabling many compiler options\n";
@@ -120,7 +120,7 @@
 	(
 	 NAME           => 'DBD::Pg',
 	 VERSION_FROM   => 'Pg.pm',
-	 INC            => "-I$POSTGRES_INCLUDE -I$dbi_arch_dir",
+	 INC            => "-I$POSTGRES_INCLUDE -I$dbi_arch_dir $comp_opts",
 	 OBJECT         => "Pg\$(OBJ_EXT) dbdimp\$(OBJ_EXT) quote\$(OBJ_EXT) types\$(OBJ_EXT)",
 	 LIBS           => ["-L$POSTGRES_LIB -lpq"],
 	 AUTHOR         => 'http://gborg.postgresql.org/project/dbdpg/',
@@ -130,7 +130,6 @@
 						'Test::Simple' => '0.30',
 						'Test::Harness' => '2.03',
 					   },
-	 CCFLAGS        => $comp_opts,
 	 PERL_MALLOC_OK => 1,
 	 NEEDS_LINKING  => 1,
 	 clean          => { FILES => 'trace Pg.xsi' },
