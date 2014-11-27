--- src/error.c.orig	2014-11-21 17:41:49 UTC
+++ src/error.c
@@ -46,14 +46,22 @@ static char const * _error_do(int * code
 /* error_get */
 char const * error_get(void)
 {
-	return _error_do(NULL, NULL, NULL);
+	va_list unused;
+
+	bzero(&unused, sizeof(unused)); /* suppress uninitialized-value warnings */
+
+	return _error_do(NULL, NULL, unused);
 }
 
 
 /* error_get_code */
 char const * error_get_code(int * code)
 {
-	return _error_do(code, NULL, NULL);
+	va_list unused;
+
+	bzero(&unused, sizeof(unused)); /* suppress uninitialized-value warnings */
+
+	return _error_do(code, NULL, unused);
 }
 
 
@@ -98,12 +106,16 @@ int error_print(char const * program)
 {
 	int code = 0;
 
+	va_list unused;
+
+	bzero(&unused, sizeof(unused)); /* suppress uninitialized-value warnings */
+
 	if(program != NULL)
 	{
 		fputs(program, stderr);
 		fputs(": ", stderr);
 	}
-	fputs(_error_do(&code, NULL, NULL), stderr);
+	fputs(_error_do(&code, NULL, unused), stderr);
 	fputc('\n', stderr);
 	return code;
 }
