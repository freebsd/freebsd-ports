--- src/lock.cc.orig	Wed Aug 20 19:50:03 2003
+++ src/lock.cc	Wed Aug 20 19:50:17 2003
@@ -115,7 +115,7 @@
 
 	if (oflag & O_CREAT) {
 		va_start(ap, oflag);
-		mode = va_arg(ap, mode_t);
+		mode = (int)va_arg(ap, int);
 		value = va_arg(ap, unsigned int);
 		va_end(ap);
 		if (mkfifo(path, mode) < 0) {
