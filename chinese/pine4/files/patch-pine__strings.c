--- pine/strings.c~	Tue Jan  9 01:05:11 2001
+++ pine/strings.c	Tue Jan  9 01:05:47 2001
@@ -2811,7 +2811,7 @@
 rfc1522_valenc(c)
     int c;
 {
-    return(!(c == '?' || c == SPACE) && isprint((unsigned char)c));
+    return c ;
 }
 
 
