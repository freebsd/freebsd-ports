

19 Mai 06:06 2006 diff -u -l converter/other/cameratopam/identify.c.orig converter/other/cameratopam/identify.c Page 1


--- converter/other/cameratopam/identify.c.orig	Sat Aug 27 19:29:58 2005
+++ converter/other/cameratopam/identify.c	Fri May 19 06:06:28 2006
@@ -25,7 +25,7 @@
 
 
 /* This does the same as the function of the same name in the GNU C library */
-static const char *memmem (const char *haystack, size_t haystacklen,
+static const char *memmem_old (const char *haystack, size_t haystacklen,
                      const char *needle, size_t needlelen)
 {
   const char *c;
@@ -316,7 +316,7 @@
   fread (head, 1, 32, ifp);
   fseek (ifp, 0, SEEK_END);
   fsize = ftell(ifp);
-  if ((c = (char*)memmem (head, 32, "MMMMRawT", 8))) {
+  if ((c = (char*)memmem_old (head, 32, "MMMMRawT", 8))) {
     strcpy (make, "Phase One");
     data_offset = c - head;
     fseek (ifp, data_offset + 8, SEEK_SET);

