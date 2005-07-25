--- src/xchmfile.cpp.orig	Mon Jul 25 12:27:20 2005
+++ src/xchmfile.cpp	Mon Jul 25 12:28:16 2005
@@ -1189,7 +1189,7 @@
 		FIXENDIAN32(off_url);
 
 		if ( RetrieveObject ( &m_chmURLSTR, buf, off_url + 8, sizeof(buf) - 1) == 0 )
-			return false;
+			return QString::null;
 
 		buf[sizeof(buf) - 1] = '\0';
 		url = KCHMViewWindow::makeURLabsoluteIfNeeded ((const char*)buf);
