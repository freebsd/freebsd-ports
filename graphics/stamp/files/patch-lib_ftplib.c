--- lib/ftplib.c.orig	2021-08-17 12:18:12 UTC
+++ lib/ftplib.c
@@ -77,6 +77,7 @@ static char *version =
     "ftplib Release 3 12/xx/97, copyright 1996, 1997 Thomas Pfau";
 
 GLOBALDEF int ftplib_debug = 0;
+netbuf *DefaultNetbuf;
 
 #if defined(__unix__) || defined(VMS)
 #define net_read read
