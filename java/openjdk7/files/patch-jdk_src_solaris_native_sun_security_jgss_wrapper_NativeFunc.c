--- jdk/src/solaris/native/sun/security/jgss/wrapper/NativeFunc.c.orig	2020-10-13 23:04:42.602966000 -0700
+++ jdk/src/solaris/native/sun/security/jgss/wrapper/NativeFunc.c	2020-10-13 23:05:10.165713000 -0700
@@ -28,6 +28,9 @@
 #include <dlfcn.h>
 #include "NativeFunc.h"
 
+/* global GSS function table */
+GSS_FUNCTION_TABLE_PTR ftab;
+
 /* standard GSS method names (ordering is from mapfile) */
 static const char RELEASE_NAME[]                = "gss_release_name";
 static const char IMPORT_NAME[]                 = "gss_import_name";
