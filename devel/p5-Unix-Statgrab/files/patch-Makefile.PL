--- Makefile.PL.bak	Sun Jun 20 22:44:53 2004
+++ Makefile.PL	Sun Jun 20 22:45:05 2004
@@ -7,7 +7,7 @@
     my %args = map { split /\s*=\s*/ } @ARGV;
     my $LIBS = $args{ LIBS } || "-lstatgrab";
     my $INC = $args{ INC };
-    return 1 if system("$CC check.c $INC $LIBS -o /dev/null 2>/dev/null") == 0;
+    return 1 if system("$CC check.c $INC $LIBS 2>/dev/null") == 0;
     return 0;
 }
 
