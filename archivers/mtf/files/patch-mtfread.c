--- mtfread.c.orig	Wed Sep 13 23:14:33 2000
+++ mtfread.c	Wed Jun 26 14:28:48 2002
@@ -42,7 +42,11 @@
 #include <limits.h>
 #include <sys/stat.h>
 #include <sys/fcntl.h>
+#if defined(BSD)
+#include <sys/mount.h>
+#else
 #include <sys/vfs.h>
+#endif
 #include <utime.h>
 #include <unistd.h>
 #include <time.h>
@@ -363,7 +367,7 @@
 	{
 		stream = (MTF_STREAM_HDR*) ((char*) tape + dbHdr->off);
 		result = skipToNextBlock();
-		if (result != 1)
+		if (result != 0) /* skipToNextBlock returns 0 upon success -1 otherwise */
 		{
 			fprintf(stderr, "Error traversing to end of descriptor block!\n");
 			return(-1);
@@ -671,7 +675,8 @@
 	INT32 result;
 	char *ptr, *ptr2, filePath[MAXPATHLEN + 1], fullPath[MAXPATHLEN + 1];
 	char tmpPath[MAXPATHLEN + 1];
-	int i, output;
+	int i;
+	int output=-1; /* Initialized to avoid gcc warning */
 	struct tm tbuf;
 	struct utimbuf utbuf;
 	UINT32 threshold;
