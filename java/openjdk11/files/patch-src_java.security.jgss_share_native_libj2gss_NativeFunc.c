--- src/java.security.jgss/share/native/libj2gss/NativeFunc.c.orig	2020-07-15 18:00:08 UTC
+++ src/java.security.jgss/share/native/libj2gss/NativeFunc.c
@@ -27,6 +27,9 @@
 #include <stdlib.h>
 #include "NativeFunc.h"
 
+/* global GSS function table */
+GSS_FUNCTION_TABLE_PTR ftab;
+
 /* standard GSS method names (ordering is from mapfile) */
 static const char RELEASE_NAME[]                = "gss_release_name";
 static const char IMPORT_NAME[]                 = "gss_import_name";
