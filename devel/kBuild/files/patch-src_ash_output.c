--- src/ash/output.c.orig	2012-07-17 22:30:18 UTC
+++ src/ash/output.c
@@ -230,6 +230,7 @@ out1fmt(const char *fmt, ...)
 	va_end(ap);
 }
 
+#if 0
 void
 dprintf(const char *fmt, ...)
 {
@@ -240,6 +241,7 @@ dprintf(const char *fmt, ...)
 	va_end(ap);
 	flushout(out2);
 }
+#endif
 
 void
 fmtstr(char *outbuf, size_t length, const char *fmt, ...)
