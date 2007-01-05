--- plugins/ripperX_plugin-oggenc.c.orig	Wed Jan  3 20:15:49 2007
+++ plugins/ripperX_plugin-oggenc.c	Wed Jan  3 20:22:39 2007
@@ -1,5 +1,3 @@
-// strndup is a GNU extension:
-#define _GNU_SOURCE
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
@@ -8,6 +6,21 @@
 
 #define OGG_OUTPUT_BUF_LENGTH 	2048
 #define PRINTOUT_INTERVAL	0.5
+
+char
+*strndup(const char *string, size_t n)
+{
+	char *ret = malloc(n + 1);
+
+	if (ret == NULL)
+		return NULL;
+	
+	strncpy(ret, string, n);
+
+	ret[n] = '\0';
+
+	return ret;
+}
 
 void 
 strip_shit(char* input, int len) {
