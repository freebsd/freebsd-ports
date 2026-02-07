--- Light.h.orig	2016-09-06 07:52:21 UTC
+++ Light.h
@@ -957,7 +957,9 @@ void DefineAxis(double *Min, double *Max, double *Inc)
 /*                                                                        */
 /**************************************************************************/
 
+#if 0
 extern char * program_invocation_name;
+#endif
 
 /* -----------   Error Messages ----------------------------------------  */
 
