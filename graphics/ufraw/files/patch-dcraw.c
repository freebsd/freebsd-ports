--- dcraw.c.orig	Thu Sep 15 19:24:38 2005
+++ dcraw.c	Thu Oct 27 21:16:01 2005
@@ -188,7 +188,7 @@
 	3 G R G R G R	3 B G B G B G	3 R G R G R G	3 G B G B G B
  */
 
-#ifndef __GLIBC__
+#if !defined(__GLIBC__) && !defined(__FreeBSD__)
 char *memmem (char *haystack, size_t haystacklen,
 	      char *needle, size_t needlelen)
 {
