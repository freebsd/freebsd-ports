--- extflat/EFint.h.orig	Tue Dec  9 16:34:04 2003
+++ extflat/EFint.h	Tue Dec  9 16:33:35 2003
@@ -21,7 +21,7 @@
 
 #ifndef	_MAGIC
 int err0 = Need_to_include_misc/magic_header;
-#endif	_MAGIC
+#endif
 
 
 /*
@@ -306,3 +306,4 @@
 extern Void efBuildConnect();
 extern Void efBuildResistor();
 extern Void efBuildCap();
+extern Void efReadError(char *fmt, ...);
