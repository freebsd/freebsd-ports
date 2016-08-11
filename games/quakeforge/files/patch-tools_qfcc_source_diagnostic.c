--- tools/qfcc/source/diagnostic.c.orig	2013-01-23 03:10:55 UTC
+++ tools/qfcc/source/diagnostic.c
@@ -103,9 +103,7 @@ debug (expr_t *e, const char *fmt, ...)
 		return;
 
 	va_start (args, fmt);
-	if (options.notices.promote) {
-		_warning (e, fmt, args);
-	} else {
+	{
 		string_t    file = pr.source_file;
 		int         line = pr.source_line;
 
