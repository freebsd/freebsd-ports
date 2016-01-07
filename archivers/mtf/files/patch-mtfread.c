--- mtfread.c.orig	2000-09-13 15:14:33 UTC
+++ mtfread.c
@@ -42,7 +42,11 @@ See mtf.c for version history, contribut
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
@@ -363,7 +367,7 @@ INT32 readTapeBlock(void)
 	{
 		stream = (MTF_STREAM_HDR*) ((char*) tape + dbHdr->off);
 		result = skipToNextBlock();
-		if (result != 1)
+		if (result != 0) /* skipToNextBlock returns 0 upon success -1 otherwise */
 		{
 			fprintf(stderr, "Error traversing to end of descriptor block!\n");
 			return(-1);
@@ -671,7 +675,8 @@ INT32 readFileBlock(void)
 	INT32 result;
 	char *ptr, *ptr2, filePath[MAXPATHLEN + 1], fullPath[MAXPATHLEN + 1];
 	char tmpPath[MAXPATHLEN + 1];
-	int i, output;
+	int i;
+	int output=-1; /* Initialized to avoid gcc warning */
 	struct tm tbuf;
 	struct utimbuf utbuf;
 	UINT32 threshold;
