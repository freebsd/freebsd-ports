--- jdk/src/solaris/native/sun/security/jgss/wrapper/NativeFunc.h.orig	2020-10-13 23:03:46.002701000 -0700
+++ jdk/src/solaris/native/sun/security/jgss/wrapper/NativeFunc.h	2020-10-13 23:04:24.830082000 -0700
@@ -265,6 +265,6 @@
 typedef GSS_FUNCTION_TABLE *GSS_FUNCTION_TABLE_PTR;
 
 /* global GSS function table */
-GSS_FUNCTION_TABLE_PTR ftab;
+extern GSS_FUNCTION_TABLE_PTR ftab;
 
 #endif
