--- include/xwindow.h.orig	2003-12-08 08:39:13.000000000 +0900
+++ include/xwindow.h	2014-10-17 22:46:12.000000000 +0900
@@ -78,6 +78,9 @@
 
 extern XFontStruct *WindowFontStruct(/* Widget */);
 extern Font WindowFont(/* Widget */);
+#ifdef XI18N
+extern XFontSet WindowFontSet(/* Widget */);
+#endif
 
 #define XtCWindowResource "WindowResource"
 #define XtCRows			"Rows"
