--- e_err.c.orig	Sun May 14 23:39:39 2000
+++ e_err.c	Thu Feb  1 15:38:37 2001
@@ -115,6 +115,7 @@
 	}
 
 	res = vsnprintf(p, len, fmt, args);
+	if (res >= len) res = len - 1;
 	len -= res;
 	p += res;
 
