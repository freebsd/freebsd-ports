--- ./maclib/Mac_FontServ.h.orig	1999-12-02 18:15:33.000000000 +0100
+++ ./maclib/Mac_FontServ.h	2013-12-28 11:39:16.000000000 +0100
@@ -135,7 +135,7 @@
 		va_list ap;
 
 		va_start(ap, fmt);
-		vsprintf(errbuf, fmt, ap);
+		vsnprintf(errbuf, sizeof(errbuf), fmt, ap);
 		va_end(ap);
 		errstr = errbuf;
 	}
