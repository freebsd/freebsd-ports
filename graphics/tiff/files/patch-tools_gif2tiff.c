CVE-2016-3186, patch from:
https://bugzilla.redhat.com/show_bug.cgi?id=1319666

--- tools/gif2tiff.c.orig	Fri Jul  1 13:11:43 2016
+++ tools/gif2tiff.c	Fri Jul  1 13:12:07 2016
@@ -349,7 +349,7 @@ readextension(void)
     int status = 1;
 
     (void) getc(infile);
-    while ((count = getc(infile)) && count <= 255)
+    while ((count = getc(infile)) && count >= 0 && count <= 255)
         if (fread(buf, 1, count, infile) != (size_t) count) {
             fprintf(stderr, "short read from file %s (%s)\n",
                     filename, strerror(errno));
