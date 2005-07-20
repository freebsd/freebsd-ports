--- src/termview.cpp.orig	Tue Jul 19 19:37:38 2005
+++ src/termview.cpp	Wed Jul 20 13:27:05 2005
@@ -728,7 +728,7 @@
 		m_s_ANSIColorStr = m_pTermData->GetSelectedTextWithColor(trim);
 	else
 	{
-		m_s_ANSIColorStr.clear();
+		m_s_ANSIColorStr = "";
 		string text = m_pTermData->GetSelectedText(trim);
 
 		gsize wl = 0;
