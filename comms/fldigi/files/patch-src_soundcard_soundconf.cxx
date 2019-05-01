--- src/soundcard/soundconf.cxx.orig	2019-03-18 15:12:35 UTC
+++ src/soundcard/soundconf.cxx
@@ -53,6 +53,11 @@ double std_sample_rates[] = { 8000.0, 9600.0, 11025.0,
 static void init_oss(void)
 {
 #if USE_OSS
+#ifdef __FreeBSD__
+	char *last = NULL;
+	char *curr = NULL;
+	char *p;
+#endif
 	glob_t gbuf;
 	glob("/dev/dsp*", 0, NULL, &gbuf);
 	if (gbuf.gl_pathc == 0) {
@@ -61,8 +66,33 @@ static void init_oss(void)
 		menuOSSDev->deactivate();
 		return;
 	}
-	for (size_t i = 0; i < gbuf.gl_pathc; i++)
+	for (size_t i = 0; i < gbuf.gl_pathc; i++) {
+#ifdef __FreeBSD__
+		if (curr)
+			free(curr);
+		curr = strdup(gbuf.gl_pathv[i]);
+		p = strrchr(curr, '.');
+		if (p)
+			*p = '\0';
+		if (last != NULL) {
+			if (strcmp(last, curr) == 0)
+				continue;
+		}
+		menuOSSDev->add(curr);
+		if (last)
+			free(last);
+		last = curr;
+		curr = NULL;
+#else
 		menuOSSDev->add(gbuf.gl_pathv[i]);
+#endif
+	}
+#ifdef __FreeBSD__
+	if (last)
+		free(last);
+	if (curr)
+		free(curr);
+#endif
 	if (progdefaults.OSSdevice.length() == 0 && gbuf.gl_pathc)
 		progdefaults.OSSdevice = gbuf.gl_pathv[0];
 	menuOSSDev->value(progdefaults.OSSdevice.c_str());
