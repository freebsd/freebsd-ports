--- maclib/Mac_Resource.h.orig	1999-12-03 19:01:47.000000000 +0100
+++ maclib/Mac_Resource.h	2013-03-16 10:47:19.000000000 +0100
@@ -96,7 +96,7 @@
 		va_list ap;
 
 		va_start(ap, fmt);
-		vsprintf(errbuf, fmt, ap);
+		vsnprintf(errbuf, sizeof(errbuf), fmt, ap);
 		va_end(ap);
 		errstr = errbuf;
 	}
