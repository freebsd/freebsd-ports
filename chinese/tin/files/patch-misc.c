--- src/misc.c.orig	Wed Jan  8 22:09:21 2003
+++ src/misc.c	Wed Jan  8 22:13:29 2003
@@ -308,7 +308,7 @@
 	 */
 
 	while (fgets(buf, (int) sizeof(buf), fp_ip) != NULL) {
-		if (!(tinrc.quote_style & QUOTE_SIGS) && !strcmp(buf, SIGDASHES) && !raw_data)
+		if (!(tinrc.quote_style & QUOTE_SIGS) && (!strcmp(buf, SIGDASHES) || !strcmp(buf, "--\n")) && !raw_data)
 			break;
 		if (strstr(prefix, "%s")) { /* initials wanted */
 			if (buf[0] != '\n') { /* line is not empty */
@@ -1064,7 +1064,9 @@
 		return (isprint(c) || (c >= 0xa0 && c <= 0xff));
 	else if (!strncasecmp(txt_mime_charsets[tinrc.mm_network_charset], "ISO-2022", 8))
 		return (isprint(c) || (c == 0x1b));
-	else if (!strncasecmp(txt_mime_charsets[tinrc.mm_network_charset], "EUC-", 4) || !strncasecmp(txt_mime_charsets[tinrc.mm_network_charset], "Big5", 4))
+	else if (!strncasecmp(txt_mime_charsets[tinrc.mm_network_charset], "Big5", 4))
+		return (isprint(c) || (c >= 0x40 && c <= 0xfe && c != 0x7f));
+	else if (!strncasecmp(txt_mime_charsets[tinrc.mm_network_charset], "EUC-", 4))
 		return 1;
 	else /* KOI8-* and UTF-8 */
 		return (isprint(c) || (c >= 0x80 && c <= 0xff));
