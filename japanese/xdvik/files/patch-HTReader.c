--- xdvik-22.15/libs/libwww/HTReader.c.orig	Tue Jan 19 17:56:33 1999
+++ xdvik-22.15/libs/libwww/HTReader.c	Wed Jan 16 06:36:58 2002
@@ -60,6 +60,7 @@
     return HT_ERROR;
 }
 
+#ifdef FIND_SIGNATURE
 /*	Push data from a socket down a stream
 **	-------------------------------------
 **
@@ -76,7 +77,7 @@
 **     		HT_WOULD_BLOCK	if read or write would block
 **		HT_PAUSE	if stream is paused
 */
-char * strnstr(char * haystack, int *pLen, char * needle)
+PRIVATE char * strnstr(char * haystack, int *pLen, char * needle)
 {
     int found = 0;
     int need = strlen(needle);
@@ -94,6 +95,7 @@
     *pLen = 0;
     return NULL;
 }
+#endif
 
 /* int DebugBufferSize = INPUT_BUFFER_SIZE; */
 
