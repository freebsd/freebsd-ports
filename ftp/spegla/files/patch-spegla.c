--- spegla.c.orig	Sat May 27 22:38:14 2000
+++ spegla.c	Fri Jan 19 19:36:43 2001
@@ -728,7 +728,7 @@
 #ifdef ULTRIX
 	if ((f.fd_req.bfreen * 1024) < minfree)
 #else
-	if ((f.f_bsize * f.f_bavail) < minfree)
+	if (((long long)f.f_bsize * f.f_bavail) < minfree)
 #endif
 		e_errx(1, "%s: Not enough space left", path);
 
