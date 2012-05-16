--- libs/core/ddmanager/ddmanager.cpp.orig	2012-02-20 18:31:11.000000000 +0300
+++ libs/core/ddmanager/ddmanager.cpp	2012-02-20 18:31:27.000000000 +0300
@@ -349,7 +349,7 @@
 		}
 		
 		// Load the dynamic object and locate the relevant symbols.
-		CqString strDriverPathAndFile = displayPath.file_string();
+		CqString strDriverPathAndFile = displayPath.string();
 		m_DriverHandle = dspyPlugin.SimpleDLOpen( &strDriverPathAndFile );
 		if ( m_DriverHandle != NULL )
 		{
