--- sanity.hh.orig	Fri Dec 31 03:16:54 2004
+++ sanity.hh	Wed Jan 26 22:20:17 2005
@@ -64,7 +64,12 @@
 extern sanity global_sanity;
 
 // F is for when you want to build a boost formatter
+#ifdef ENABLE_NLS
 #define F(str) boost::format(gettext(str))
+#else
+#define F(str) boost::format((str))
+#endif
+
 
 // L is for logging, you can log all you want
 #define L(fmt) global_sanity.log(fmt, __FILE__, __LINE__)
