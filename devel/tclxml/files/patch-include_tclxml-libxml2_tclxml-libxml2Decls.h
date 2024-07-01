--- include/tclxml-libxml2/tclxml-libxml2Decls.h.orig	2013-03-30 17:17:07 UTC
+++ include/tclxml-libxml2/tclxml-libxml2Decls.h
@@ -55,7 +55,12 @@ EXTERN void		TclXML_libxml2_ErrorHandler _ANSI_ARGS_((
 				TclXML_libxml2_DocumentHandling keep));
 /* 10 */
 EXTERN void		TclXML_libxml2_ErrorHandler _ANSI_ARGS_((void * ctx, 
-				xmlErrorPtr error));
+#if LIBXML_VERSION >= 21200
+				const xmlError *error));
+#else
+				xmlError *error));
+#endif
+
 /* 11 */
 EXTERN void		TclXML_libxml2_ResetError _ANSI_ARGS_((
 				Tcl_Interp * interp));
@@ -93,7 +98,13 @@ typedef struct Tclxml_libxml2Stubs {
     int (*tclXML_libxml2_GetTclDocFromNode) _ANSI_ARGS_((Tcl_Interp * interp, xmlNodePtr nodePtr, TclXML_libxml2_Document ** tDocPtrPtr)); /* 7 */
     void (*tclXML_libxml2_DestroyDocument) _ANSI_ARGS_((TclXML_libxml2_Document * tDocPtr)); /* 8 */
     void (*tclXML_libxml2_DocKeep) _ANSI_ARGS_((Tcl_Obj * objPtr, TclXML_libxml2_DocumentHandling keep)); /* 9 */
-    void (*tclXML_libxml2_ErrorHandler) _ANSI_ARGS_((void * ctx, xmlErrorPtr error)); /* 10 */
+    void (*tclXML_libxml2_ErrorHandler) _ANSI_ARGS_((void * ctx,
+#if LIBXML_VERSION >= 21200
+                const xmlError * error
+#else
+                xmlError * error
+#endif
+                )); /* 10 */
     void (*tclXML_libxml2_ResetError) _ANSI_ARGS_((Tcl_Interp * interp)); /* 11 */
     Tcl_Obj * (*tclXML_libxml2_GetErrorObj) _ANSI_ARGS_((Tcl_Interp * interp)); /* 12 */
     void (*tclXML_libxml2_SetErrorNodeFunc) _ANSI_ARGS_((Tcl_Interp * interp, TclXML_ErrorNodeHandlerProc * proc)); /* 13 */
