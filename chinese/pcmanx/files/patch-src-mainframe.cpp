--- src/mainframe.cpp.orig	2016-02-16 12:31:52 UTC
+++ src/mainframe.cpp
@@ -187,7 +187,7 @@ CMainFrame::CMainFrame()
 	LoadIcons();
 
 
-	gtk_window_set_title (GTK_WINDOW (m_Widget), "PCManX "VERSION );
+	gtk_window_set_title (GTK_WINDOW (m_Widget), "PCManX " VERSION );
 
 	m_pNotebook = new CNotebook();
 	gtk_notebook_set_scrollable(GTK_NOTEBOOK(m_pNotebook->m_Widget), TRUE);
@@ -285,9 +285,9 @@ CTelnetCon* CMainFrame::NewCon(string ti
 		url = url.substr(first, last - first + 1);
 
 	/* Remove telnet:// from url */
-	first = url.find_first_not_of("telnet://");
-	if (first != string::npos)
-		url.erase(0, first);
+	const string telnetPrefix = "telnet://";
+	if(url.substr(0, telnetPrefix.size()) == telnetPrefix)
+		url.erase(0, telnetPrefix.size());
 
 	if ( site == NULL )
 		site = &AppConfig.m_DefaultSite;
@@ -1677,7 +1677,7 @@ void CMainFrame::SetCurView(CTelnetView*
 	m_pView = view;
 	if( !m_pView || !m_pView->GetCon() )
 	{
-		gtk_window_set_title (GTK_WINDOW (m_Widget), "PCManX "VERSION );
+		gtk_window_set_title (GTK_WINDOW (m_Widget), "PCManX " VERSION );
 		gtk_entry_set_text( GTK_ENTRY(m_URLEntry), "");
 		return;
 	}
@@ -1690,7 +1690,7 @@ void CMainFrame::SetCurView(CTelnetView*
 	if( ! con->IsClosed() )
 		m_pNotebook->SetPageTitle( m_pView, title );
 
-	title += " - PCManX "VERSION;
+	title += " - PCManX " VERSION;
 	gtk_window_set_title (GTK_WINDOW (m_Widget), title.c_str() );
 
 	char time_str[100];
