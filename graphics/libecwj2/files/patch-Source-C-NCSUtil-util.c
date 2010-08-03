--- Source/C/NCSUtil/util.c.orig	2009-04-05 21:59:28.000000000 +0400
+++ Source/C/NCSUtil/util.c	2009-04-05 22:05:04.000000000 +0400
@@ -163,15 +163,9 @@
 	if(nSizeBytes < 1024) {
 #ifdef WIN32
 		sprintf(buf, "%I64d bytes", nSizeBytes);
-#elif defined SOLARIS
-		sprintf(buf, "%lld bytes", nSizeBytes);
 #elif defined MACINTOSH
 		sprintf(buf, "%I64d bytes", nSizeBytes);
-#elif defined HPUX
-		sprintf(buf, "%lld bytes", nSizeBytes);
-#elif defined LINUX
-		sprintf(buf, "%lld bytes", nSizeBytes);
-#elif defined MACOSX
+#elif defined POSIX
 		sprintf(buf, "%lld bytes", nSizeBytes);
 #else
 #error whats the 64bit format specifier?
@@ -306,6 +300,10 @@
 
 	return(NCS_MACINTOSH_OSX);
 
+#elif defined FREEBSD
+
+	return(NCS_FREEBSD);
+
 #else	/* WIN32 */
 #error - NCSGetPlatform()
 #endif	/* WIN32 */
