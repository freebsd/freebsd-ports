--- Makefile.PL.orig	2010-11-22 00:55:41 UTC
+++ Makefile.PL
@@ -196,7 +196,7 @@
     (
      NAME           => 'DBD::Pg',
      VERSION_FROM   => 'Pg.pm',
-     INC            => "-I$POSTGRES_INCLUDE -I$dbi_arch_dir",
+     INC            => "-I$POSTGRES_INCLUDE -I$dbi_arch_dir $comp_opts",
      OBJECT         => "Pg\$(OBJ_EXT) dbdimp\$(OBJ_EXT) quote\$(OBJ_EXT) types\$(OBJ_EXT)",
      LIBS           => ["-L$POSTGRES_LIB -lpq -lm"],
      AUTHOR         => 'Greg Sabino Mullane',
@@ -207,7 +207,6 @@
                         'Test::More'          => '0.61',
                         'version'             => '0',
                        },
-     CCFLAGS        => $comp_opts,
      PERL_MALLOC_OK => 1,
      NEEDS_LINKING  => 1,
      NO_META        => 1,
