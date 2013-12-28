--- ./maclib/Mac_Sound.h.orig	2002-10-20 04:53:34.000000000 +0200
+++ ./maclib/Mac_Sound.h	2013-12-28 11:39:16.000000000 +0100
@@ -199,7 +199,7 @@
 		va_list ap;
 
 		va_start(ap, fmt);
-		vsprintf(errbuf, fmt, ap);
+		vsnprintf(errbuf, sizeof(errbuf), fmt, ap);
 		va_end(ap);
 		errstr = errbuf;
 	}
