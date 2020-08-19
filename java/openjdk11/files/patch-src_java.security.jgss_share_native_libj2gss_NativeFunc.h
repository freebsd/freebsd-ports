--- src/java.security.jgss/share/native/libj2gss/NativeFunc.h.orig	2020-07-15 18:00:08 UTC
+++ src/java.security.jgss/share/native/libj2gss/NativeFunc.h
@@ -277,6 +277,6 @@ typedef struct GSS_FUNCTION_TABLE {
 typedef GSS_FUNCTION_TABLE *GSS_FUNCTION_TABLE_PTR;
 
 /* global GSS function table */
-GSS_FUNCTION_TABLE_PTR ftab;
+extern GSS_FUNCTION_TABLE_PTR ftab;
 
 #endif
