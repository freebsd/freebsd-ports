--- ffmpeg-strip-wma/asf.c.orig	Sun Jul 11 06:51:15 2004
+++ ffmpeg-strip-wma/asf.c	Sun Jul 11 06:53:34 2004
@@ -18,8 +18,6 @@
  */
 #include "avformat.h"
 #include "avi.h"
-//#include "mpegaudio.h"
-#include <iconv.h>
 
 #undef NDEBUG
 #include <assert.h>
@@ -830,6 +828,7 @@
     return str;
 }
 
+/*
 static void tag_recode(char *before, int len)
 {
        int result;
@@ -859,21 +858,22 @@
 		return;
        return;
 }
+*/
 
 static void get_str16_nolen(ByteIOContext *pb, int len, char *buf, int buf_size)
 {
-    int c, lenz;
+    int c;
     char *q;
 
     q = buf;
-    lenz = len;
     while (len > 0) {
-        c = get_byte(pb);
-        if ((q - buf) < buf_size-1)
-            *q++ = c;
-        len--;
-    }
-    tag_recode(buf, lenz);
+    	c = get_le16(pb);
+	if ((q - buf) < buf_size - 1)
+		*q++ = c;
+	len-=2;
+    	}
+	
+    *q = '\0';				   
 }
 
 static int asf_probe(AVProbeData *pd)
