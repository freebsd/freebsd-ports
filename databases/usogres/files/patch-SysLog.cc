--- src/SysLog.cc.orig	Sat Sep  6 23:03:07 2003
+++ src/SysLog.cc	Sat Sep  6 23:07:08 2003
@@ -57,7 +57,11 @@
 
 	char* pbuf = new char[strlen(format)*3];
 	::vsprintf(pbuf, format, ap);
+#if defined(NDEBUG)
+	if (lvl <= LOG_ERR) ::syslog(lvl, pbuf);
+#else
 	::syslog(lvl, pbuf);
+#endif
 	delete [] pbuf;
 
 	va_end(ap);
