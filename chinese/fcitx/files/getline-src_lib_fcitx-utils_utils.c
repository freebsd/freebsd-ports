--- ./src/lib/fcitx-utils/utils.c.orig	2011-10-02 05:43:11.000000000 -0500
+++ ./src/lib/fcitx-utils/utils.c	2011-11-09 21:15:42.497306506 -0600
@@ -249,4 +249,21 @@ char* fcitx_get_process_name()
 #endif
 }
 
+ssize_t getline(char ** p, size_t * cap, FILE * fp) {
+	ssize_t l;
+	if (!*cap && (*p = malloc(128))) *cap = 128;
+	else if (!*p) return -1;
+	fgets(*p, *cap, fp);
+	l = strlen(*p);
+	while (!feof(fp) && (*p)[l - 1] != '\n') {
+		if (!(*p = realloc(*p, *cap *= 2))) {
+			*cap = 0;
+			return -1;
+		}
+		fgets(*p + l, *cap / 2, fp);
+		l += strlen(*p + l);
+	}
+	return feof(fp) ? -1 : l;
+}
+
 // kate: indent-mode cstyle; space-indent on; indent-width 0;
