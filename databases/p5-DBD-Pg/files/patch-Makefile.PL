--- Makefile.PL.orig	2019-04-11 19:14:32 UTC
+++ Makefile.PL
@@ -213,7 +213,7 @@ my %opts =
     (
      NAME           => 'DBD::Pg',
      VERSION_FROM   => 'Pg.pm',
-     INC            => "-I$POSTGRES_INCLUDE -I$dbi_arch_dir",
+     INC            => "-I$POSTGRES_INCLUDE -I$dbi_arch_dir $comp_opts",
      OBJECT         => "Pg\$(OBJ_EXT) dbdimp\$(OBJ_EXT) quote\$(OBJ_EXT) types\$(OBJ_EXT)",
      LIBS           => ["-L$POSTGRES_LIB -lpq -lm"],
      AUTHOR         => 'Greg Sabino Mullane',
@@ -225,7 +225,6 @@ my %opts =
                         'Time::HiRes'         => '0',
                         'version'             => '0',
                        },
-     CCFLAGS        => $comp_opts,
      PERL_MALLOC_OK => 1,
      NEEDS_LINKING  => 1,
      NO_META        => 1,
