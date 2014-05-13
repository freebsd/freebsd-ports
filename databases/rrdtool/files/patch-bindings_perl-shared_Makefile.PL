--- bindings/perl-shared/Makefile.PL.orig	2014-04-19 13:00:18.000000000 +0200
+++ bindings/perl-shared/Makefile.PL	2014-04-19 13:13:26.000000000 +0200
@@ -31,7 +31,7 @@
 			/linux/   && do{ $R = "-Wl,--rpath -Wl,$rp"};
 			/hpux/    && do{ $R = "+b$rp"};
 			/solaris/ && do{ $R = "-R$rp"};
-			/bsd/     && do{ $R = "-R$rp"};
+			/bsd/     && do{ $R = "-Wl,--rpath -Wl,$rp"};
 			/aix/     && do{ $R = "-blibpath:$rp"};
 		}
 	}
