--- lib/urldata.h.orig	Fri May  9 00:39:29 2003
+++ lib/urldata.h	Sun Jun 15 18:57:46 2003
@@ -501,7 +501,7 @@
 struct PureInfo {
   int httpcode;
   int httpversion;
-  long filetime; /* If requested, this is might get set. Set to -1 if
+  time_t filetime; /* If requested, this is might get set. Set to -1 if
                     the time was unretrievable */
   long header_size;  /* size of read header(s) in bytes */
   long request_size; /* the amount of bytes sent in the request(s) */
