--- perl-shared/RRDs.xs.orig	Sun May  9 11:07:59 2004
+++ perl-shared/RRDs.xs	Sun May  9 11:08:11 2004
@@ -360,6 +360,6 @@
 			XSRETURN_UNDEF;
 		}
 		EXTEND(sp,2);
-		PUSHs(sv_2mortal(newSVuv(start_tmp)));
-		PUSHs(sv_2mortal(newSVuv(end_tmp)));
+		PUSHs(sv_2mortal(newSViv(start_tmp)));
+		PUSHs(sv_2mortal(newSViv(end_tmp)));
 
