--- src/af/xap/unix/xap_UnixFontManager.cpp.orig	Sat Feb 22 01:00:28 2003
+++ src/af/xap/unix/xap_UnixFontManager.cpp	Sat Feb 22 01:00:57 2003
@@ -808,30 +808,30 @@
 		switch (f)
 		{
 		case GR_Font::FF_Roman:
-			m_f[f].setFont(searchFont("Times-12"));
+			m_f[f].setFont(searchFont("Times 12"));
 			break;
 
 		case GR_Font::FF_Swiss:
-			m_f[f].setFont(searchFont("Helvetica-12"));
+			m_f[f].setFont(searchFont("Helvetica 12"));
 			break;
 
 		case GR_Font::FF_Modern:
-			m_f[f].setFont(searchFont("Courier-12"));
+			m_f[f].setFont(searchFont("Courier 12"));
 			break;
 
 		case GR_Font::FF_Script:
-			m_f[f].setFont(searchFont("Cursive-12"));
+			m_f[f].setFont(searchFont("Cursive 12"));
 			break;
 
 		case GR_Font::FF_Decorative:
-			m_f[f].setFont(searchFont("Old English-12"));
+			m_f[f].setFont(searchFont("Old English 12"));
 			break;
 
 		// ugh!?  BiDi is not a font family, what is it doing here?
 		// And what's that "Technical" thing?
 		case GR_Font::FF_Technical:
 		case GR_Font::FF_BiDi:
-			m_f[f].setFont(searchFont("Arial-12"));
+			m_f[f].setFont(searchFont("Arial 12"));
 			break;
 			
 		default:
