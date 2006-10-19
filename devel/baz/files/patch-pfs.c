diff -uN -r src/baz/libarch/pfs.c src/baz/libarch/pfs.c
--- src/baz/libarch/pfs.c	2005-06-20 23:59:37.000000000 +0200
+++ src/baz/libarch/pfs.c	2006-01-14 17:12:24.000000000 +0100
@@ -520,6 +520,66 @@
     parsed_uri->host = str_replace (parsed_uri->host, str_save (0, at_pos + 1));
 }
 
+/* RFC2396 spake:
+ * "Data must be escaped if it does not have a representation 
+ * using an unreserved character".
+ */
+
+/* Lookup table: character classes from 2396. (This is overkill) */
+
+#define SP 0   /* space    = <US-ASCII coded character 20 hexadecimal>                 */
+#define CO 0   /* control  = <US-ASCII coded characters 00-1F and 7F hexadecimal>      */
+#define DE 0   /* delims   = "<" | ">" | "#" | "%" | <">                               */
+#define UW 0   /* unwise   = "{" | "}" | "|" | "\" | "^" | "[" | "]" | "`"             */
+#define MA 1   /* mark     = "-" | "_" | "." | "!" | "~" | "*" | "'" | "(" | ")"       */
+#define AN 2   /* alphanum = alpha | digit                                             */
+#define RE 2   /* reserved = ";" | "/" | "?" | ":" | "@" | "&" | "=" | "+" | "$" | "," */
+
+static const char uri_chars[128] = {
+/*                +2      +4      +6      +8     +10     +12     +14     */
+/*   0 */ CO, CO, CO, CO, CO, CO, CO, CO, CO, CO, CO, CO, CO, CO, CO, CO,
+/*  16 */ CO, CO, CO, CO, CO, CO, CO, CO, CO, CO, CO, CO, CO, CO, CO, CO,
+/*  32 */ SP, MA, DE, DE, RE, DE, RE, MA, MA, MA, MA, RE, RE, MA, MA, RE,
+/*  48 */ AN, AN, AN, AN, AN, AN, AN, AN, AN, AN, RE, RE, DE, RE, DE, RE,
+/*  64 */ RE, AN, AN, AN, AN, AN, AN, AN, AN, AN, AN, AN, AN, AN, AN, AN,
+/*  80 */ AN, AN, AN, AN, AN, AN, AN, AN, AN, AN, AN, UW, UW, UW, UW, MA,
+/*  96 */ UW, AN, AN, AN, AN, AN, AN, AN, AN, AN, AN, AN, AN, AN, AN, AN,
+/* 112 */ AN, AN, AN, AN, AN, AN, AN, AN, AN, AN, AN, UW, UW, UW, MA, CO 
+};
+
+#define ESCAPE(ch) (((const signed char)(ch) < 0 || \
+		uri_chars[(unsigned int)(ch)] == 0))
+
+char *oldneon_ne_path_escape(const char *abs_path) 
+{
+    const char *pnt;
+    char *ret, *retpos;
+    int count = 0;
+    for (pnt = abs_path; *pnt != '\0'; pnt++) {
+	if (ESCAPE(*pnt)) {
+	    count++;
+	}
+    }
+    if (count == 0) {
+	return ne_strdup(abs_path);
+    }
+    /* An escaped character is "%xx", i.e., two MORE
+     * characters than the original string */
+    retpos = ret = ne_malloc(strlen(abs_path) + 2*count + 1);
+    for (pnt = abs_path; *pnt != '\0'; pnt++) {
+	if (ESCAPE(*pnt)) {
+	    /* Escape it - %<hex><hex> */
+	    sprintf(retpos, "%%%02x", (unsigned char) *pnt);
+	    retpos += 3;
+	} else {
+	    /* It's cool */
+	    *retpos++ = *pnt;
+	}
+    }
+    *retpos = '\0';
+    return ret;
+}
+
 /**
  * \brief escape a location
  *
@@ -528,7 +588,7 @@
 t_uchar *
 escape_location (t_uchar const *location)
 {
-    return ne_path_escape(location);
+    return oldneon_ne_path_escape(location);
 }
 
 /**
