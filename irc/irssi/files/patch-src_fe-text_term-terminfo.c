--- src/fe-text/term-terminfo.c.orig	2019-08-29 13:48:46 UTC
+++ src/fe-text/term-terminfo.c
@@ -672,7 +672,11 @@ void term_stop(void)
 
 static int input_utf8(const unsigned char *buffer, int size, unichar *result)
 {
-	unichar c = g_utf8_get_char_validated((char *)buffer, size);
+	unichar c = g_utf8_get_char_validated((char *) buffer, size);
+
+	/* GLib >= 2.63 do not accept Unicode NUL anymore */
+	if (c == (unichar) -2 && *buffer == 0 && size > 0)
+		c = 0;
 
 	switch (c) {
 	case (unichar)-1:
