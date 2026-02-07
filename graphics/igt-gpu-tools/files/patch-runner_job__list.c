--- runner/job_list.c.orig	2022-08-31 20:00:01 UTC
+++ runner/job_list.c
@@ -1,7 +1,12 @@
 #include <ctype.h>
 #include <errno.h>
 #include <fcntl.h>
+#ifdef __linux__
 #include <linux/limits.h>
+#elif defined(__FreeBSD__)
+#include <sys/limits.h>
+#include <sys/wait.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -40,6 +45,31 @@ static void add_job_list_entry(struct job_list *job_li
 	entry->subtest_count = subtest_count;
 }
 
+#ifdef __FreeBSD__
+static inline int
+job_list_fscanf(FILE *stream, char *fmt, char **subtestname)
+{
+	int bufsize;
+	char c;
+
+	for (bufsize = 0;
+	    (c = fgetc(stream)) != '\n' && c != EOF;
+	    ++bufsize)
+		;
+
+	if (bufsize == 0)
+		return 0;
+
+	*subtestname = malloc(bufsize + 2);
+
+	/* no fseek() in pipes */
+	stream->_r += bufsize + 1;
+	stream->_p -= bufsize + 1;
+
+	return (fscanf(stream, "%s\n", *subtestname));
+}
+#endif
+
 static void add_subtests(struct job_list *job_list, struct settings *settings,
 			 char *binary,
 			 struct regex_list *include, struct regex_list *exclude)
@@ -72,7 +102,11 @@ static void add_subtests(struct job_list *job_list, st
 		return;
 	}
 
+#ifdef __linux__
 	while (fscanf(p, "%ms", &subtestname) == 1) {
+#elif defined(__FreeBSD__)
+	while (job_list_fscanf(p, "%s", &subtestname) == 1) {
+#endif
 		char piglitname[256];
 
 		generate_piglit_name(binary, subtestname, piglitname, sizeof(piglitname));
@@ -226,7 +260,12 @@ static bool job_list_from_test_list(struct job_list *j
 		if (settings->include_regexes.size && !matches_any(line, &settings->include_regexes))
 			continue;
 
+#ifdef __linux__
 		if (sscanf(line, "igt@%ms", &binary) == 1) {
+#elif defined(__FreeBSD__)
+		binary = malloc(strlen(line)-4);
+		if (sscanf(line, "igt@%s", binary) == 1) {
+#endif
 			if ((delim = strchr(binary, '@')) != NULL)
 				*delim++ = '\0';
 
