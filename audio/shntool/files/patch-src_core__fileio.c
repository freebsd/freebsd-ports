--- src/core_fileio.c.orig	2009-03-11 17:18:01 UTC
+++ src/core_fileio.c
@@ -110,10 +110,10 @@ bool read_value_long(FILE *file,unsigned
   buf[4] = 0;
 
   if (be_val)
-    *be_val = (buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3];
+    *be_val = ((buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3]) & 0xFFFFFFFF;
 
   if (le_val)
-    *le_val = (buf[3] << 24) | (buf[2] << 16) | (buf[1] << 8) | buf[0];
+    *le_val = ((buf[3] << 24) | (buf[2] << 16) | (buf[1] << 8) | buf[0]) & 0xFFFFFFFF;
 
   if (tag_val)
     tagcpy(tag_val,buf);
