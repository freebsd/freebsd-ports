--- client.c.orig	Sat Dec 29 09:40:48 2001
+++ client.c	Mon Mar  4 21:42:05 2002
@@ -277,12 +277,12 @@
       int packet_len, command;
       char data[BUF_SIZE];
 
-      if (!get_data (s, &packet_len, 4)) {
+      if (!get_data (s, (char *)&packet_len, 4)) {
 	printf ("packet_len read failed\n");
 	return 0;
       }
       
-      packet_len = get_32 (&packet_len, 0) + 4;
+      packet_len = get_32 ((unsigned char *)&packet_len, 0) + 4;
       
       printf ("command packet detected, len=%d\n",
 	      packet_len);
@@ -308,7 +308,7 @@
 int interp_header (uint8_t *header, int header_len) {
 
   int i;
-  int packet_length;
+  int packet_length = 0;
 
   /*
    * parse header
@@ -416,12 +416,12 @@
 
     int packet_len, command;
 
-    if (!get_data (s, &packet_len, 4)) {
+    if (!get_data (s, (char *)&packet_len, 4)) {
       printf ("packet_len read failed\n");
       return 0;
     }
 
-    packet_len = get_32 (&packet_len, 0) + 4;
+    packet_len = get_32 ((unsigned char *)&packet_len, 0) + 4;
 
     printf ("command packet detected, len=%d\n",
 	    packet_len);
