--- vmsbackup.c.orig	1997-08-13 21:48:43.000000000 +0000
+++ vmsbackup.c
@@ -55,8 +55,8 @@
 #endif
 #ifdef REMOTE
 #include	<local/rmt.h>
-#include	<sys/stat.h>
 #endif
+#include	<sys/stat.h>
 #include	<sys/file.h>
 
 #if 0
@@ -300,7 +300,7 @@ char	*fn;
 	if(procf && wflag) {
 		printf("extract %s [ny]",filename);
 		fflush(stdout);
-		gets(ans);
+		fgets(ans, 80, stdin);
 		if(*ans != 'y') procf = 0;
 	}
 	if(procf)
@@ -757,6 +757,7 @@ size_t rsize;
  *  process a virtual block record (file record)
  *
  */
+void
 process_vbn(buffer, rsize)
 char		*buffer;
 unsigned short	rsize;
