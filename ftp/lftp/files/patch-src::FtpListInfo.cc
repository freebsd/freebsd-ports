--- src/FtpListInfo.cc.orig	Thu Apr  8 23:53:22 2004
+++ src/FtpListInfo.cc	Thu Apr  8 23:53:35 2004
@@ -788,7 +788,7 @@
       }
       if(!strncasecmp(tok,"Size=",5))
       {
-	 size=atoll(tok+5);
+	 size=strtoll(tok+5, NULL, 10);
 	 continue;
       }
       if(!strncasecmp(tok,"Perm=",5))
