--- plugins/ripperX_plugin-oggenc.c.orig	2006-12-10 07:13:15 UTC
+++ plugins/ripperX_plugin-oggenc.c
@@ -1,5 +1,3 @@
-// strndup is a GNU extension:
-#define _GNU_SOURCE
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
@@ -9,6 +7,21 @@
 #define OGG_OUTPUT_BUF_LENGTH 	2048
 #define PRINTOUT_INTERVAL	0.5
 
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
+
 void 
 strip_shit(char* input, int len) {
 	int i;
