--- appFrame/appFileChooserMotif.c	Fri Apr  4 06:46:48 2003
+++ /home/bsd/patches/TedFixes/appFileChooserMotif.c	Sun Jun  1 20:19:07 2003
@@ -549,6 +549,7 @@
 static int appMakeFileChooser( AppChooserInformation **	pAci,
 				Widget				relative,
 				EditApplication *		ea,
+				int				withFilter,
 				const char *			defaultFilter,
 				Widget				option )
     {
@@ -624,15 +625,21 @@
 			NULL );
 
     /*  Not necessary
-    XtAddCallback( text, XmNactivateCallback,
+    if  ( withFilter )
+	{
+	XtAddCallback( text, XmNactivateCallback,
 				    appFileFilterActivated, (void *)aci );
+	}
     */
 
     filterButton= XmFileSelectionBoxGetChild( aci->aciDialog.adDialog,
 						    XmDIALOG_APPLY_BUTTON );
 
-    XtAddCallback( filterButton, XmNactivateCallback,
+    if  ( withFilter )
+	{
+	XtAddCallback( filterButton, XmNactivateCallback,
 				    appFileFilterActivated, (void *)aci );
+	}
 
     text= XmFileSelectionBoxGetChild( aci->aciDialog.adDialog, XmDIALOG_TEXT );
     XtVaSetValues( text,
@@ -705,14 +712,15 @@
 			EditApplication *	ea )
     {
     AppChooserInformation *	aci= (AppChooserInformation *)0;
+    const int			withFilter= extensionCount > 0;
 
-    if  ( appMakeFileChooser( &aci, relative, ea, defaultFilter, option ) )
+    if  ( appMakeFileChooser( &aci, relative, ea, withFilter, defaultFilter, option ) )
 	{ LDEB(1); return;	}
 
     XtAddCallback( aci->aciDialog.adDialog,
 			XmNokCallback, appOpenChooserOk, (XtPointer)aci );
 
-    if  ( extensionCount > 0 )
+    if  ( withFilter )
 	{
 	appFileMakeFilter( aci );
 
@@ -727,7 +735,7 @@
     aci->aciOpenDocument= openDocument;
     aci->aciFilename= (char *)0;
 
-    if  ( extensionCount > 0 )
+    if  ( withFilter )
 	{
 	WidgetList		children;
 	Cardinal		childCount= 0;
@@ -920,16 +928,17 @@
 				char **			pFilename )
     {
     AppChooserInformation *	aci= (AppChooserInformation *)0;
+    const int			withFilter= ea->eaFileExtensionCount > 0;
     int				response;
 
-    if  ( appMakeFileChooser( &aci, relative, ea,
+    if  ( appMakeFileChooser( &aci, relative, ea, withFilter,
 					    ea->eaDefaultFileFilter, option ) )
 	{ return ACIrespFAILURE;	}
 
     XtAddCallback( aci->aciDialog.adDialog,
 			    XmNokCallback, appSaveOkPushed, (XtPointer)aci );
 
-    if  ( ea->eaFileExtensionCount > 0 )
+    if  ( withFilter )
 	{
 	appFileMakeFilter( aci );
 
@@ -977,9 +986,10 @@
 					char **			pFilename )
     {
     AppChooserInformation *	aci= (AppChooserInformation *)0;
+    const int			withFilter= 0;
     int				response;
 
-    if  ( appMakeFileChooser( &aci, panel, ea, "*.ps", option ) )
+    if  ( appMakeFileChooser( &aci, panel, ea, withFilter, "*.ps", option ) )
 	{ LDEB(1); return ACIrespFAILURE;	}
 
     XtAddCallback( aci->aciDialog.adDialog,
