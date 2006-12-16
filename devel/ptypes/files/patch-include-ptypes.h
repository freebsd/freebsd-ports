--- include/ptypes.h.orig	Sat Dec 16 19:35:24 2006
+++ include/ptypes.h	Sat Dec 16 19:42:49 2006
@@ -42,7 +42,7 @@
     { return (T*)pexchange((void**)target, (void*)value); }
 
 
-#if (__GNUC__ == 3) && (__GNUC_MINOR__ >= 3)
+#if (__GNUC__ == 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 3))
 #  define VARIANT_TYPECAST_HACK
 #endif
 
@@ -71,6 +71,7 @@
 
 ptpublic extern char* emptystr;
 
+class variant;
 
 class ptpublic string 
 {
@@ -871,6 +872,8 @@
     VAR_COMPOUND = VAR_STRING
 };
 
+
+class _varray;
 
 class ptpublic variant
 {
