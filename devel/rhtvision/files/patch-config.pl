--- config.pl.orig	2026-06-21 20:07:49 UTC
+++ config.pl
@@ -1254,7 +1254,7 @@ sub GenerateMakefile
     # Darwin: doesn't have ldconfig.
     if ($OSf ne 'Darwin')
       {
-       $rep.=($OSf eq 'FreeBSD') ? "\t-ldconfig -m \$(libdir)\n" : "\t-ldconfig\n";
+#       $rep.=($OSf eq 'FreeBSD') ? "\t-ldconfig -m \$(libdir)\n" : "\t-ldconfig\n";
       }
    }
  if ($internac)
