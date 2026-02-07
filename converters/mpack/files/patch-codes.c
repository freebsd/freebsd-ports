--- codes.c
+++ codes.c
@@ -128,7 +128,7 @@
     int nbytes;
     
     MD5Init(&context);
-    while (nbytes = fread(buf, 1, sizeof(buf), infile)) {
+    while ((nbytes = fread(buf, 1, sizeof(buf), infile))) {
 	length += nbytes;
 	MD5Update(&context, buf, nbytes);
     }
