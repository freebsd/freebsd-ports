--- ./screenlib/SDL_FrameBuf.h.orig	2000-09-24 19:55:39.000000000 +0200
+++ ./screenlib/SDL_FrameBuf.h	2013-12-28 11:39:16.000000000 +0100
@@ -165,7 +165,7 @@
 		va_list ap;
 
 		va_start(ap, fmt);
-		vsprintf(errbuf, fmt, ap);
+		vsnprintf(errbuf, sizeof(errbuf), fmt, ap);
 		va_end(ap);
 		errstr = errbuf;
         }
