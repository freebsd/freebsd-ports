--- seaview.cxx.orig	Mon Nov 17 14:16:39 2003
+++ seaview.cxx	Mon Nov 17 14:17:13 2003
@@ -164,6 +164,8 @@
 	"seaview.hlp", 
 #elif defined(__APPLE__)
 	NULL,
+#elif defined(DEFAULT_HELPFILE)
+       __XSTRING(DEFAULT_HELPFILE),
 #else
 	"seaview.help", 
 #endif
