--- regutil/regutil.c.orig	2014-10-19 04:07:12 UTC
+++ regutil/regutil.c
@@ -183,6 +183,8 @@ extern void *getRexxUtilFunctionAddress(
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
