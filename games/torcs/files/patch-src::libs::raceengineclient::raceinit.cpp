--- ./src/libs/raceengineclient/raceinit.cpp.orig	Fri Feb  4 23:29:59 2005
+++ ./src/libs/raceengineclient/raceinit.cpp	Mon Feb 28 19:23:32 2005
@@ -42,6 +42,19 @@
 
 #include "raceinit.h"
 
+#if defined(__FreeBSD__)
+static char *strndup(const char *str, int len) {
+	char *ret;
+
+	if ((str == NULL || len < 0)) return(NULL);
+	ret = (char *)malloc(len + 1);
+	if (ret == NULL) return(NULL);
+	memcpy(ret, str, len);
+	ret[len] = '\0';
+	return(ret);
+}
+#endif
+
 static char *level_str[] = { ROB_VAL_ROOKIE, ROB_VAL_AMATEUR, ROB_VAL_SEMI_PRO, ROB_VAL_PRO };
 
 static tModList *reEventModList = 0;
