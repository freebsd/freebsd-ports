--- ./src/base64.c.orig	2012-01-29 13:01:09.956709152 +0100
+++ ./src/base64.c	2012-01-29 13:17:28.106706024 +0100
@@ -104,9 +104,9 @@
 
 unsigned char *base64decode(const char *buf, size_t *size)
 {
-	if (!buf) return;
+	if (!buf) return NULL;
 	size_t len = strlen(buf);
-	if (len <= 0) return;
+	if (len <= 0) return NULL;
 	unsigned char *outbuf = (unsigned char*)malloc((len/4)*3+3);
 
 	unsigned char *line;
