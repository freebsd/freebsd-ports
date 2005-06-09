--- gzrecover.c.orig	Sat Sep  4 19:55:08 2004
+++ gzrecover.c	Wed Jun  8 21:53:49 2005
@@ -20,6 +20,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <errno.h>
@@ -85,10 +86,14 @@
   static int suffix = 1;
 
   /* Build the output file name */
-  if (outfile_specified)
-    check_error(0, outfile = (char *)malloc(strlen(user_outname) + 9), "malloc");
-  else
-    check_error(0, outfile = (char *)malloc(strlen(infile) + 25), "malloc"); 
+  if (outfile_specified) {
+    outfile = (char *)malloc(strlen(user_outname) + 9);
+    check_error(0, (int)outfile, "malloc");
+  }
+  else {
+  	outfile = (char *)malloc(strlen(infile) + 25);
+    check_error(0, (int)outfile, "malloc"); 
+  }
     
   if (!outfile_specified) /* Strip of .gz unless user specified name */
    {
@@ -223,7 +228,8 @@
   infile = argv[optind];
 
   /* Open input file and memory map */
-  check_error(0, inbuf = (char *)malloc(inbuf_size), "malloc");
+  inbuf = (char *)malloc(inbuf_size);
+  check_error(0, (int)inbuf, "malloc");
   check_error(-1, ifd = open(infile, O_RDONLY), "open");
 
   if (verbose_mode)
@@ -231,7 +237,8 @@
 
   /* Open output file & initialize output buffer */
   ofd = open_outfile(infile);
-  check_error(0, outbuf = (char *)malloc(outbuf_size), "malloc");
+  outbuf = (char *)malloc(outbuf_size);
+  check_error(0, (int)outbuf, "malloc");
 
   /* Initialize zlib */
   check_error(-1, bytes_read = read_internal(ifd, inbuf, inbuf_size), "read");
