--- zphoto.c.orig	Sat Apr 10 18:12:30 2004
+++ zphoto.c	Mon Apr 12 09:48:26 2004
@@ -1308,8 +1308,8 @@
     fp = zphoto_efopen(file_name, "r");
 
     while (fgets(buf, BUFSIZ, fp)) {
-        buf[strcspn(buf, "\r\n")] = '\0'; /* chomp */
         char *sep, *file_name, *caption;
+        buf[strcspn(buf, "\r\n")] = '\0'; /* chomp */
         if (buf[0] == '#')
             continue;
         if ((sep = strchr(buf, '\t'))) {
