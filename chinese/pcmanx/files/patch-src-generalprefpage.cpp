--- src/generalprefpage.cpp.orig	Tue Oct 11 02:57:13 2005
+++ src/generalprefpage.cpp	Tue Oct 11 02:56:43 2005
@@ -64,7 +64,7 @@
 	gtk_widget_show (m_AAFont);
 	gtk_box_pack_start (GTK_BOX (m_Widget), m_AAFont, FALSE, FALSE, 0);
 
-	m_pWgetFiles = gtk_check_button_new_with_mnemonic (_("Use \"wget\" to download files."));
+	m_pWgetFiles = gtk_check_button_new_with_mnemonic (_("Use \"fetch\" to download files."));
 	gtk_widget_show (m_pWgetFiles);
 	gtk_box_pack_start (GTK_BOX (m_Widget), m_pWgetFiles, FALSE, FALSE, 0);
 
