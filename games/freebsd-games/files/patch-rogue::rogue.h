$FreeBSD$

--- rogue/rogue.h	17 Dec 2001 12:43:23 -0000	1.3.2.1
+++ rogue/rogue.h	21 Aug 2003 20:04:36 -0000
@@ -194,9 +194,12 @@
 
 #define MAX_OPT_LEN 40
 
+#define HUNGER_STR_LEN 8
+
+#define MAX_ID_TITLE_LEN 64
 struct id {
 	short value;
-	char *title;
+	char title[MAX_ID_TITLE_LEN];
 	char *real;
 	unsigned short id_status;
 };
@@ -472,3 +475,9 @@
 	short second;	/* 0 - 59 */
 };
 
+/*
+ * external routine declarations.
+ */
+extern  char    hunger_str[HUNGER_STR_LEN];
+extern  char    login_name[MAX_OPT_LEN];
+extern  const char   *error_file;
