--- regutil/regutil.c.orig	2019-10-06 06:09:42 UTC
+++ regutil/regutil.c
@@ -183,6 +183,8 @@ extern void *getRexxUtilFunctionAddress( char *name )
 }
 #endif
 
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wincompatible-pointer-types"
 /* sysloadfuncs() */
 rxfunc(sysloadfuncs)
 {
@@ -198,6 +200,7 @@ rxfunc(sysloadfuncs)
 
     return 0;
 }
+#pragma clang diagnostic pop
 
 
 /* sysdropfuncs() */
