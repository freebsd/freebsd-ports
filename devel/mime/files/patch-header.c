--- ./header.c.orig	2003-09-16 01:37:19.000000000 +0200
+++ ./header.c	2014-02-18 11:11:32.980337829 +0100
@@ -67,7 +67,7 @@
 	alc = 0;
 
 	while (value < end) {
-		crlf = memmem(value, end - value, crlfpair, strlen(crlfpair));
+		crlf = memmemory(value, end - value, crlfpair, strlen(crlfpair));
 		if (crlf == NULL)
 			goto fv_error;
 
@@ -123,7 +123,7 @@
 		 * header line
 		 */
 		colon = memchr(header, ':', end - header);
-		crlf = memmem(header, end - header, crlfpair, strlen(crlfpair));
+		crlf = memmemory(header, end - header, crlfpair, strlen(crlfpair));
 
 		if (colon == NULL || crlf == NULL || colon > crlf)
 			goto mph_error;
