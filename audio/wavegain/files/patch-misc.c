--- misc.c.orig	2006-06-04 21:47:38 UTC
+++ misc.c
@@ -39,8 +39,7 @@ void file_error(const char* message, ...)
 	vfprintf(stderr, message, args);
 	va_end(args);
 
-	fprintf(stderr, strerror(err_num));
-	fprintf(stderr, "\n");
+	fprintf(stderr, "%s\n", strerror(err_num));
 }
 
 
