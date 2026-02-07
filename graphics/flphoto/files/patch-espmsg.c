--- espmsg.c.orig	2005-01-23 03:52:44 UTC
+++ espmsg.c
@@ -766,7 +766,7 @@ translate_messages(const char *language)
     *bufptr++ = '&';
     *bufptr = '\0';
 
-    sprintf(length, "%d", bufptr - buffer);
+    sprintf(length, "%ld", (long)(bufptr - buffer));
 
    /*
     * Send the request...
