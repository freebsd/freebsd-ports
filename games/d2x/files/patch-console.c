--- main/console.c.orig	Fri Jun  6 23:59:49 2003
+++ main/console.c	Tue Apr  6 14:45:18 2004
@@ -70,7 +70,7 @@
 	va_list arglist;
 	char buffer[2048];
 
-	if (priority <= ((int)con_threshold.value))
+	if (priority <= ((int)con_threshold.value) && fmt)
 	{
 		va_start (arglist, fmt);
 		vsprintf (buffer,  fmt, arglist);
