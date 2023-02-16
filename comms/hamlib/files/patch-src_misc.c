--- src/misc.c.orig	2023-01-01 00:12:52 UTC
+++ src/misc.c
@@ -2581,7 +2581,8 @@ char *date_strget(char *buf, int buflen, int localtime
     if (localtime)
     {
         mytm = localtime_r(&t, &result);
-        mytimezone = timezone;
+	/* For FreeBSD */
+        mytimezone = mytm->tm_gmtoff;
     }
     else
     {
