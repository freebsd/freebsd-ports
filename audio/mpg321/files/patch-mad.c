
$FreeBSD$

--- mad.c.orig	Sun Sep 23 08:17:55 2001
+++ mad.c	Mon Sep 24 15:56:20 2001
@@ -554,44 +554,47 @@
     
 int calc_length(char *file, buffer *buf)
 {
-    FILE * f;
+    int f;
     struct stat filestat;
     void *fdm;
     char buffer[3];
 
-    if (stat(file, &filestat) == -1)
+    f = open(file, O_RDONLY);
+
+    if (f < 0)
     {
         mpg321_error(file);
         return -1;
     }
 
-    f = fopen(file, "r");
-
-    if (f == NULL)
+    if (fstat(f, &filestat) < 0)
     {
         mpg321_error(file);
+        close(f);
         return -1;
     }
 
     if (!S_ISREG(filestat.st_mode))
     {
         fprintf(stderr, "%s: Not a regular file\n", file);
-        fclose(f);
+        close(f);
         return -1;
     }
 
     /* TAG checking is adapted from XMMS */
     buf->length = filestat.st_size;
 
-    if (fseek(f, -128, SEEK_END) < 0)
+    if (lseek(f, -128, SEEK_END) < 0)
     {
         mpg321_error(file);
+        close(f);
         return -1;
     }    
 
-    if (read(fileno(f), buffer, 3) != 3)
+    if (read(f, buffer, 3) != 3)
     {
         fprintf(stderr, "Couldnt read 3 bytes from %s\n", file);
+        close(f);
         return -1;
     }
     
@@ -600,12 +603,11 @@
         buf->length -= 128; /* Correct for id3 tags */
     }
     
-    rewind(f);
-
-    fdm = mmap(0, buf->length, PROT_READ, MAP_SHARED, fileno(f), 0);
+    fdm = mmap(0, buf->length, PROT_READ, MAP_SHARED, f, 0);
     if (fdm == MAP_FAILED)
     {
         mpg321_error(file);
+        close(f);
         return -1;
     }
 
@@ -616,11 +618,11 @@
     if (munmap(fdm, buf->length) == -1)
     {
         mpg321_error(file);
-        fclose(f);
+        close(f);
         return -1;
     }
 
-    if (fclose(f) == EOF)
+    if (close(f) < 0)
     {
         mpg321_error(file);
         return -1;
