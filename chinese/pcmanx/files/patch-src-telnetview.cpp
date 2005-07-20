--- src/telnetview.cpp.orig	Wed Jul 20 07:07:54 2005
+++ src/telnetview.cpp	Wed Jul 20 13:39:22 2005
@@ -178,7 +178,7 @@
 						"utf-8", m_pTermData->m_Encoding.c_str(), "?", NULL, &wl, NULL);
 				if(purl)
 				{
-					m_s_ANSIColorStr.clear();
+					m_s_ANSIColorStr = "";
 					GtkClipboard* clipboard = gtk_clipboard_get( GDK_NONE );
 					gtk_clipboard_set_text(clipboard, purl, wl );
 					clipboard = gtk_clipboard_get(  GDK_SELECTION_PRIMARY);
