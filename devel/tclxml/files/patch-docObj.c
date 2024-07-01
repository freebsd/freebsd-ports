--- docObj.c.orig	2013-03-30 17:17:07 UTC
+++ docObj.c
@@ -1852,9 +1852,13 @@ void
 }
 
 void
-TclXML_libxml2_ErrorHandler (ctx, error)
-     void *ctx; /* ignore - depends on context */
-     xmlErrorPtr error;
+TclXML_libxml2_ErrorHandler (void *ctx,
+#if LIBXML_VERSION >= 21200
+        const xmlError *error
+#else
+        xmlError *error
+#endif
+        )
 {
   ThreadSpecificData *tsdPtr = Tcl_GetThreadData(&dataKey, sizeof(ThreadSpecificData));
   Tcl_Obj *objPtr;
