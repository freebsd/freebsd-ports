
$FreeBSD$

--- seaview.cxx.orig	Thu May 22 01:45:14 2003
+++ seaview.cxx	Thu May 22 01:37:25 2003
@@ -164,6 +164,8 @@
 	"seaview.hlp", 
 #elif defined(__APPLE__)
 	NULL,
+#elif defined(DEFAULT_HELPFILE)
+	__XSTRING(DEFAULT_HELPFILE),
 #else
 	"seaview.help", 
 #endif
