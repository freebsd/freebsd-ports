--- Makefile.PL.orig	2026-08-26 19:57:11 UTC
+++ Makefile.PL
@@ -232,7 +232,7 @@ my %opts =
     (
      NAME           => 'DBD::Pg',
      VERSION_FROM   => 'Pg.pm',
-     INC            => qq{-I"$POSTGRES_INCLUDE" -I"$dbi_arch_dir"},
+     INC            => qq{-I"$POSTGRES_INCLUDE" -I"$dbi_arch_dir" $comp_opts},
      OBJECT         => 'Pg$(OBJ_EXT) dbdimp$(OBJ_EXT) quote$(OBJ_EXT) types$(OBJ_EXT) strbuf$(OBJ_EXT)',
      LIBS           => ["-L\"$POSTGRES_LIB\" -lpq -lm"],
      AUTHOR         => 'Greg Sabino Mullane',
@@ -245,7 +245,6 @@ my %opts =
                         'Time::HiRes'         => '0',
                         'version'             => '0',
                        },
-     CCFLAGS        => $comp_opts,
      PERL_MALLOC_OK => 1,
      NEEDS_LINKING  => 1,
      NO_META        => 1,
