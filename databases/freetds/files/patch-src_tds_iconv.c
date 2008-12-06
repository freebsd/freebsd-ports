--- src/tds/iconv.c.orig	Sat Jan 13 16:27:13 2007
+++ src/tds/iconv.c	Sat Jan 13 16:29:24 2007
@@ -973,13 +973,18 @@ tds_srv_charset_changed(TDSSOCKET * tds,
 #if HAVE_ICONV_ALWAYS
 	TDSICONV *char_conv = tds->char_convs[client2server_chardata];
 
-	const char *canonic_charset = tds_canonical_charset_name(charset);
+	int canonic_charset_num = tds_canonical_charset(charset);
+	const char *canonic_charset;
+
+	if (tds->major_version >= 7 && canonic_charset_num == TDS_CHARSET_ISO_8859_1)
+		canonic_charset_num = TDS_CHARSET_CP1252;
 
 	/* ignore request to change to unknown charset */
-	if (!canonic_charset) {
+	if (canonic_charset_num < 0) {
 		tdsdump_log(TDS_DBG_FUNC, "tds_srv_charset_changed: what is charset \"%s\"?\n", charset);
 		return;
 	}
+	canonic_charset = canonic_charsets[canonic_charset_num].name;
 
 	if (strcmp(canonic_charset, char_conv->server_charset.name) == 0)
 		return;
