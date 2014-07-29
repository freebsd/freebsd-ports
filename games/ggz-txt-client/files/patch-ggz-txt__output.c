--- ggz-txt/output.c.orig	Fri Jun 25 22:32:46 2004
+++ ggz-txt/output.c	Sun Jul 18 20:29:22 2004
@@ -145,10 +145,10 @@
 	char message[1024];	/* FIXME: Make me dynamic */
 	int x;
 	char *token, *messagedup, *orig;
+	va_list ap;
 
 	if(!output_enabled) return;
 
-	va_list ap;
 	va_start(ap, fmt);
 	vsnprintf(message, sizeof(message), fmt, ap);
 	va_end(ap);
