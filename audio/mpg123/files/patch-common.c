--- common.c.orig	Thu Mar 10 15:33:55 2005
+++ common.c	Thu Mar 10 15:34:53 2005
@@ -137,7 +137,7 @@
 	return FALSE;
     if(!((head>>17)&3))
 	return FALSE;
-    if( ((head>>12)&0xf) == 0xf)
+    if( ((head>>12)&0xf) == 0xf || ((head>>12)&0xf) == 0)
 	return FALSE;
     if( ((head>>10)&0x3) == 0x3 )
 	return FALSE;
@@ -356,9 +356,12 @@
       fr->mpeg25 = 1;
     }
     
-    if (!param.tryresync || !oldhead) {
-          /* If "tryresync" is true, assume that certain
-             parameters do not change within the stream! */
+    if (!param.tryresync || !oldhead ||
+        (((oldhead>>19)&0x3) ^ ((newhead>>19)&0x3))) {
+          /* If "tryresync" is false, assume that certain
+             parameters do not change within the stream!
+	     Force an update if lsf or mpeg25 settings
+	     have changed. */
       fr->lay = 4-((newhead>>17)&3);
       if( ((newhead>>10)&0x3) == 0x3) {
         fprintf(stderr,"Stream error\n");
@@ -525,7 +528,7 @@
 	decodestr(comment,tag->comment,30);
 	decodestr(year,tag->year,4);
 
-	if ( tag->genre <= sizeof(genre_table)/sizeof(*genre_table) ) {
+	if ( tag->genre < sizeof(genre_table)/sizeof(*genre_table) ) {
 		strncpy(genre, genre_table[tag->genre], 30);
 	} else {
 		strncpy(genre,"Unknown",30);
