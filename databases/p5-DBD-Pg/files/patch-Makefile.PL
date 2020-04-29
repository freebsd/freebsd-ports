--- Makefile.PL.orig	2020-04-18 17:55:08 UTC
+++ Makefile.PL
@@ -212,7 +212,7 @@ my %opts =
     (
      NAME           => 'DBD::Pg',
      VERSION_FROM   => 'Pg.pm',
-     INC            => "-I$POSTGRES_INCLUDE -I$dbi_arch_dir",
+     INC            => "-I$POSTGRES_INCLUDE -I$dbi_arch_dir $comp_opts",
      OBJECT         => 'Pg$(OBJ_EXT) dbdimp$(OBJ_EXT) quote$(OBJ_EXT) types$(OBJ_EXT)',
      LIBS           => ["-L$POSTGRES_LIB -lpq -lm"],
      AUTHOR         => 'Greg Sabino Mullane',
@@ -224,7 +224,6 @@ my %opts =
                         'Time::HiRes'         => '0',
                         'version'             => '0',
                        },
-     CCFLAGS        => $comp_opts,
      PERL_MALLOC_OK => 1,
      NEEDS_LINKING  => 1,
      NO_META        => 1,
