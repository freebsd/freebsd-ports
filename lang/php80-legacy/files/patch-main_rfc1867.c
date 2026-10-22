--- main/rfc1867.c.orig	2026-10-21 15:33:56 UTC
+++ main/rfc1867.c
@@ -390,6 +390,14 @@ static int find_boundary(multipart_buffer *self, char 
 	return 0;
 }
 
+static zend_bool php_mime_should_save_hdr(const char *name)
+{
+	return !strcasecmp(name, "Content-Disposition")
+		|| !strcasecmp(name, "Content-Type");
+}
+
+static char *php_mime_get_hdr_value(zend_llist header, char *key);
+
 /* parse headers */
 static int multipart_buffer_headers(multipart_buffer *self, zend_llist *header)
 {
@@ -430,10 +438,16 @@ static int multipart_buffer_headers(multipart_buffer *
 			}
 
 			*value = '\0';
-			do { value++; } while (isspace(*value));
 
-			key = estrdup(line);
-			smart_string_appends(&buf_value, value);
+			/* Keep only headers we use, and ignore duplicates */
+			if (!php_mime_should_save_hdr(line)
+					|| php_mime_get_hdr_value(*header, line)) {
+				key = NULL;
+			} else {
+				key = estrdup(line);
+				do { value++; } while (isspace((unsigned char)*value));
+				smart_string_appends(&buf_value, value);
+			}
 		} else if (buf_value.c) { /* If no ':' on the line, add to previous line */
 			smart_string_appends(&buf_value, line);
 		} else {
@@ -507,11 +521,11 @@ static char *php_ap_getword(const zend_encoding *encod
 	return res;
 }
 
-static char *substring_conf(char *start, int len, char quote)
+static char *substring_conf(char *start, size_t len, char quote)
 {
 	char *result = emalloc(len + 1);
 	char *resp = result;
-	int i;
+	size_t i;
 
 	for (i = 0; i < len && start[i] != quote; ++i) {
 		if (start[i] == '\\' && (start[i + 1] == '\\' || (quote && start[i + 1] == quote))) {
@@ -539,14 +553,14 @@ static char *php_ap_getword_conf(const zend_encoding *
 		char quote = *str;
 
 		str++;
-		return substring_conf(str, (int)strlen(str), quote);
+		return substring_conf(str, strlen(str), quote);
 	} else {
 		char *strend = str;
 
 		while (*strend && !isspace(*strend)) {
 			++strend;
 		}
-		return substring_conf(str, strend - str, 0);
+		return substring_conf(str, (size_t)(strend - str), 0);
 	}
 }
 
