--- header.c.orig	Sun Oct 30 23:37:49 2005
+++ header.c	Sun Oct 30 23:38:13 2005
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
