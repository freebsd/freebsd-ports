--- ./bindings/perl-shared/Makefile.PL.orig	2008-09-22 09:26:55.000000000 +0800
+++ ./bindings/perl-shared/Makefile.PL	2008-09-22 09:27:28.000000000 +0800
@@ -14,6 +14,7 @@
 	        /linux/   && do{ $R = "-Wl,--rpath -Wl,$rp"};
 	        /hpux/    && do{ $R = "+b$rp"};
 	        /solaris/ && do{ $R = "-R$rp"};
+		/bsd/     && do{ $R = "-R$rp"}; 
                 /aix/     && do{ $R = "-Wl,-blibpath:$rp"};
 	}
 }
