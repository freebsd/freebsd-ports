--- midimountain/mvcSongProperties.cpp.orig	Tue Jul 22 04:23:32 2003
+++ midimountain/mvcSongProperties.cpp	Tue Jul 22 04:25:22 2003
@@ -42,7 +42,8 @@
 //=============================================================================
 void TMvcSongProperties::SetData( void )
 {
-	int* tmpInt = new int = 0;
+	int* tmpInt = new int;
+	*tmpInt = 0;
 
 	gtk_editable_insert_text( GTK_EDITABLE( FindWidget( "txtName" )),
 		fSequence->GetSequenceName(),
@@ -111,4 +112,4 @@
 void CancelClickedSongProp( GtkButton *button, gpointer user_data )
 {
 	gtk_widget_hide( ((TMvcSongProperties*)user_data)->GetWidget() );
-}
\ No newline at end of file
+}
