--- gmp3info.c.orig	Mon Jul 16 04:17:16 2001
+++ gmp3info.c	Sun Mar 14 22:10:09 2004
@@ -484,12 +484,12 @@
 }
 
 void about_mp3info(void) {
-	quick_popup(VERSION,"MP3Info
-			An ID3 Tag Editor\n\n
-			Original author: Ricardo Cerqueira <rmc@plug.pt>
-			Current maintainer: Cedric Tefft <cedric@earthling.net>
-			GTK Version: Ricardo Cerqueira <rmc@plug.pt>\n\n
-			Ricardo Cerqueira, Cedric Tefft   1999-2001\n\n");
+	quick_popup(VERSION,"MP3Info"
+"			An ID3 Tag Editor\n\n"
+"			Original author: Ricardo Cerqueira <rmc@plug.pt>"
+"			Current maintainer: Cedric Tefft <cedric@earthling.net>"
+"			GTK Version: Ricardo Cerqueira <rmc@plug.pt>\n\n"
+"			Ricardo Cerqueira, Cedric Tefft   1999-2001\n\n");
 }
 
 /* rmcc has left the building */
