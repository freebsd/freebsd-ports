--- Light.h.orig	2014-09-25 09:25:17 UTC
+++ Light.h
@@ -935,7 +935,9 @@ void DefineAxis(double *Min, double *Max
 /*                                                                        */
 /**************************************************************************/
 
+#if 0
 extern char * program_invocation_name;
+#endif
 
 /* -----------   Error Messages ----------------------------------------  */
 
