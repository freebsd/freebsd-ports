--- ./maclib/Mac_Wave.h.orig	2000-01-25 17:44:10.000000000 +0100
+++ ./maclib/Mac_Wave.h	2013-12-28 11:39:16.000000000 +0100
@@ -108,7 +108,7 @@
 		va_list ap;
 
 		va_start(ap, fmt);
-		vsprintf(errbuf, fmt, ap);
+		vsnprintf(errbuf, sizeof(errbuf), fmt, ap);
 		va_end(ap);
 		errstr = errbuf;
 	}
