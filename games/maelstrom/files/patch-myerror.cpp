--- ./myerror.cpp.orig	1998-07-14 03:50:17.000000000 +0200
+++ ./myerror.cpp	2013-12-28 11:39:16.000000000 +0100
@@ -16,7 +16,7 @@
 	va_list ap;
 
 	va_start(ap, fmt);
-	vsprintf(mesg, fmt, ap);
+	vsnprintf(mesg, sizeof(mesg), fmt, ap);
 	fputs(mesg, stderr);
 	va_end(ap);
 }
@@ -27,7 +27,7 @@
 	va_list ap;
 
 	va_start(ap, fmt);
-	vsprintf(mesg, fmt, ap);
+	vsnprintf(mesg, sizeof(mesg), fmt, ap);
 	fputs(mesg, stdout);
 	va_end(ap);
 }
@@ -37,7 +37,7 @@
 	char buffer[BUFSIZ];
 
 	if ( *msg ) {
-		sprintf(buffer, "%s: %s\n", msg, strerror(errno));
+		snprintf(buffer, sizeof(buffer), "%s: %s\n", msg, strerror(errno));
 		error(buffer);
 	} else
 		error((char *)strerror(errno));
