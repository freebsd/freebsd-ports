
$FreeBSD$

--- proto.h.orig	Fri Dec 14 06:57:10 2001
+++ proto.h	Tue Dec 18 19:58:04 2001
@@ -65,7 +65,9 @@
 
 /* Programs we want available */
 
+#ifndef HAVE_STRCASESTR
 char *strcasestr(char *haystack, char *needle);
+#endif
 char *strstrwrapper(char *haystack, char *needle);
 int search_init(int replacing);
 int renumber(filestruct * fileptr);
