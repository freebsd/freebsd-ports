--- dictfmt.c.orig	Tue Feb 11 03:08:33 2003
+++ dictfmt.c	Mon Oct 27 22:03:33 2003
@@ -213,6 +213,12 @@
 
    while (src && src [0]){
       ch = *(const unsigned char *)src;
+      if((ch & 0x80) && *(src+1)) {
+        *dest++ = ch;
+        *dest++ = *(src+1);
+        src+=2;
+        continue;
+      }
 
       if (isspace (ch)){
 	 *dest++ = ' ';
