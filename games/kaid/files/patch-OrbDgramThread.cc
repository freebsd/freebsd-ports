--- OrbDgramThread.cc	Wed Feb  9 19:28:14 2005
--- OrbDgramThread.cc	Sun Feb 27 15:01:40 2005
@@ -27,6 +27,8 @@
 	m_cParent->verbositylog(2,"THREAD","Datagram server thread started...");
     m_cConf = cConf;
 	m_cListeningSocket = NULL;
+	m_iMyPort = 0;
+	m_iSourcePort = 0;
 	m_bOrbFound = false;
 }
 
@@ -136,12 +138,13 @@
 
 IPAddress& COrbDgramThread::FindNearestOrb()
 {
+	const size_t BUFFER_SIZE = 65535;
 	m_bOrbFound=false;
 	if (!m_cListeningSocket) return m_cNearestOrb;
 	
 	unsigned int i;
 	int iBytesTransferred, iSrcPort;
-	char pcBuffer[65535];
+	char *pcBuffer = new char[BUFFER_SIZE];
 	IPAddress pcAddr;
     vector<string> vsOrbs;
     vector<string> vsSegments;
@@ -169,7 +172,7 @@
                 m_cConf->OrbPort);
         }
 
-        iBytesTransferred = m_cListeningSocket->ReceiveDatagram(pcBuffer, sizeof(pcBuffer) - 1,
+        iBytesTransferred = m_cListeningSocket->ReceiveDatagram(pcBuffer, BUFFER_SIZE - 1,
             m_cNearestOrb, iSrcPort);
 		
         pcBuffer[iBytesTransferred] = 0;
@@ -191,6 +194,7 @@
     catch (...)
     {
     }
+	delete pcBuffer;
 	
 	return m_cNearestOrb;
 }
