--- ../desktop/source/app/app.cxx.orig	Sun Mar 30 22:26:15 2003
+++ ../desktop/source/app/app.cxx	Sun Mar 30 22:27:02 2003
@@ -587,7 +587,8 @@
     ::comphelper::setProcessServiceFactory( NULL );
 
 	// clear lockfile
-	m_pLockfile->clean();
+	if (m_pLockfile != NULL)
+		m_pLockfile->clean();
 
     if( !Application::IsRemoteServer() )
 	{
@@ -621,7 +622,8 @@
 		a <<= (sal_Bool)sal_False;
 		xPropertySet->setPropertyValue( OUSTRING(RTL_CONSTASCII_USTRINGPARAM( SUSPEND_QUICKSTARTVETO )), a );
 	} else {
-        m_pLockfile->clean();
+		if (m_pLockfile != NULL)
+			m_pLockfile->clean();
 	}
 
     return bExit;
