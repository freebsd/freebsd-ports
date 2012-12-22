--- ./espmsg.c.orig	2005-01-23 04:52:44.000000000 +0100
+++ ./espmsg.c	2012-12-22 12:41:39.000000000 +0100
@@ -766,7 +766,7 @@
     *bufptr++ = '&';
     *bufptr = '\0';
 
-    sprintf(length, "%d", bufptr - buffer);
+    sprintf(length, "%ld", (long)(bufptr - buffer));
 
    /*
     * Send the request...
