--- src/main.c.orig	Fri Jan 30 15:23:48 2004
+++ src/main.c	Fri Jan 30 15:24:10 2004
@@ -200,7 +200,7 @@
 	}
 
 #ifdef HAVE_FPSETMASK
-	fpresetsticky(FP_X_DZ|FP_X_INV);
+	fpsetsticky(FP_X_DZ|FP_X_INV);
 	fpsetmask(FP_X_DZ|FP_X_INV);
 #endif
 	return result;
