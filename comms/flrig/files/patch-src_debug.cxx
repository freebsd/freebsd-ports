--- src/debug.cxx.orig	2013-08-29 02:59:21.000000000 -0700
+++ src/debug.cxx	2014-04-11 03:02:01.000000000 -0700
@@ -126,7 +126,7 @@
 
 	vsnprintf(sztemp, sizeof(sztemp), fmt, args);
 	estr.append(sztemp);
-	vfprintf(wfile, fmt, args);
+	fputs(sztemp, wfile);
 
 	va_end(args);
 
@@ -149,16 +149,14 @@
 
 	vsnprintf(sztemp, sizeof(sztemp), fmt, args);
 	estr.append(sztemp);
-	vfprintf(wfile, fmt, args);
+	fputs(sztemp, wfile);
 	va_end(args);
 
 	fflush(wfile);
 
 	if (tty) {
 		if (level <= DEBUG_LEVEL && level >= QUIET_LEVEL) {
-			va_start(args, format);
-			vfprintf(stderr, fmt, args);
-			va_end(args);
+			fputs(sztemp, stderr);
 		}
 	}
 
