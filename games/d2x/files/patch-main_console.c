--- main/console.c.orig	2003-06-06 21:59:49 UTC
+++ main/console.c
@@ -70,7 +70,7 @@ void con_printf(int priority, char *fmt,
 	va_list arglist;
 	char buffer[2048];
 
-	if (priority <= ((int)con_threshold.value))
+	if (priority <= ((int)con_threshold.value) && fmt)
 	{
 		va_start (arglist, fmt);
 		vsprintf (buffer,  fmt, arglist);
