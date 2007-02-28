--- include/dprintf.h.orig	Fri Sep  8 06:03:14 2006
+++ include/dprintf.h	Mon Feb 19 16:00:43 2007
@@ -40,13 +40,9 @@
 	va_list va;
 
 	va_start(va, fmt);
-	n = vsprintf(NULL, fmt, va);
-	if(n > MAXLEN)
+	n = vasprintf(&buffer, fmt, va);
+	if(-1 == n)
 		std_err(NONE, "dprintf() failed: string is too long");
-	if((buffer = (char *)malloc((n+1) * sizeof(char))) == NULL)
-		std_err(PERR, "malloc() failed");
-	(void)vsnprintf(buffer, n+1, fmt, va);
-	*(buffer+n) = '\0';
 	va_end(va);
 
 	if(write(s, buffer, n) == -1)
