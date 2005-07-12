--- mrundlg.c.orig	Mon Jul 11 12:15:16 2005
+++ mrundlg.c	Tue Jul 12 14:50:45 2005
@@ -250,8 +250,8 @@
 
 void txtCommand_Change (Widget w, XtPointer client_data, XmAnyCallbackStruct *call)
 {
-	if (szCommand != NULL) XtFree(szCommand);
 	Arg args; String szValue;
+	if (szCommand != NULL) XtFree(szCommand);
 	XtSetArg(args, XmNvalue, &szValue);
 	XtGetValues(w, &args, 1);
 	szCommand = szValue;
