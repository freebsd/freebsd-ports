--- Makefile.PL.orig	2015-05-07 17:56:22 UTC
+++ Makefile.PL
@@ -54,7 +54,7 @@ if (my $gccversion = $Config{gccversion}
         $opts{DEFINE} .= ' -Wmissing-prototypes';
     }
 }
-$opts{LIBS} = ["-lstdc++"]; # else error: libmemcached.so: undefined symbol: __gxx_personality_v0
+$opts{LIBS} = ["-lc++"]; # else error: libmemcached.so: undefined symbol: __gxx_personality_v0
 $opts{OPTIMIZE} = "-g"  if $opt_g;
 $opts{CCFLAGS}  = "-pg" if $opt_pg;
 my $coverage_flags = "";
