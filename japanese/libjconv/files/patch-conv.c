--- conv.c.orig	Sat Aug  5 05:52:38 2000
+++ conv.c	Fri Jan 12 02:31:33 2001
@@ -130,11 +130,19 @@
 	*dest_r = NULL;
 	*dest_len_r = 0;
 	*actual_codeset_r = num_src_codesets;
+
+	if (strcasecmp(dest_codeset, "SJIS") == 0)
+		dest_codeset = "Shift_JIS";
 	
 	for (i = 0; i < num_src_codesets; i++) {
 		iconv_t cd;
-		DEBUG_DO(printf("jconv_alloc_conv: try %s\n", src_codesets[i]));
-		cd = iconv_open(dest_codeset, src_codesets[i]);
+		const char *src_codeset = src_codesets[i];
+
+		if (strcasecmp(src_codeset, "SJIS") == 0)
+			src_codeset = "Shift_JIS";
+
+		DEBUG_DO(printf("jconv_alloc_conv: try %s\n", src_codeset));
+		cd = iconv_open(dest_codeset, src_codeset);
 		if (cd == (iconv_t)-1) {
 			/* EMFILE, ENFILE, ENOMEM, or EINVAL */
 			error_code = errno;
