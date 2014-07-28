--- bplexec.c.orig	Thu Feb  9 17:25:34 1995
+++ bplexec.c	Wed Nov 15 20:45:53 2000
@@ -17,6 +17,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
+#include <errno.h>
 
 #include "bpl.h"
 #include "machine.h"
@@ -1096,7 +1097,7 @@
 
 	fname_w_index = strlen(fname_work);
 	if (copy_body(s)) { /* ファイル名異常 */
-		strcpy(fname_work, tmpnam(NULL));
+		strcpy(fname_work, "/tmp/bpl.XXXXXXXXXX");
 	}
 
 	my_free(real_filename);
@@ -1118,16 +1119,19 @@
 	FILE *fp;
 	UCHAR *my_tmp;
 	char *tmp;
+	int fd;
 
-	tmp = tmpnam(NULL);
+	tmp = "/tmp/bpl.XXXXXXXXXX";
 	my_tmp = (UCHAR *) malloc(strlen(tmp) + 1);
 	if (my_tmp == NULL)
 		return NULL;
 	strcpy(my_tmp, tmp);
 
-	fp = fopen(tmp, "wb");
-	if (fp == NULL) {
+	if ((fd = mkstemp(my_tmp)) == -1 ||
+            (fp = fdopen(fd, "wb")) == NULL ) {
+		fprintf(stderr, "%s: %s\n", my_tmp, strerror(errno));
 		free(my_tmp);
+		return NULL;
 	} else {
 		/* ディレクトリは current を使う */
 		strwarn(STR_CANT_CREATE_L); /* 「ファイルが作成できないので」 */
@@ -1136,6 +1140,7 @@
 		strwarn(STR_CANT_CREATE_R);
 		my_free(real_filename);
 		real_filename = my_tmp;
+		close(fd);
 	}
 	return fp;
 }
