--- sanity.hh.orig	Wed Jan  7 13:11:48 2004
+++ sanity.hh	Sun Mar 21 22:49:59 2004
@@ -58,7 +58,11 @@
 extern sanity global_sanity;
 
 // F is for when you want to build a boost formatter
+#ifdef ENABLE_NLS
 #define F(str) boost::format(gettext(str))
+#else
+#define F(str) boost::format((str))
+#endif
 
 // L is for logging, you can log all you want
 #define L(fmt) global_sanity.log(fmt)
