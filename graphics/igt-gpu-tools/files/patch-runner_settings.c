--- runner/settings.c.orig	2022-08-31 20:00:01 UTC
+++ runner/settings.c
@@ -872,6 +872,36 @@ bool serialize_settings(struct settings *settings)
 #undef SERIALIZE_LINE
 }
 
+#ifdef __FreeBSD__
+static inline int
+settings_fscanf(FILE *stream, char **name, char **val)
+{
+	char c, **buf = name;
+	int i, buflen, rewind = 0;
+
+	/* get buffer size for name AND value */
+	for (i = 0; i < 2; ++i, buf = val) {
+		for (buflen = 0;
+		    (c = fgetc(stream)) != ':' && c != '\n' && c != EOF;
+		    ++buflen)
+			;
+
+		/* add 1 to make room for '\0' */
+		*buf = malloc(buflen + 1);
+
+		/* add 1 to include ':' or '\n' */
+		rewind += buflen + 1;
+	}
+
+	/* rewind to start of new line for fscanf */
+	i = fseek(stream, -rewind, SEEK_CUR);
+	if (i < 0)
+		return (i);
+
+	return (fscanf(stream, "%s : %[^\n]\n", *name, *val));
+}
+#endif
+
 bool read_settings_from_file(struct settings *settings, FILE *f)
 {
 #define PARSE_LINE(s, name, val, field, write) \
@@ -887,7 +917,11 @@ bool read_settings_from_file(struct settings *settings
 
 	settings->dmesg_warn_level = -1;
 
+#ifdef __linux__
 	while (fscanf(f, "%ms : %m[^\n]", &name, &val) == 2) {
+#elif defined(__FreeBSD__)
+	while (settings_fscanf(f, &name, &val) == 2) {
+#endif
 		int numval = atoi(val);
 		PARSE_LINE(settings, name, val, abort_mask, numval);
 		PARSE_LINE(settings, name, val, disk_usage_limit, strtoul(val, NULL, 10));
