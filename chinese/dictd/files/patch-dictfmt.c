--- dictfmt.c.orig	Sun Nov 24 01:25:09 2002
+++ dictfmt.c	Sun Nov 24 01:25:23 2002
@@ -208,6 +208,12 @@
 
    while (src && src [0]){
       ch = *(const unsigned char *)src;
+      if((ch & 0x80) && *(src+1)) {
+	 *dest++ = ch;
+	 *dest++ = *(src+1);
+	 src+=2;
+	 continue;
+      }
 
       if (isspace (ch)){
 	 *dest++ = ' ';
