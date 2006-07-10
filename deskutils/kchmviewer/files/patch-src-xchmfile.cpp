--- src/xchmfile.cpp.orig	Mon Jul 10 11:44:50 2006
+++ src/xchmfile.cpp	Mon Jul 10 11:45:49 2006
@@ -1278,7 +1278,7 @@
 		FIXENDIAN32(off_url);
 
 		if ( RetrieveObject ( &m_chmURLSTR, buf, off_url + 8, sizeof(buf) - 1) == 0 )
-			return false;
+			return QString::null;
 
 		buf[sizeof(buf) - 1] = '\0';
 		url = KCHMViewWindow::makeURLabsoluteIfNeeded ((const char*)buf);
